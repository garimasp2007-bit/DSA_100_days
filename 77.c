#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[1001];
int visited[1001];

void addEdge(int u, int v) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->v = v;
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->v = u;
    n2->next = adj[v];
    adj[v] = n2;
}

void dfs(int u) {
    visited[u] = 1;
    Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v]) {
            dfs(temp->v);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}
