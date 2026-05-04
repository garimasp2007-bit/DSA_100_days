/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void dfs(int v, struct Node* adj[], int visited[], int stack[], int *top) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) dfs(temp->data, adj, visited, stack, top);
        temp = temp->next;
    }
    stack[(*top)++] = v;
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
    }

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int stack[n], top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, adj, visited, stack, &top);
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
