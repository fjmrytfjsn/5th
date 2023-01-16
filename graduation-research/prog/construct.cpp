#include <algorithm>
#include <list>
#include <vector>
using namespace std;

vector<vector<int>> edges(0, vector<int>(0, 0));

struct Graph {
    int n;
    Graph(int n): n(n), mat(n, vector<int>(n, 0)), G(n, vector<int>(1, 0)), ver_list(0,0) {}
    list<int> ver_list;
    vector<vector<int>> mat, G;

    void add_edge(int u, int v) {
        if(edges[u][v])
            return;
        if(find(ver_list.begin(), ver_list.end(), v) != ver_list.end()) 
            return;
        edges[u][v] = mat[u][v] = 1;
        G[u].push_back(v);
        ver_list.push_back(v);
    }
};

Graph construct0(int n, int d1, int d2) {
    Graph t(n);

    t.add_edge(0, 1);

    for(int i=1; i<d1; i++)
        t.add_edge(i, n-d1+i);

    for(int i=1; i<d1; i++)
        t.add_edge(i, n-d2+i);

    for(int i=1; i+d2<n-d2+1; i+=d2)
        for(int j=0; j<d1-1; j++)
            if(i+j+d2<n-d2+1)
                t.add_edge(i+j, i+j+d2);
            else break;

    for(int i=1; i+d1<n-d2+1; i+=d2) {
        for(int j=0; j<d1-1; j++)
            if(i+j+d1<n-d2+1)
                t.add_edge(i+j, i+j+d1);
            else break;
        for(int j=i+2*d1-1-1; j+d1<i+d2; j+=d1)
            if(j+d1<n-d2+1)
                t.add_edge(j, j+d1);
            else break;
    }

    for(int i=n-(d2-d1); i<n-d1+1; i+=d1) {
        t.add_edge(i-1, i);
        for(int j=1; j<d1; j++)
            t.add_edge(i+j-d1, i+j);
    }

    for(int i=1; i<n-1; i++)
        t.add_edge(i, i+1);

    return t;
}

Graph construct1(int n, int d1, int d2) {
    Graph t(n);

    t.add_edge(0, d1);

    for(int i=d1; i>1; i--)
        t.add_edge(i, i-1);

    for(int i=1; i<d2; i++)
        t.add_edge(i, n-d2+i);

    for(int i=1; i<d1; i++)
        t.add_edge(i, i+d2);

    for(int i=d1; i+d2<n-max(d1-1, d2-d1); i+=d2)
        for(int j=0; j<d2-d1; j++)
            if(i+j+d2<n-max(d1-1, d2-d1))
                t.add_edge(i+j, i+j+d2);

    for(int i=d2-max(d1-1, d2-d1); i+d1<n-d1+1; i+=d2)
        for(int j=0; j<max(d1-1, d2-d1); j++)
            if(i+j+d1<n-d1+1)
                t.add_edge(i+j, i+j+d1);

    for(int i=2*d2; i<n-max(d1-1, d2-d1); i+=d2)
    	t.add_edge(i-d1, i);

    for(int i=d1; i<n-1; i++)
        t.add_edge(i, i+1);

    return t;
}

Graph construct2(int n, int d1, int d2) {
    Graph t(n);

    t.add_edge(0, d2);

    for(int i=1; i<d1; i++)
        t.add_edge(i+d1, i);

    t.add_edge(d2, d2-d1);

    for(int i=d2-d1; i>2*d1-1; i-=d1)
        t.add_edge(i, i-d1);

    for(int i=d2; i>d1; i--)
        t.add_edge(i, i-1);

    for(int i=1; i<n-d2; i++)
        t.add_edge(i, i+d2);

    if(n-d2+d1<n-d1+1)
        t.add_edge(n-d2+d1-1, n-d2+d1);

    for(int i=d1; i<n-d2; i++)
        t.add_edge(i, i+d1);

    for(int i=d2; i<n-1; i++)
        t.add_edge(i, i+1);

    return t;
}

Graph reverse(Graph org, int n) {
    Graph conv(n);
    for(int i=0; i<n; i++) {
        for(int j=1; j<n; j++)
            if(org.mat[i][j])
                conv.mat[(n-i)%n][(n-j)%n] = 1;
        for(auto ver:org.G[i])
            conv.G[(n-i)%n].push_back((n-ver)%n);
    }
    
    return conv;
}

vector<Graph> construct(int n, int d1, int d2) {
    edges.resize(n);
    for(int i=0; i<n; i++)
        edges[i].assign(n, 0);

    Graph t0(n), t1(n), t2(n), t3(n), t4(n), t5(n);

    t0 = construct0(n, d1, d2);
    t1 = construct1(n, d1, d2);
    t2 = construct2(n, d1, d2);

    t3 = reverse(t0, n);
    t4 = reverse(t1, n);
    t5 = reverse(t2, n);

    vector<Graph> ts {t0, t1, t2, t3, t4, t5};

    return ts;
}
