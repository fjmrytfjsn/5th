#ifndef cr_check_h
#define cr_check_h

#include<bits/stdc++.h>

bool is_spanning_tree(vector<Graph> ts, int n, int d1, int d2);
vector<vector<int>> find_path(int n, vector<vector<int>> G);
bool is_independent(vector<Graph> ts, int n, int d1, int d2);
bool cr_check(vector<Graph> ts, int n, int d1, int d2);

#endif