
//Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int n){
    struct Node *temp, *newnode;
    int x;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        }else{
            temp->next = newnode;
            temp = newnode;
        }
    }
}


void rotateRight(int k){
    
    if(head == NULL || head->next == NULL){
        return;
    }

    struct Node *temp = head;
    int n = 1;

    while(temp->next != NULL){
        temp = temp->next;
        n++;
    }

    temp->next = head;
    k = k % n;

    int steps = n - k;

    struct Node *newLast = head;

    for(int i = 1; i < steps; i++)
        newLast = newLast->next;

    head = newLast->next;

    newLast->next = NULL;
}

void display(){
    struct Node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    
    int n, k;

    scanf("%d", &n);

    create(n);

    scanf("%d", &k);

    rotateRight(k);

    display();

    return 0;
}
