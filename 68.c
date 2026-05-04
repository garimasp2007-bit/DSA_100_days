/*
problem: Implement topological sorting using in-degree array and queue (Kahn’s Algorithm).
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++) indegree[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->data;
            indegree[v]--;
            if (indegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != n) printf("Cycle exists");

    return 0;
}
