#include <stdio.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack; // struktur stack

void initStack(Stack *s) { 
    s->top = -1; 
}// inisialisasi stack

int isEmpty(Stack *s) {
    return s->top == -1; 
} // mengecek apakah stack kosong

void push(Stack *s, int value) { // menambah elemen ke puncak stack
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return; 
    }
    s->arr[++s->top] = value; // menaikkan indeks (top)
}

int pop(Stack *s) { 
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return s->arr[s->top--]; // indeks top  dikurangi 1
}

void deleteMiddle(Stack *s, int current, int middle) {
    if (isEmpty(s))
        return; // rekursi berhenti saat stack kosong

    int temp = pop(s); // elemen yang dipop disimpan sementara
    deleteMiddle(s, current + 1, middle);
    if (current != middle) {
        push(s, temp); // nilai yang diproses bukan middle, push lagi ke stack
    }
}
void display(Stack *s) { // menampilkan isi stack
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s; // membuat stack
    initStack(&s); // indeks top = -1

    push(&s, 10); // memasukkan elemen ke stack
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    int size = s.top + 1;
    int middle = (size / 2); // mencari nilai tengah

    deleteMiddle(&s, 0, middle); 
    printf("Stack setelah menghapus elemen tengah:\n");
    display(&s);

    return 0;
}
// if (!isEmpty(&s)) {
       // printf("Elemen top akhir: %d\n", s.arr[s.top]);
       // printf("Stack awal:\n"); display(&s);