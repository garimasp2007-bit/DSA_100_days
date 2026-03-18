
//Problem: Deque (Double-Ended Queue)
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// push_front
void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
int pop_front() {
    if (isEmpty()) return -1;

    int val = deque[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return val;
}

// pop_back
int pop_back() {
    if (isEmpty()) return -1;

    int val = deque[rear];

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }

    return val;
}

// front element
int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

// rear element
int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

// size
int size() {
    if (isEmpty()) return 0;
    return (rear - front + MAX) % MAX + 1;
}

// display
void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    // Example usage
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();           // 5 10 20 30

    printf("%d\n", pop_front()); // 5
    printf("%d\n", pop_back());  // 30

    display();           // 10 20

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    return 0;
}
