/*
day 74 - winner of an election

Problem: Find candidate with maximum votes.

Input:
- n votes (as integers)

Output:
- Print candidate with highest votes
*/
#include <stdio.h>

void main() {

    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);


    int maxCount=0, winner;

    for(int i=0;i<n;i++){

        int count=0;

        for(int j=0;j<n;j++){
            if(arr[i]==arr[j])
                count++;
        }

        if(count>maxCount){
            maxCount=count;
            winner=arr[i];
        }
    }

    printf("%d",winner);
}
