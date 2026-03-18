
//Perform inorder, preorder, and postorder traversals of a given binary tree.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// create node
struct node* newNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// build tree from level order
struct node* build(int arr[], int n, int i)
{
    if (i >= n || arr[i] == -1)
        return NULL;

    struct node* root = newNode(arr[i]);

    root->left = build(arr, n, 2*i + 1);
    root->right = build(arr, n, 2*i + 2);

    return root;
}

// inorder
void inorder(struct node* root)
{
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// preorder
void preorder(struct node* root)
{
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// postorder
void postorder(struct node* root)
{
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = build(arr, n, 0);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}
