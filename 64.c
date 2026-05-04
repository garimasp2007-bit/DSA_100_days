#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* adj[100];
int visited[100];

void addEdge(int u,int v){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=v;
    newNode->next=adj[u];
    adj[u]=newNode;

    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=u;
    newNode->next=adj[v];
    adj[v]=newNode;
}

void bfs(int n,int start){
    int queue[100];
    int front=0,rear=0;

    queue[rear++]=start;
    visited[start]=1;

    while(front<rear){
        int v=queue[front++];
        printf("%d ",v);

        struct Node* temp=adj[v];

        while(temp!=NULL){
            int neighbor=temp->data;

            if(!visited[neighbor]){
                visited[neighbor]=1;
                queue[rear++]=neighbor;
            }

            temp=temp->next;
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        adj[i]=NULL;
        visited[i]=0;
    }

    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }

    int start;
    scanf("%d",&start);

    bfs(n,start);

    return 0;
}