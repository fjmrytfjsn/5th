#include<vector>
#include<cstdio>
#include<functional>
using std::vector;
using std::printf;

struct DisjointSetUnion {
    int n;
    std::vector<int> data;
    DisjointSetUnion(int n): n(n), data(n, -1) {}

    int root(int x) {
        if(data[x] < 0) return x;
        return data[x] = root(data[x]);
    }
    
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(data[x] > data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
    }

    int count_components(){
        int ret = 0;
        for(int d: data) if(d < 0) ret++;
        return ret;
    }
};


struct Graph {
    int n, m;
    std::vector< std::vector<int> > edges, mat;
    DisjointSetUnion dsu;
    Graph(int n): n(n), m(0), edges(n), mat(n, std::vector<int>(n, 0)), dsu(n) {}
    
    void add_edge(int u, int v) {
        if(mat[u][v] == 1 or mat[v][u] == 1){
            fprintf(stderr, "%d-%d edge already exists\n", u, v);
            assert(false);
        }
        edges[u].push_back(v);
        edges[v].push_back(u);
        mat[u][v] = mat[v][u] = 1;
        dsu.unite(u, v);
        m++;
    }
    
    bool is_spanning_tree(bool verbose = false) {
        if(!verbose) return (m == n-1) and (dsu.count_components() == 1);
        if(m < n-1) printf("too less edges: %d\n", m);
        else if(m > n-1) printf("too much edges: %d\n", m);
        else if(dsu.count_components() != 1) printf("graph is disconnected\n");
        else return true;
        return false;
    }

    void print_matrix() {
        printf("G = (%d, %d)\n", n, m);
        for(int i = 0; i < n; i++) {
            printf("%3d: ", i);
            for(int j = 0; j < n; j++){
                if(i == j) printf("x");
                else printf("%d", mat[i][j]);
            }
            printf("\n");
        }
        return;
    }

    std::vector<int> find_path(int start, int goal) {
        std::vector<int> path;
        std::vector<bool> visited(n, false);
        std::function<bool(int)> dfs = [&](int current_vertex){
            if(visited[current_vertex]) return false;
            visited[current_vertex] = true;
            if(current_vertex == goal) {
                path.push_back(current_vertex);
                return true;
            }
            bool is_path_element = false;
            for(int next_vertex: edges[current_vertex]) {
                if(visited[next_vertex]) continue;
                if(dfs(next_vertex)) is_path_element = true;
            }
            if(!is_path_element) return false;
            path.push_back(current_vertex);
            return true;
        };
        assert(dfs(start));
        std::reverse(path.begin(), path.end());
        return path;
    }
};


bool cr_check(std::vector<Graph> ts, bool verbose = false){
    bool entire_ok = true;
    if(verbose) {
        puts("I. Spanning Tree Check");
        for(int i = 0; i < ts.size(); i++) {
            if(ts[i].is_spanning_tree()) printf("  t%d ... OK\n", i);
            else printf("  t%d ... NG\n", i);
        }
        puts("");
        puts("II. Independent Check");
    }
    for(int i = 0; i < ts.size(); i++) {
        if(!ts[i].is_spanning_tree()) entire_ok = false;
    }

    int n = ts.at(0).n;
    for(int goal = 1; goal < n; goal++) {
        if(verbose) printf("%3d - %3d path", 0, goal);
        /*
        for(int i = 0; i < ts.size(); i++) {
            printf("\n  t%d:", i);
            for(int v: ts[i].find_path(0, goal)) printf(" %d", v);
            puts("");
        }
        //*/

        bool ok = true;
        for(int i = 0; i < ts.size(); i++) {
            std::vector<int> ipass = ts[i].find_path(0, goal);
            std::set<int> ipassv(ipass.begin(), ipass.end());
            for(int j = i+1; j < ts.size(); j++) {
                std::vector<int> jpass = ts[j].find_path(0, goal);
                std::set<int> commonv, jpassv(jpass.begin(), jpass.end());
                std::set_intersection(
                    ipassv.begin(), ipassv.end(),
                    jpassv.begin(), jpassv.end(),
                    std::inserter(commonv, commonv.end())
                );
                if(commonv.size() > 2){
                    entire_ok = ok = false;
                    if(verbose){
                        printf("\nNG: t%d and t%d is not indepent\n", i, j);
                        printf("common vertex on %d - %d path:", 0, goal);
                        for(int v: commonv) printf(" %d", v); puts("");
                    }
                }
            }
        }
        if(verbose and ok) puts(" ... OK");
    }
    
    return entire_ok;
}
