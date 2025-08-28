#include <stdio.h>
#include <stdlib.h>

#define MAX 100000  // maximum size of stack

// stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1; // should never happen with valid input
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1;
}

// Queue using two stacks
Stack stack1, stack2;

void enqueue(int x) {
    push(&stack1, x);
}

void shiftStacks() {
    if (isEmpty(&stack2)) {
        while (!isEmpty(&stack1)) {
            push(&stack2, pop(&stack1));
        }
    }
}

void dequeue() {
    shiftStacks();
    pop(&stack2);
}

int front() {
    shiftStacks();
    return peek(&stack2);
}

int main() {
    int q;
    scanf("%d", &q);
    
    init(&stack1);
    init(&stack2);
    
    while (q--) {
        int type, x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            printf("%d\n", front());
        }
    }
    
    return 0;
}
