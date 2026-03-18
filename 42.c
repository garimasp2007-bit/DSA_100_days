
//Problem Statement:
//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

int main() {
    int N, x;
    scanf("%d", &N);

    // Input queue
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    for (int i = 0; i < N; i++) {
        push(dequeue());
    }

    // Reset queue pointers
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    for (int i = 0; i < N; i++) {
        enqueue(pop());
    }

    // Output reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
