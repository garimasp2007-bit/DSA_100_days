
// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
# include <stdio.h>
# include <string.h>
int main(){
    char temp;
    char word[100];
    scanf("%s",word);
    int length=strlen(word);
    for(int i=length-1;i>=0;i--){
        printf("%c",word[i]);
    }
    return 0;
}
