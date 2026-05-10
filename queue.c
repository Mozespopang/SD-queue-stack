#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return q->front > q->rear;
}
void enqueue(Queue *q, int value) {
    q->rear++;
    q->data[q->rear] = value;
}
int dequeue(Queue *q) {
    int value = q->data[q->front];
    q->front++;
    return value;
}

int main() {
    int n, k;
    Queue q;
    scanf("%d %d", &n, &k);
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        int pearl;
        scanf("%d", &pearl);
        enqueue(&q, pearl);
    }
    for (int i = 0; i < k; i++) {
        int temp = dequeue(&q);
        enqueue(&q, temp);
    }
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }
    return 0;
}