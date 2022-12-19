#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5000000

void init(int A[]) {
    int  i;
    srand( (unsigned int) time(NULL) );
    for (i=0; i<N; i++)
        A[i] = rand() % 100000;
}

int count(int A[], int min, int max) {
    int i, count = 0;
    for(i=0; i<N; i++)
        if(min<=A[i] && A[i]<max)
            count++;
    return count;
}

int main() {
    int i;
    int A[N];
    init(A);
    for(i=0; i<100000; i+=5000)
        printf("%6d -%6d : %d\n", i, i+5000, count(A, i, i+5000));
    return 0;   
}
