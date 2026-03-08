#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx ) {

    int *x = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        x[i] = 0;

    for(int i = 0; i < n; i++) {
        if(w[i] <= wx) {
            x[i] = 1;
            wx = wx - w[i];
        }
    }

    return x;
}

int main() {

    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackGreedy(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}
