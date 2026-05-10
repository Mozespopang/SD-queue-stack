#include <stdio.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void deleteMiddle(Stack *s, int current, int middle) {
    if (isEmpty(s))
        return;

    int temp = pop(s);
    deleteMiddle(s, current + 1, middle);
    if (current != middle) {
        push(s, temp);
    }
}
void display(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    int size = s.top + 1;
    int middle = (size / 2);

    deleteMiddle(&s, 0, middle);
    printf("Stack setelah menghapus elemen tengah:\n");
    display(&s);

    return 0;
}