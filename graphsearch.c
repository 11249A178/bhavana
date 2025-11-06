#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void enqueue(int v) { queue[rear++] = v; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

void BFS(int n, int adj[n][n], int start) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n = 6;
    int adj[6][6] = {
        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {1,0,0,0,0,1},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0}
    };

    printf("BFS Traversal starting from node 0: ");
    BFS(n, adj, 0);
    printf("\n");

    return 0;
}
