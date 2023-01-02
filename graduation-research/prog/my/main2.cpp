#include<iostream>
#include"construct2.cpp"
#include"cr_check.cpp"

int main() {
    bool ok = true;
    int n, d1, d2;

    int n_min, n_max;
    cout<<"nの最小値を入力してください>>"; cin>>n_min;
    cout<<"nの最大値を入力してください>>"; cin>>n_max;
    cout<<"d1の値を入力してください>>"; cin>>d1;
    puts("");

    for(n=n_min; n<=n_max; n++) {
        for(d2=d1+1; d2*2<n; d2++) {
            vector<Graph> ts = construct(n, d1, d2);
            if(!cr_check(ts, n, d1, d2)) ok = false;
        }
        cout<<endl;
    }
    
    puts("");
    if(ok) printf("%d - %d : successed\n", n_min, n_max);
    else printf("%d - %d : failed\n", n_min, n_max);

    return 0;
}
