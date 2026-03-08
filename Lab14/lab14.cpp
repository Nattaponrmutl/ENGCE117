#include <stdio.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x);

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x, vx;

    x = new int[n];

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x)
{
    if(i == n)
        return 0;

    int *x0 = new int[n];
    int *x1 = new int[n];

    for(int k = 0; k < n; k++){
        x0[k] = 0;
        x1[k] = 0;
    }

    int v0 = KnapsackBT(w, v, n, wx, i + 1, x0);

    int v1 = 0;
    if(wx >= w[i]){
        v1 = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, x1);
    }

    if(v1 > v0){
        for(int k = i + 1; k < n; k++)
            x[k] = x1[k];

        x[i] = 1;

        delete[] x0;
        delete[] x1;

        return v1;
    }
    else{
        for(int k = i + 1; k < n; k++)
            x[k] = x0[k];

        x[i] = 0;

        delete[] x0;
        delete[] x1;

        return v0;
    }
}
