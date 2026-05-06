/*
day 73 - first non repeating character

Problem: Find the first non-repeating character in a string.

Input:
- String

Output:
- Print first non-repeating character
*/
#include <stdio.h>

void main() {

    char str[100];
    scanf("%s",str);

    int count[256]={0};


    for(int i=0;str[i]!='\0';i++)
        count[(int)str[i]]++;


    for(int i=0;str[i]!='\0';i++){
        if(count[(int)str[i]]==1){
            printf("%c",str[i]);
            return;
        }
    }

    printf("No Unique Character");
}
