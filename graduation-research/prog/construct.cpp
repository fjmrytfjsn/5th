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

    int base = 1;
    while(base+d2<n-d2+1) {
        for(int i=0; i<d1-1; i++)
            if(base+i+d2<n-d2+1)
                t.add_edge(base+i, base+i+d2);
        base += d2;
    }

    base = 1;
    while(base+d1<n-d2+1) {
        for(int i=0; i<d1-1; i++)
            if(base+i+d1<n-d2+1)
                t.add_edge(base+i, base+i+d1);
        int j=base+2*d1-2;
        while(j+d1<base+d2) {
            if(j+d1<n-d2+1)
                t.add_edge(j, j+d1);
            j += d1;
        }
        base += d2;
    }

    base = n-(d2-d1);
    while(base<n-d1+1) {
        t.add_edge(base-1, base);
        for(int i=1; i<d1; i++)
            t.add_edge(base+i-d1, base+i);
        base += d1;
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

    int base = d1;
    while(base+d2<n-max(d1-1, d2-d1)) {
        for(int i=0; i<d2-d1; i++)
            if(base+i+d2<n-max(d1-1, d2-d1))
                t.add_edge(base+i, base+i+d2);
        base += d2;
    }

    base = d2-max(d1-1, d2-d1);
    while(base+d1<n-d1+1) {
        for(int i=0; i<max(d1-1, d2-d1); i++)
            if(base+i+d1<n-d1+1)
                t.add_edge(base+i, base+i+d1);
        base += d2;
    }

    base = 2*d2;
    while(base<n-max(d1-1, d2-d1)) {
    	t.add_edge(base-d1, base);
        base += d2;
    }

    for(int i=d1; i<n-1; i++)
        t.add_edge(i, i+1);

    return t;
}

Graph construct2(int n, int d1, int d2) {
    Graph t(n);

    t.add_edge(0, d2);
    t.add_edge(d2, d2-d1);

    for(int i=1; i<d1; i++)
        t.add_edge(i+d1, i);

    int base = d2-d1;
    while(base>2*d1-1) {
        t.add_edge(base, base-d1);
        base -= d1;
    }

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
