
/* Problem: Given an array of integers, rotate the array to the right by k positions.
*/

#include<stdio.h>
int main(){
    
    int n, i, k;
    int arr[50];
    int rotated[50];
    printf("Enter number of elements= ");
    scanf("%d", &n);

    printf("Enter the %d elements= ",n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter k (positions to rotate)= ");
    scanf("%d", &k);
    k = k % n;

    for(i = 0; i < n; i++){
        rotated[(i + k) % n] = arr[i];
    }

    printf("Rotated array= ");
    for(i = 0; i < n; i++){
        printf("%d ", rotated[i]);
    }
    printf("\n");

    return 0;
}
