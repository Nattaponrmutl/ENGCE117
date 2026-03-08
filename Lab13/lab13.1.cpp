#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP( int *w, int *v, int n, int wx );

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x;

    x = KnapsackDP(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}

int *KnapsackDP(int *w, int *v, int n, int wx){

    int **dp;
    int *x;

    dp = (int**)malloc((n+1) * sizeof(int*));
    for(int i=0;i<=n;i++)
        dp[i] = (int*)malloc((wx+1) * sizeof(int));

    for(int i=0;i<=n;i++)
        for(int j=0;j<=wx;j++)
            dp[i][j] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=wx;j++){

            if(w[i-1] <= j){

                int take = v[i-1] + dp[i-1][j-w[i-1]];
                int notake = dp[i-1][j];

                if(take > notake)
                    dp[i][j] = take;
                else
                    dp[i][j] = notake;

            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    x = (int*)malloc(n * sizeof(int));

    int j = wx;

    for(int i=n;i>0;i--){

        if(dp[i][j] != dp[i-1][j]){
            x[i-1] = 1;
            j -= w[i-1];
        }else{
            x[i-1] = 0;
        }
    }

    return x;
}
