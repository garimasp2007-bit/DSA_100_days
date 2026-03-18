
// Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);

    // Push elements
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        pop();
    }

    // Print stack from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
