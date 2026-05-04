#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node*left;
struct Node*right;
};

struct Node*newNode(int val){
struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
temp->data=val;
temp->left=temp->right=NULL;
return temp;
}

struct Node**queue;
int front=0,rear=0;

void push(struct Node*node){
queue[rear++]=node;
}

struct Node*pop(){
return queue[front++];
}

int empty(){
return front==rear;
}

struct Node*buildTree(int n){
if(n==0)return NULL;
int val,i=1;
scanf("%d",&val);
struct Node*root=newNode(val);
push(root);
while(!empty()&&i<n){
struct Node*temp=pop();
int l,r;
scanf("%d",&l);i++;
if(l!=-1){
temp->left=newNode(l);
push(temp->left);
}
if(i<n){
scanf("%d",&r);i++;
if(r!=-1){
temp->right=newNode(r);
push(temp->right);
}
}
}
return root;
}

void levelOrder(struct Node*root){
if(!root)return;
push(root);
while(!empty()){
struct Node*temp=pop();
printf("%d ",temp->data);
if(temp->left)push(temp->left);
if(temp->right)push(temp->right);
}
}

int main(){
int n;
scanf("%d",&n);
queue=(struct Node**)malloc(sizeof(struct Node*)*n);
struct Node*root=buildTree(n);
front=rear=0;
levelOrder(root);
return 0;
}