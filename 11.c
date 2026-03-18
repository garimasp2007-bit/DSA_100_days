
//Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.
# include <stdio.h>
int main(){
    int row,col;
    scanf("%d %d",&row,&col);
    int mat1[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    int mat2[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    int sum[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
