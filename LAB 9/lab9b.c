#include <stdio.h>

int a[20][20], visited[20], n;


void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start = 1, connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

   
    dfs(start);

 
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("Graph is CONNECTED\n");
    else
        printf("Graph is NOT CONNECTED\n");

    return 0;
}
