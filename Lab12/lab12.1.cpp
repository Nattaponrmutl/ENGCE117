#include <stdio.h>

int *Dijkstra( int *L, int n );

int main() {

    int n = 5, i = 0, j = 0, *d, *g;

    g = new int[ n * n ];

    for( i = 0 ; i < n ; i++ )
        for( j = 0 ; j < n ; j++ )
            g[ i * n + j ] = -1;

    g[ 0 * n + 1 ] = 100 ;  g[ 0 * n + 2 ] = 80 ;
    g[ 0 * n + 3 ] = 30  ;  g[ 0 * n + 4 ] = 10 ;
    g[ 1 * n + 2 ] = 20  ;  g[ 3 * n + 1 ] = 20 ;
    g[ 3 * n + 2 ] = 20  ;  g[ 4 * n + 3 ] = 10 ;

    d = Dijkstra( g , n );

    for( i = 0 ; i < n - 1 ; i++ )
        printf("%d ", d[i]);

    return 0;
}

int *Dijkstra(int *L, int n)
{
    int *dist = new int[n];
    int *visited = new int[n];

    for(int i=0;i<n;i++){
        dist[i] = 9999;
        visited[i] = 0;
    }

    dist[0] = 0;

    for(int count=0; count<n-1; count++){

        int min = 9999, u = -1;

        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v=0; v<n; v++){

            int weight = L[u*n + v];

            if(weight != -1 && !visited[v] && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }

    int *result = new int[n-1];

    for(int i=1;i<n;i++)
        result[i-1] = dist[i];

    return result;
}
