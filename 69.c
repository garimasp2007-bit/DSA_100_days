/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct HeapNode **array;
};

struct Node* newNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->w = w;
    node->next = NULL;
    return node;
}

struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return heap;
}

void swap(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int l = 2*idx + 1;
    int r = 2*idx + 2;

    if (l < heap->size && heap->array[l]->dist < heap->array[smallest]->dist)
        smallest = l;

    if (r < heap->size && heap->array[r]->dist < heap->array[smallest]->dist)
        smallest = r;

    if (smallest != idx) {
        struct HeapNode *smallestNode = heap->array[smallest];
        struct HeapNode *idxNode = heap->array[idx];

        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;

        swap(&heap->array[smallest], &heap->array[idx]);
        heapify(heap, smallest);
    }
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

struct HeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap)) return NULL;

    struct HeapNode* root = heap->array[0];
    struct HeapNode* last = heap->array[heap->size - 1];

    heap->array[0] = last;
    heap->pos[last->v] = 0;

    heap->size--;
    heapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(struct MinHeap *heap, int v) {
    return heap->pos[v] < heap->size;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* node = newNode(v, w);
        node->next = adj[u];
        adj[u] = node;
    }

    int src;
    scanf("%d", &src);

    int dist[n];
    struct MinHeap* heap = createMinHeap(n);

    for (int v = 0; v < n; v++) {
        dist[v] = INT_MAX;
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    heap->array[src] = newHeapNode(src, 0);
    heap->pos[src] = src;
    dist[src] = 0;
    heap->size = n;

    decreaseKey(heap, src, 0);

    while (!isEmpty(heap)) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            if (isInMinHeap(heap, v) && dist[u] != INT_MAX && temp->w + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->w;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}
