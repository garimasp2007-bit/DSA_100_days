/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* build(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = create(arr[0]);
    q[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = q[front++];

        if (i < n && arr[i] != -1) {
            curr->left = create(arr[i]);
            q[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = create(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }

    free(q);
    return root;
}

void rightView(struct Node* root) {
    if (!root)
        return;

    struct Node** q = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = q[front++];

            if (i == size - 1)
                printf("%d ", curr->val);

            if (curr->left)
                q[rear++] = curr->left;
            if (curr->right)
                q[rear++] = curr->right;
        }
    }

    free(q);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = build(arr, n);
    rightView(root);

    return 0;
}
