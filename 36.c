
//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include<stdio.h>
#define MAX 100
typedef struct{
    int arr[MAX];
    int front;
    int rear;
    int size;
} CircularQueue;

void enqueue(CircularQueue *q, int value){
    if(q->size == MAX){
        printf("Queue Overflow\n");
        return;
    }

    if(q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    q->size++;
}

void dequeue(CircularQueue *q){
    if(q->size == 0){
        printf("Queue Underflow\n");
        return;
    }

    q->front = (q->front + 1) % MAX;
    q->size--;
}

void display(CircularQueue *q){
    int i = q->front;

    while(i != q->rear){
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }

    printf("%d", q->arr[q->rear]);
}

int main(){
    int n, m, x;

    CircularQueue q;
    q.front = -1;
    q.rear = -1;
    q.size = 0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(&q,x);
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++){
        dequeue(&q);
    }

    display(&q);

    return 0;
}
