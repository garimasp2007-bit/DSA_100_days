#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

typedef struct {
    int vertex, key;
} HeapNode;

Node* adj[1001];
HeapNode heap[10001];
int size = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(int v, int key) {
    size++;
    heap[size].vertex = v;
    heap[size].key = key;

    int i = size;
    while (i > 1 && heap[i].key < heap[i/2].key) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int l = 2*i, r = 2*i + 1, smallest = i;

        if (l <= size && heap[l].key < heap[smallest].key)
            smallest = l;
        if (r <= size && heap[r].key < heap[smallest].key)
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

void addEdge(int u, int v, int w) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->v = v;
    n1->w = w;
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->v = u;
    n2->w = w;
    n2->next = adj[v];
    adj[v] = n2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int visited[1001] = {0};
    int key[1001];

    for (int i = 1; i <= n; i++) key[i] = INF;

    key[1] = 0;
    push(1, 0);

    int total = 0;

    while (size > 0) {
        HeapNode top = pop();
        int u = top.vertex;

        if (visited[u]) continue;

        visited[u] = 1;
        total += top.key;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
                push(v, w);
            }
            temp = temp->next;
        }
    }

    printf("%d", total);

    return 0;
}
