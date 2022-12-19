#ifndef construct2_h
#define construct2_h

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
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

void init(Graph &t, int n);
Graph construct0(int n, int d1, int d2);
Graph construct1(int n, int d1, int d2);
Graph construct2(int n, int d1, int d2);
vector<Graph> construct(int n, int d1, int d2);

#endif