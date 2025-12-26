#include <stdio.h>

int a[20][20], visited[20], n;


void bfs(int v) {
    int queue[20], front = 0, rear = 0;
    int i;

    visited[v] = 1;
    queue[rear++] = v;

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 1; i <= n; i++) {
            if (a[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}


int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
