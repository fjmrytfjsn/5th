#include<bits/stdc++.h>
#include"cr_check.cpp"
#define REP(i,b,e) for(int i=(b);i<(e);i++)

Graph construct0(int n, int d1, int d2) {
    Graph t0(n);
    int diff = d2 - d1;
    int lim = n - d2 + 1;
    REP(i, n-d2+1, n-d1+1) t0.add_edge(i, (i+d2)%n);
    REP(i, n-d1+1, n) t0.add_edge(i, (i+d1)%n);
    REP(i, 0, d1-1) t0.add_edge(i, i+1);
    for(int base = 0; base < n - d2 + 1; base += d2) {
        REP(i, 1, diff+1) if(base + i + d1 < lim) t0.add_edge(base + i, base + i + d1);
        REP(i, 1, d1) if(base + i + d2 < lim) t0.add_edge(base + i, base + i + d2);
        if(base + d1 < lim) t0.add_edge(base + d1 - 1, base + d1);
    }
    return t0;
}

Graph construct1(int n, int d1, int d2) {
    Graph t1(n);
    int diff = d2 - d1;
    int lim = n - d2 + 1;
    REP(i, n-d1+1, n) t1.add_edge(i, (i+d2)%n);
    t1.add_edge(0, d1);
    REP(i, 1, d2-1) t1.add_edge(i, i+1);
    for(int base = 1; base < lim; base += d2) {
        REP(i, diff, d2-1) if(base + i + d1 < lim) t1.add_edge(base + i, base + i + d1);
        REP(i, d1-1, d1-1+diff) if(base + i + d2 < lim) t1.add_edge(base + i, base + i + d2);
        if(base + d1 + 1 < lim) t1.add_edge(base + d1, base + d1 + 1);
    }
    if((n-d1-d1)%d2 == 1) {
        t1.add_edge(n-d2+1 - d2, n-d2+1);
        t1.add_edge(n-d1 - d2, n-d1);
    } else if((n-d1-d1)%d2 == 2) {
        t1.add_edge(n-d2+1 - d2, n-d2+1);
        t1.add_edge(n-d1 - d1, n-d1);
    } else {
        REP(i, n-d2+1, n-d1+1) t1.add_edge(i - d1, i);
    }
    return t1;
}

Graph construct2(int n, int d1, int d2) {
    Graph t2(n);
    int diff = d2 - d1;
    int lim = n - d2 + 1;
    t2.add_edge(0, d2);
    REP(i, 1, d1) t2.add_edge(i, i+d1);
    t2.add_edge(d1+1, d2); 
    for(int base = d1; base < lim; base += d2) {
        if(base + diff + d1 < lim) t2.add_edge(base + diff, base + diff + d1);
        if(base + diff + d2 < lim) t2.add_edge(base + diff, base + diff + d2);
        REP(i, 0, d2-1) if(i != 1 and base + i + 1 < lim) t2.add_edge(base + i, base + i + 1);
    }
    if((n-d1-d1)%d2 == 1) {
        t2.add_edge(n-d2+1 - d1, n-d2+1);
        t2.add_edge(n-d1 - d1, n-d1);
    } else if((n-d1-d1)%d2 == 2) {
        t2.add_edge(n-d2+1 - d1, n-d2+1);
        t2.add_edge(n-d1 - d2, n-d1);
    } else {
        REP(i, n-d2+1, n-d1+1) t2.add_edge(i - d2, i);
    }
    REP(i, n-d1+1, n) t2.add_edge(i - d2, i);
    return t2;
}

void print_edge_count(std::vector<Graph> ts){
    int n = ts.at(0).n;
    std::vector< std::vector<int> > count(n, std::vector<int>(n, 0));
    for(Graph t: ts){
        REP(i, 0, n) REP(j, i+1, n) if(t.mat[i][j]) {
            count[i][j]++;
            count[j][i]++;
        }
    }
    puts("edge count ...");
    REP(i, 0, n) {
        printf("%2d:", i);
        REP(j, 0, n){
            if(i == j) printf("x");
            else printf("%d", count[i][j]);
        }
        puts("");
    }
    return;
}

bool construct_and_check_trees(int n, int d1, int d2, bool verbose = false) {
    Graph t0 = construct0(n, d1, d2);;
    Graph t1 = construct1(n, d1, d2);;
    Graph t2 = construct2(n, d1, d2);;
    Graph t3(n), t4(n), t5(n);
    REP(i, 0, n) REP(j, i+1, n) if(t0.mat[i][j]) t3.add_edge((n-i)%n, n-j);
    REP(i, 0, n) REP(j, i+1, n) if(t1.mat[i][j]) t4.add_edge((n-i)%n, n-j);
    REP(i, 0, n) REP(j, i+1, n) if(t2.mat[i][j]) t5.add_edge((n-i)%n, n-j);
    
    std::vector<Graph> ts = {t0, t1, t2, t3, t4, t5};
    //print_edge_count(ts);
    return cr_check(ts, verbose);
}


int main() {
    ///*
    bool ok = true;
    int diff = 2;
    REP(n, (2+diff)*2, 50){
        printf("n = %2d\n", n);
        REP(d1, 1+diff, (n-1)/3) { //[1+diff, (n-3)/3)
            int d2 = d1 + diff;
            printf("  CR(%2d,%2d,%2d)", n, d1, d2);
            std::flush(std::cout);
            if(construct_and_check_trees(n, d1, d2)) printf(" ... OK :)\n");
            else{
                printf(" ... NG\n");
                ok = false;
            }
        }
    }
    if(ok) printf("8 <= n < 50,  3 <= d1 < (n-3)/3, d2 = d1 + 2 ... OK\n");
    else printf("NG\n");
    //*/

    return 0;
}
