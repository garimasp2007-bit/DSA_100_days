//Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
# include <stdio.h>
int main(){
    int row,col;
    scanf("%d %d",&row,&col);
    int mat[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    if(row!=col){
        printf("Not a Symmetric Matrix");
        return 0;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]!=mat[j][i]){
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }
    printf("A symmetric Matrix");
    return 0;
}
