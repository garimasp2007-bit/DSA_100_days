
/* Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
*/

#include<stdio.h>
int main(){

    int n, i, j;
    int arr[50];
    int count = 0, sum;

    printf("Enter n = ");
    scanf("%d", &n);

    printf("Enter elements = ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++){
        sum = 0;
        
        for(j = i; j < n; j++){
            sum = sum + arr[j];

            if(sum == 0){
                count++;
            }
        }
    }

    printf("Number of subarrays with sum 0 = %d", count);

    return 0;
}
