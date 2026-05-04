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

int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b)
        return 1;
    if (!a || !b)
        return 0;
    if (a->val != b->val)
        return 0;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = build(arr, n);

    if (isMirror(root, root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
