#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> edges(0, vector<int>(0, 0));

struct Graph {
    int n;
    Graph(int n): n(n), mat(n, vector<int>(n, 0)), G(n, vector<int>(n, 0)) {}
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

Graph LOOP(int base, int n, int d1, int d2, Graph t) {
    int now = base+d2;
    while(1) {
        if(now!=d1 and now!=d2 and now!=n-d1 and now!=n-d2) {
            if(now+d1<=n-d2) {
                t.add_edge(now, now+d1);
            }else {
                ;
            }
            if(now+d2<=n-d2) {
                if(t.add_edge(now, now+d2)) {
                    ;
                }else {
                    break;
                }
            }else {
                break;
            }
        }else {
            break;
        }
        now += d2;
    }
    return t;
}

Graph STEP4(int range, int n, int d1, int d2, Graph t) {
    for(int i=1; i<range; i++) {
        if(i==1 or i==d1 or i==d2) continue;
        t.add_edge(i, (i+d1)%n);
        t.add_edge(i, (i+d2)%n);
        t.add_edge(i, (i+n-d1)%n);
        t.add_edge(i, (i+n-d2)%n);
        t = LOOP(i, n, d1, d2, t);
    }

    return t;
}

Graph STEP5(int n, int d1, int d2, Graph t) {
    //STEP5-1
    for(int i=1; i<n-d1; i++)
        if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2) {
            if(i%d1!=0 or i%d2!=0) {
                t.add_edge(i, i+d1);
            }
        }

    //STEP5-2
    for(int i=1; i<n-d2; i++) {
        if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2){
            t.add_edge(i, i+d2);
        }
    }

    //STEP5-3
    for(int i=1; i<n-1; i++)
        if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2)
            t.add_edge(i, i+1);

    return t;
}

Graph construct0(int n, int d1, int d2) {
    Graph t0(n);
    
    init(t0, n);

    //STEP1
    t0.add_edge(0, 1);

    //STEP2
    t0.add_edge(1, 1+1); 
    t0.add_edge(1, 1+d1);
    t0.add_edge(1, 1+d2);
    t0.add_edge(1, (1+n-d1)%n);
    t0.add_edge(1, (1+n-d2)%n);

    // int now = 1+d2;
    // while(1) {
    //     if(now!=d1 and now!=d2 and now!=n-d1 and now!=n-d2) {
    //         if(now+d1<n-d1) {
    //             t0.add_edge(now, now+d1);
    //         }else {
    //             ;
    //         }
    //         if(now+d2<n-d1) {
    //             if(t0.add_edge(now, now+d2)) {
    //                 ;
    //             }else {
    //                 break;
    //             }
    //         }else {
    //             break;
    //         }
    //     }else {
    //         break;
    //     }
    //     now += d2;
    // }

    t0 = LOOP(1, n, d1, d2, t0);

    //STEP3
    for(int i=1+1; i<d1; i++)
        t0.add_edge(i, i+1);
    
    // //STEP4
    // for(int i=2; i<n; i++) {
    //     if(i==d1 or i==d2) continue;
    //     t0.add_edge(i, (i+d1)%n);
    //     t0.add_edge(i, (i+d2)%n);
    //     t0.add_edge(i, (i+n-d1)%n);
    //     t0.add_edge(i, (i+n-d2)%n);
    //     // now = i+d2;
    //     // while(1) {
    //     //     if(now!=d1 and now!=d2 and now!=n-d1 and now!=n-d2) {
    //     //         if(now+d1<n-d1) {
    //     //             t0.add_edge(now, now+d1);
    //     //         }else {
    //     //             ;
    //     //         }
    //     //         if(now+d2<n-d1) {
    //     //             if(t0.add_edge(now, now+d2)) {
    //     //                 ;
    //     //             }else {
    //     //                 break;
    //     //             }
    //     //         }else {
    //     //             break;
    //     //         }
    //     //     }else {
    //     //         break;
    //     //     }
    //     //     now += d2;
    //     // }
    //     t0 = LOOP(i, n, d1, d2, t0);
    // }
    t0 = STEP4(d1, n, d1, d2, t0);

    // //STEP5-1
    // for(int i=1; i<n-d1; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2) {
    //         t0.add_edge(i, i+d1);
    //     }
    // }
    // //STEP5-2
    // for(int i=1; i<n-d2; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2)
    //         t0.add_edge(i, i+d2);
    // }
    // //STEP5-3
    // for(int i=1; i<n-1; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2)
    //         t0.add_edge(i, i+1);
    // }
    
    t0 = STEP5(n, d1, d2, t0);

    return t0;
}

Graph construct1(int n, int d1, int d2) {
    Graph t1(n);
    
    init(t1, n);

    //STEP1
    t1.add_edge(0, d1);

    //STEP2
    t1.add_edge(d1, d1-1); 
    t1.add_edge(d1, d1+1); 
    t1.add_edge(d1, d1+d1);
    t1.add_edge(d1, d1+d2);
    t1.add_edge(d1, d1-d2+n);

    // int now = d1+d2;
    // while(1) {
    //     if(now!=d1 and now!=d2 and now!=n-d1 and now!=n-d2) {
    //         if(now+d1<n-d1) {
    //             t1.add_edge(now, now+d1);
    //         }else {
    //             ;
    //         }
    //         if(now+d2<n-d1) {
    //             if(t1.add_edge(now, now+d2)) {
    //                 ;
    //             }else {
    //                 break;
    //             }
    //         }else {
    //             break;
    //         }
    //     }else {
    //         break;
    //     }
    //     now += d2;
    // }

    t1 = LOOP(d1, n, d1, d2, t1);

    //STEP3
    for(int i=d1-1; i>1; i--)
        t1.add_edge(i, i-1);
    for(int i=d1+1; i<d2; i++)
        t1.add_edge(i, i+1);
    
    // //STEP4
    // for(int i=2; i<n; i++) {
    //     if(i==d1 or i==d2) continue;
    //     t1.add_edge(i, i+d1);
    //     t1.add_edge(i, (i+n-d1)%n);
    //     t1.add_edge(i, (i+n-d2)%n);
    //     if(t1.add_edge(i, i+d2)) {
    //         ;
    //     }else {
    //         continue;
    //     }
    //     // now = i+d2;
    //     // while(1) {
    //     //     if(now!=d1 and now!=d2 and now!=n-d1 and now!=n-d2) {
    //     //         if(now+d1<n-d1) {
    //     //             t1.add_edge(now, now+d1);
    //     //         }else {
    //     //             ;
    //     //         }
    //     //         if(now+d2<n-d1) {
    //     //             if(t1.add_edge(now, now+d2)) {
    //     //                 ;
    //     //             }else {
    //     //                 break;
    //     //             }
    //     //         }else {
    //     //             break;
    //     //         }
    //     //     }else {
    //     //         break;
    //     //     }
    //     //     now += d2;
    //     // }

    //     t1 = LOOP(i, n, d1, d2, t1);
    // }
    t1 = STEP4(d2, n, d1, d2, t1);

    // //STEP5-1
    // for(int i=1; i<n-d1; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2) {
    //         t1.add_edge(i, i+d1);
    //     }
    // }
    // //STEP5-2
    // for(int i=1; i<n-d2; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2) {
    //         t1.add_edge(i, i+d2);
    //     }
    // }
    // //STEP5-3
    // for(int i=1; i<n-1; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2)
    //         t1.add_edge(i, i+1);
    // }

    t1 = STEP5(n, d1, d2, t1);

    return t1;
}

Graph construct2(int n, int d1, int d2) {
    Graph t2(n);
    
    init(t2, n);

    //STEP1
    t2.add_edge(0, d2);

    //STEP2
    t2.add_edge(d2, d2-1); 
    t2.add_edge(d2, d2+1); 
    t2.add_edge(d2, d2+d1);
    t2.add_edge(d2, d2+d2);
    t2.add_edge(d2, (d2+n-d1)%n);

    // int now = d2+d2;
    // while(1) {
    //     if(now!=d1 and now!=d2 and now!=n-d1 and now!=n-d2) {
    //         if(now+d1<n-d1) {
    //             t2.add_edge(now, now+d1);
    //         }else {
    //             ;
    //         }
    //         if(now+d2<n-d1) {
    //             if(t2.add_edge(now, now+d2)) {
    //                 ;
    //             }else {
    //                 break;
    //             }
    //         }else {
    //             break;
    //         }
    //     }else {
    //         break;
    //     }
    //     now += d2;
    // }

    t2 = LOOP(d2, n, d1, d2, t2);


    //STEP3
    for(int i=d2-1; i>d1; i--)
        t2.add_edge(i, i-1);
    for(int i=d2+1; i<n-d2; i++)
        t2.add_edge(i, i+1);
    
    // //STEP4
    // for(int i=2; i<n; i++) {
    //     if(i==d1 or i==d2) continue;
    //     t2.add_edge(i, i+d1);
    //     t2.add_edge(i, i+d2);
    //     t2.add_edge(i, (i+n-d1)%n);
    //     t2.add_edge(i, (i+n-d2)%n);
    //     // now = i+d2;
    //     // while(1) {
    //     //     if(now!=d1 and now!=d2 and now!=n-d1 and now!=n-d2) {
    //     //         if(now+d1<n-d1) {
    //     //             t2.add_edge(now, now+d1);
    //     //         }else {
    //     //             ;
    //     //         }
    //     //         if(now+d2<n-d1) {
    //     //             if(t2.add_edge(now, now+d2)) {
    //     //                 ;
    //     //             }else {
    //     //                 break;
    //     //             }
    //     //         }else {
    //     //             break;
    //     //         }
    //     //     }else {
    //     //         break;
    //     //     }
    //     //     now += d2;
    //     // }

    //     t2 = LOOP(i, n, d1, d2, t2);
    // }
    t2 = STEP4(n-d2, n, d1, d2, t2);

    // //STEP5-1
    // for(int i=1; i<n-d1; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2) {
    //         t2.add_edge(i, i+d1);
    //     }
    // }
    // //STEP5-2
    // for(int i=1; i<n-d2; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2) {
    //         t2.add_edge(i, i+d2);
    //     }
    // }
    // //STEP5-3
    // for(int i=1; i<n-1; i++) {
    //     if(i!=d1 and i!=d2 and i!=n-d1 and i!=n-d2)
    //         t2.add_edge(i, i+1);
    // }

    t2 = STEP5(n, d1, d2, t2);

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

// int main() {
//     int n, d1, d2;
//     cin >> n >> d1 >> d2;
//     vector<Graph> ts = construct(n, d1, d2);
//     for(int x=0; x<6; x++) {
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 cout << ts[x].mat[i][j] << ' ';
//             }
//             cout << "\n";
//         }cout << "\n";
//     }

//     return 0;
// }
