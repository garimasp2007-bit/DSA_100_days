#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

typedef struct {
    int vertex, dist;
} HeapNode;

Node* adj[1001];

HeapNode heap[10001];
int size = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int v, int dist) {
    size++;
    heap[size].vertex = v;
    heap[size].dist = dist;

    int i = size;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int left = 2*i, right = 2*i + 1, smallest = i;

        if (left <= size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return root;
}

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
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

    int source;
    scanf("%d", &source);

    int dist[1001];
    for (int i = 1; i <= n; i++) dist[i] = INF;

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode top = pop();
        int u = top.vertex;

        if (top.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
