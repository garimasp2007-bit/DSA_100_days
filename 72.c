/*
day 72 - first repeated character

Problem: Find the first repeated character in a string.

Input:
- String

Output:
- Print first repeated character
*/
#include <stdio.h>

void main() {

    char str[100];
    scanf("%s",str);

    int count[256]={0};


    for(int i=0;str[i]!='\0';i++){

        if(count[(int)str[i]]==1){
            printf("%c",str[i]);
            return;
        }

        count[(int)str[i]]++;
    }

    printf("No Repetition");
}
