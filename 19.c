
//Problem: Given an array of integers, find two elements whose sum is closest to zero.
# include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int no1,no2;
    int sum=arr[0]+arr[1];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int add=arr[i]+arr[j];
            if((add>0 && add<sum)||(add<0 && add>sum)){
                sum=add;
                no1=arr[i];
                no2=arr[j];
            }
        }
    }
    printf("%d %d",no1,no2);
    return 0;
}
