#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int A[], int N) {
    int  i;
    srand( (unsigned int) time(NULL) );
    for (i=0; i<N; i++)
        A[i] = rand() % 100000;
}

int count(int A[], int min, int max, int N) {
    int i, count = 0;
    for(i=0; i<N; i++)
        if(min<=A[i] && A[i]<max)
            count++;
    return count;
}

int main() {
    int i;
    int N[8] = {1000, 10000, 100000, 1000000, 2000000, 3000000, 4000000, 5000000};
    int A[8][N[7]];
    for(i=0; i<8; i++){
        init(A[i], N[i]);
    }
    printf("N");
    for(i=0; i<8; i++)
        printf(" & %d", N[i]);
    printf(" \\\\\n");
    for(i=0; i<100000; i+=5000)
        printf("%6d -%6d & %d & %d & %d & %d & %d & %d & %d & %d \\\\\n", i, i+5000, count(A[0], i, i+5000, N[0]), count(A[1], i, i+5000, N[1]), count(A[2], i, i+5000, N[2]), count(A[3], i, i+5000, N[3]), count(A[4], i, i+5000, N[4]), count(A[5], i, i+5000, N[5]), count(A[6], i, i+5000, N[6]), count(A[7], i, i+5000, N[7]));
    return 0;   
}
