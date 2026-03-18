
//Problem Statement:
//Implement a Queue using a linked list supporting enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue
int dequeue() {
    if (front == NULL) return -1;

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;

    if (front == NULL) rear = NULL;

    free(temp);
    return val;
}

int main() {
    int N, x;
    scanf("%d", &N);

    char op[10];

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') { // enqueue
            scanf("%d", &x);
            enqueue(x);
        }
        else if (op[0] == 'd') { // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
