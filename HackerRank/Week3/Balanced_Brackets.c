#include <stdio.h>
#include <string.h>

#define MAX 1000  // maximum bracket string length

// Stack implementation
typedef struct {
    char arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0'; // invalid pop
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

// Function to check if brackets are balanced
const char* isBalanced(char *s) {
    Stack stack;
    init(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        } else {
            if (isEmpty(&stack)) return "NO"; // no matching open bracket

            char top = pop(&stack);
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return "NO";
            }
        }
    }

    if (isEmpty(&stack)) return "YES";
    else return "NO";
}

int main() {
    int n;
    scanf("%d", &n);

    char str[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        printf("%s\n", isBalanced(str));
    }

    return 0;
}
