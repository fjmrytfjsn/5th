#include <vector>
#include <queue>
using namespace std;

bool is_spanning_tree(vector<Graph> ts, int n, int d1, int d2) {
    vector<int> V;
    for(int i=0; i<n; i++) V.push_back(i);
    vector<vector<int>> E(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if((j-i+n)%n==1 or (j-i+n)%n==d1 or (j-i+n)%n==d2) E[i][j]=E[j][i]=1;
    vector<int> existed_vertex;

    for(int i=0; i<6; i++) {
        existed_vertex.assign(1, 0);
        for(int u=0; u<n; u++) {
            for(int v=1; v<n; v++) {
                if(ts[i].mat[u][v]) {
                    if(!E[u][v]) {
                        printf("The edge (%d, %d) of t%d does not exists in CR(%d, %d, %d).\n", u, v, i, n, d1, d2);
                        return false;
                    }
                    existed_vertex.push_back(v);
                }
            }
        }
        sort(existed_vertex.begin(), existed_vertex.end());
        if(existed_vertex==V) {
            // printf("t%d is spanning tree\n", i);
            ;
        }
        else {
            vector<int> diff;
            set_difference(V.begin(), V.end(), existed_vertex.begin(), existed_vertex.end(), back_inserter(diff));
            printf("The following vertices do not exist in t%d\n", i);
            for (int j: diff)
                cout << j << ' ';
            puts("");
            return false;
        }
    }
    return true;
}

vector<vector<int>> find_path(int n, vector<vector<int>> G) {
    vector<bool> visited(n, false);
    vector<int> path;
    vector<vector<int>> path_set(n, vector<int>(0));
    queue<vector<int>> que;

    visited.assign(n, false);
    vector<int>().swap(path);
    queue<vector<int>>().swap(que);

    visited[0] = true;
    path.push_back(0);
    que.push(path);
    path_set[0] = path;
    
    while(!que.empty()) {
        path=que.front();
        for(auto next_v : G[path.back()]) {
            if(visited[next_v]) continue;
            visited[next_v] = true;
            path.push_back(next_v);
            que.push(path);
            path_set[path.back()] = path;
            path=que.front();
        }
        que.pop();
    }

    return path_set;
}

bool is_independent(vector<Graph> ts, int n, int d1, int d2) {
    vector<vector<int>> existed_edge(n, vector<int>(n, 0));
    vector<vector<int>> path(6, vector<int>(0, 0));
    for(int i=0; i<6; i++) {
        for(int u=0; u<n; u++) {
            for(int v=1; v<n; v++) {
                if(ts[i].mat[u][v]) {
                    if(existed_edge[u][v]) {
                        printf("The edge (%d, %d) of t%d is already exists.\n", u, v, i);
                        return false;
                    }
                    existed_edge[u][v]=1;
                }
            }
        }
    }

    vector<vector<int>> existed_vertex(n, vector<int>(n, 0));
    vector<vector<vector<int>>> path_set(6, vector<vector<int>>(n, vector<int>(0)));

    for(int i=0; i<6; i++) path_set[i] = find_path(n, ts[i].G);

    for(auto path: path_set) {
        for(int goal=1; goal<n; goal++) {
            for(int j=1; j<path[goal].size()-1; j++) {
                if(!existed_vertex[goal][path[goal][j]]) {
                    existed_vertex[goal][path[goal][j]] = 1;
                }
                else {
                    printf("Vertex %d overlaps on the path to vertex %d.\n", path[goal][j], goal);
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

    printf("CR(%d, %d, %d) is successed\n", n, d1, d2);

    return true;    
}

// int main() {
//     bool ok;
//     int n, d1=4, d2;
//     int n_min, n_max;
//     cout<<"nの最小値を入力してください>>"; cin>>n_min;
//     cout<<"nの最大値を入力してください>>"; cin>>n_max;

//     for(n=n_min; n<=n_max; n++) {
//         for(d2=d1+2; d2*2<n; d2++){ 
//             vector<Graph> ts = construct(n, d1, d2);
//             ok=cr_check(ts, n, d1, d2);
//         }
//     }

//     if(ok) printf("%d - %d : successed\n", n_min, n_max);
//     else printf("%d - %d : failed\n", n_min, n_max);

//     return 0;
// }
