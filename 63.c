#include <stdio.h>

int visited[100];

void dfs(int graph[100][100],int n,int v){
    printf("%d ",v);
    visited[v]=1;

    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && visited[i]==0){
            dfs(graph,n,i);
        }
    }
}

int main(){
    int n;

    scanf("%d",&n);

    int graph[100][100];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    int start;
    scanf("%d",&start);

    dfs(graph,n,start);

    return 0;
}