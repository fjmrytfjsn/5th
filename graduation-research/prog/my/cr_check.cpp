#include<bits/stdc++.h>
#include"construct.cpp"
using namespace std;

bool is_spanning_tree(vector<Graph> ts, int n, int d1, int d2) {
    vector<int> V;
    for(int i=0; i<n; i++) V.push_back(i);
    vector<vector<int>> E(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if((j-i+n)%n==1 or (j-i+n)%n==d1 or (j-i+n)%n==d2) E[i][j]=E[j][i]=1;
    vector<int> exist_vertex;

    for(int i=0; i<6; i++) {
        exist_vertex.assign(1, 0);
        for(int u=0; u<n; u++) {
            for(int v=1; v<n; v++) {
                if(ts[i].mat[u][v]) {
                    if(!E[u][v]) {
                        printf("The edge (%d, %d) of t%d does not exists in CR(%d, %d, %d).\n", u, v, i, n, d1, d2);
                        return false;
                    }
                    exist_vertex.push_back(v);
                }
            }
        }
        sort(exist_vertex.begin(), exist_vertex.end());
        if(exist_vertex==V) {
            // printf("t%d is spanning tree\n", i);
            ;
        }
        else {
            vector<int> diff;
            set_difference(V.begin(), V.end(), exist_vertex.begin(), exist_vertex.end(), back_inserter(diff));
            puts("The following vertices do not exist");
            for (int i: diff)
                cout << i << ' ';
            puts("");
            return false;
        }
    }
    return true;
}

vector<int> find_path(int n, vector<vector<int>> G, int goal) {
    vector<int> path;
    vector<bool> visited(n, false);
    function<bool(int)> dfs = [&](int current_vertex) {
        if(visited[current_vertex]) return false;
        visited[current_vertex] = true;
        if(current_vertex == goal) {
            path.push_back(current_vertex);
            return true;
        }
        bool is_path_element = false;
        for(int next_vertex: G[current_vertex]) {
            if(visited[next_vertex]) continue;
            if(dfs(next_vertex)) is_path_element = true;
        }
        if(!is_path_element) return false;
        path.push_back(current_vertex);
        return true;
    };
    assert(dfs(0));
    reverse(path.begin(), path.end());
    return path;
}

bool is_independent(vector<Graph> ts, int n, int d1, int d2) {
    vector<vector<int>> exist_edge(n, vector<int>(n, 0));
    vector<vector<int>> path(6, vector<int>(0, 0));
    for(int i=0; i<6; i++) {
        for(int u=0; u<n; u++) {
            for(int v=1; v<n; v++) {
                if(ts[i].mat[u][v]) {
                    if(exist_edge[u][v]) {
                        printf("The edge (%d, %d) of t%d is already exists.\n", u, v, i);
                        return false;
                    }
                    exist_edge[u][v]=1;
                }
            }
        }
    }

    vector<int> temp;
    for(int goal=1; goal<n; goal++) {
        for(int i=0; i<6; i++) {
            path[i]=find_path(n, ts[i].G, goal);
        }
        for(int i=0; i<5; i++) {
            for(int j=1; j<6; j++) {
                temp.insert(temp.end(), path[i].begin(), path[i].end());
                temp.insert(temp.end(), path[j].begin(), path[j].end());
                int array[temp.size()];
                copy(temp.begin(), temp.end(), array);
                if(temp.size()!=sizeof(array)/4) {
                    printf("t%dとt%dにおいて頂点が重複\n", i, j);
                    return false;
                }
            }
        }
    }

    return true;
}

bool cr_check(vector<Graph> ts, int n, int d1, int d2) {
    if(is_spanning_tree(ts, n, d1, d2)) {
        // puts("trees are spanning tree");
        ;
    }
    else {
        printf("CR(%d, %d, %d) is failed\n", n, d1, d2);
        return false;
    }

    if(is_independent(ts, n, d1, d2)) {
        // puts("trees are independent");
        ;
    }
    else {
        printf("CR(%d, %d, %d) is failed\n", n, d1, d2);
        return false;
    }

    // printf("CR(%d, %d, %d) is successed\n", n, d1, d2);

    return true;    
}

int main() {
    bool ok;
    int n, d1=4, d2;
    int n_min, n_max;
    cout<<"nの最小値を入力してください>>"; cin>>n_min;
    cout<<"nの最大値を入力してください>>"; cin>>n_max;

    for(n=n_min; n<=n_max; n++) {
        for(d2=d1+2; d2*2<n; d2++){ 
            vector<Graph> ts = construct(n, d1, d2);
            ok=cr_check(ts, n, d1, d2);
        }
    }

    if(ok) printf("%d - %d : successed\n", n_min, n_max);
    else printf("%d - %d : failed\n", n_min, n_max);

    return 0;
}
