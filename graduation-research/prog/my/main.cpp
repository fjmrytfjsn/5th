#include<bits/stdc++.h>
#include"construct.cpp"
#include"cr_check.cpp"

int main() {
    int n, d1=4, d2;
    int n_min, n_max;
    cout<<"nの最小値を入力してください>>"; cin>>n_min;
    cout<<"nの最大値を入力してください>>"; cin>>n_max;

    for(n=n_min; n<=n_max; n++) {
        for(d2=d1+2; d2<n/2; d2++){ 
            vector<Graph> ts = construct(n, d1, d2);
            cr_check(ts, n, d1, d2);
        }
    }

    return 0;
}