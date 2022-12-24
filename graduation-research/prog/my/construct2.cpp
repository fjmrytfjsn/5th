#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> edges(0, vector<int>(0, 0));

struct Graph {
    int n;
    Graph(int n): n(n), mat(n, vector<int>(n, 0)), G(n, vector<int>(n)) {}
    list<int> ver_set;
    vector<vector<int>> mat, G;

    bool add_edge(int u, int v) {
        if(edges[u][v])
            return false;
        if(find(ver_set.begin(), ver_set.end(), v) != ver_set.end()) 
            return false;
        edges[u][v]=mat[u][v] = 1;
        G[u].push_back(v);
        ver_set.push_back(v);
        return true;
    }
};

void init(Graph &t, int n) {
    t.ver_set.clear();
    t.ver_set.push_back(0);
}

Graph construct0(int n, int d1, int d2) {
    Graph t0(n);
    
    init(t0, n);

    t0.add_edge(0, 1);

    for(int i=1; i<d1; i++) {
        t0.add_edge(i, n-d1+i);
        t0.add_edge(i, n-d2+i);
    }

    for(int i=1; i+d2<n-d2+1; i+=d2) {
        for(int j=0; j<d1-1; j++) {
            if(i+j+d2<n-d2+1) {
                if(i+j!=d1 and i+j!=d2 and i+j!=n-d1 and i+j!=n-d2) {
                    t0.add_edge(i+j, i+j+d2);
                }else {
                    ;
                }
            }else {
                ;
            }
        }
    }

    for(int i=1; i+d1<n-d2+1; i+=d2) {
        for(int j=0; j<d1-1; j++) {
            if(i+j+d1<n-d2+1) {
                if(i+j!=d1 and i+j!=d2 and i+j!=n-d1 and i+j!=n-d2) {
                    t0.add_edge(i+j, i+j+d1);
                }else {
                    ;
                }
            }else {
                ;
            }
        }
    }
    if(n-d2+d1<=n-d1) {
        if((n-d2+d1)%d2==0 or (n-d2+d1-d2)%d1==0) {
            t0.add_edge(n-d2+d1-1, n-d2+d1);
        }else {
            t0.add_edge(n-d2+d1-d2, n-d2+d1);
        }
        for(int i=n-d2+d1+1; i<=n-d1; i++) {
                t0.add_edge(i-d1, i);
            }
    }

    if(d2>=3*d1-1) {
        t0.add_edge(2*d1-1, 3*d1-1);
    }

    for(int i=1; i<n-1; i++) {
        t0.add_edge(i, i+1);
    }

    return t0;
}

Graph construct1(int n, int d1, int d2) {
    Graph t1(n);
    
    init(t1, n);

    t1.add_edge(0, d1);
    t1.add_edge(d1, 2*d1);

   for(int i=1; i<d1; i++) {
       t1.add_edge(i, i+d2);
   }

    for(int i=d1; i>1; i--) {
        t1.add_edge(i, i-1);
    } 

    for(int i=d1; i<d2; i++) {
        if(i!=2*d1) {
            t1.add_edge(i, i+1);
        }
    }

    for(int i=1; i<d2; i++) {
        t1.add_edge(i, n-d2+i);
    }

    for(int i=d1; i+d2<n-max(d1-1, d2-d1); i+=d2) {
        for(int j=0; j<d2-d1; j++) {
            if(i+j+d2<n-max(d1-1, d2-d1)) {
                t1.add_edge(i+j, i+j+d2);
            }else {
                ;
            }
        }
    }

    for(int i=d2-max(d1-1, d2-d1); i+d1<n-d1+1; i+=d2) {
        for(int j=0; j<max(d1-1, d2-d1); j++) {
            if(i+j+d1<n-d1+1) {
                t1.add_edge(i+j, i+j+d1);
            }else {
                ;
            }
        }
    }

    for(int i=2*d2; i<n-max(d1-1, d2-d1); i+=d2) {
    	t1.add_edge(i-d1, i);
    }

    for(int i=d2; i<n-d2+d1; i++) {
        t1.add_edge(i, i+1);
    }

    return t1;
}

Graph construct2(int n, int d1, int d2) {
    Graph t2(n);
    
    init(t2, n);

    t2.add_edge(0, d2);

    for(int i=1; i<d1; i++) {
        t2.add_edge(i+d1, i);
    }

    t2.add_edge(d2, d2-d1);

    for(int i=d2; i>d1; i--) {
        t2.add_edge(i, i-1);
    }

    for(int i=1; i<n-d2; i++) {
        t2.add_edge(i, i+d2);
    }

    if(n-d2+d1<n-d1+1) {
        t2.add_edge(n-d2+d1-1, n-d2+d1);
    }

    for(int i=d1; i<n-d2; i++) {
        t2.add_edge(i, i+d1);
    }

    for(int i=d2; i<n-1; i++) {
        t2.add_edge(i, i+1);
    }

    return t2;
}

vector<Graph> construct(int n, int d1, int d2) {
    edges.resize(n);
    for(int i=0; i<n; i++)
        edges[i].assign(n, 0);

    Graph t0 = construct0(n, d1, d2);

    Graph t1 = construct1(n, d1, d2);

    Graph t2 = construct2(n, d1, d2);

    Graph t3(n), t4(n), t5(n);
    for(int i=0; i<n; i++)
        for(int j=1; j<n; j++)
            if(t0.mat[i][j]) t3.add_edge((n-i+n)%n, (n-j+n)%n);
    for(int i=0; i<n; i++)
        for(int j=1; j<n; j++)
            if(t1.mat[i][j]) t4.add_edge((n-i+n)%n, (n-j+n)%n);
    for(int i=0; i<n; i++)
        for(int j=1; j<n; j++)
            if(t2.mat[i][j]) t5.add_edge((n-i+n)%n, (n-j+n)%n);

    vector<Graph> ts {t0, t1, t2, t3, t4, t5};

    return ts;
}
