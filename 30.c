
// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
};

int main(){
    
    struct node *head = NULL, *temp = NULL, *ptr = NULL;
    int n, i;

    printf("Enter number of terms = ");
    scanf("%d", &n);


    for(i = 0; i < n; i++){
        ptr = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent = ");
        scanf("%d %d", &ptr->coeff, &ptr->exp);

        ptr->next = NULL;

        if(head == NULL){
            head = ptr;
            temp = ptr;
        }else{
            temp->next = ptr;
            temp = ptr;
        }
    }

    temp = head;
    while(temp != NULL){
        if(temp->exp == 0){
            printf("%d", temp->coeff);
        }else if(temp->exp == 1){
            printf("%dx", temp->coeff);
        }else{
            printf("%dx^%d", temp->coeff, temp->exp);
        }if(temp->next != NULL){
            printf(" + ");
        }
        temp = temp->next;
    }

    return 0;
}
