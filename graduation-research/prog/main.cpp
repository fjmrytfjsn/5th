#include <iostream>
#include <stdlib.h>
// #include "construct.cpp"
#include "cr_check.cpp"

int main(int argc, char *argv[]) {
    bool ok = true;
    int n, d1, d2;

    int n_min, n_max;
    n_min = 10;
    n_max = atoi(argv[1]);
    // d1 = atoi(argv[3]);

    for(n=n_min; n<=n_max; n++) {
        for(d1=3; d1<=(n+2)/4; d1++) {
            for(d2=d1+1; d2*2<n; d2++) {
                vector<Graph> ts = construct(n, d1, d2);
                if(!cr_check(ts, n, d1, d2)) ok = false;
            }
            cout<<endl;
        }
    }
    
    puts("");
    if(ok) printf("%d - %d : successed\n", n_min, n_max);
    else printf("%d - %d : failed\n", n_min, n_max);

    return 0;
}
