/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int hd;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->hd = 0;
    node->left = node->right = NULL;
    return node;
}

typedef struct QNode {
    Node* node;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->node = node;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QNode* temp = q->front;
    Node* node = temp->node;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    Node* root = newNode(arr[0]);
    Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        Node* curr = dequeue(q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    int min = 0, max = 0;
    root->hd = 0;
    enqueue(q, root);

    Node* list[1000];
    int hd[1000];
    int idx = 0;

    while (!isEmpty(q)) {
        Node* curr = dequeue(q);
        list[idx] = curr;
        hd[idx] = curr->hd;
        if (curr->hd < min) min = curr->hd;
        if (curr->hd > max) max = curr->hd;
        idx++;

        if (curr->left) {
            curr->left->hd = curr->hd - 1;
            enqueue(q, curr->left);
        }
        if (curr->right) {
            curr->right->hd = curr->hd + 1;
            enqueue(q, curr->right);
        }
    }

    for (int h = min; h <= max; h++) {
        for (int j = 0; j < idx; j++) {
            if (hd[j] == h) {
                printf("%d ", list[j]->data);
            }
        }
        printf("\n");
    }

    return 0;
}
