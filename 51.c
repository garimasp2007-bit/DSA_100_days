/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node* lca(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;
    if (p < root->val && q < root->val)
        return lca(root->left, p, q);
    if (p > root->val && q > root->val)
        return lca(root->right, p, q);
    return root;
}

int main() {
    int n, x, p, q;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d %d", &p, &q);
    struct Node* res = lca(root, p, q);
    if (res)
        printf("%d\n", res->val);
    return 0;
}
