
/* Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(head == NULL){
        return newNode;
    }

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void printList(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int i, n, value;
    struct Node* head = NULL;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    
    printList(head);

    return 0;
}
