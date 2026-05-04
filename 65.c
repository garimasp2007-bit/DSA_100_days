/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int dfs(int v, int parent, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->data;
        if (!visited[u]) {
            if (dfs(u, v, adj, visited)) return 1;
        } else if (u != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
        newNode2->data = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
