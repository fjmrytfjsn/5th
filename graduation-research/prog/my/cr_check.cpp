#include<bits/stdc++.h>
using namespace std;

bool is_spanning_tree(Graph t, vector<int> V, vector<vector<int>> E) {
    vector<int> V;
    for(i=0; i<n; i++) V.push_back(i);
    vector<vector<int>> E(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0, j<n; j++)
            if((j-i+n)%n==1 or (j-i+n)%n==d1 or (j-i+n)%n==d2) E[i][j]=1;
    vector<int> exist_vertex;
    for(int i=0; i<6; i++) {
        exist_vertex.assign(1,0);
        for(int u=0; u<n; u++) {
            for(int v=1, v<n; v++) {
                if(t[i].mat[u][v]) {
                    if(!E[u][v]) {
                        printf("The edge (%d, %d) of t%d does not exists in CR(%d, %d, %d).\n", u, v, i, n, d1, d2);
                        return false;
                    }
                    exist_vertex.push_back(v);
                }
            }
        }
        sort(exist_vertex.begin(), exist_vertex.end());
        if(exist_vertex=!V) {
            vector<int> diff;
            set_difference(V.begin(), V.end(), exist_vertex.begin(), exist_vertex.end(), back_inserter(diff));
            puts("The following vertices do not exist");
            for (int i: diff)
                cout << i << ' ';
            puts("");
            
        }
        return true;
    }
     
}

bool check(vector<Graph> ts) {

    is_spanning_tree(ts[i], V, E);
            
    is_independent(ts[i]);

    if(E[u][v]==-1) {
        printf("The edge (%d, %d) of t%d is already exists.\n", u, v, i);
        return false;
    }

}

int main() {

    check(ts, V, E)
}
