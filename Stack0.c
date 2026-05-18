#include <stdio.h>
#define MAX 100

// Struktur stack
struct Stack {
    int arr[MAX];
    int top;
};

// Fungsi untuk menambah elemen ke stack
void push(struct Stack *s, int x) {
    if (s->top < MAX - 1) { 
        s->arr[++(s->top)] = x;// menaikkan indeks top
    }// jika stack belum penuh, posisi top akan diisi oleh nilai x yang dimasukkan
}

// Fungsi untuk mengambil elemen dari posisi atas stack
int pop(struct Stack *s) {
    if (s->top >= 0) { // stack tidak kosong
        return s->arr[(s->top)--]; // mengambil nilai pada indeks top, top diturunkan
    }
    return -1;// stack kosong
}

// Fungsi rekursif untuk menghapus elemen tengah
void deleteMiddle1(struct Stack *s, int currentIndex, int mid) {
    
    if (currentIndex == mid) {// posisi yang dibandinngkan untuk mencari nilai mid
        pop(s); // Hapus elemen tengah
        return;
    }

    // menyimpan elemen teratas yang dipop
    int currentTop = pop(s);

    // mengecek elemen pada indeks dibawahnya
    deleteMiddle1(s, currentIndex - 1, mid);

    // push kembali elemen yang disimpan di currentTop ke stack
    push(s, currentTop);
}

// Fungsi utama untuk menghapus elemen tengah
void deleteMiddle2(struct Stack *s) {
    int size = s->top + 1; // Menghitung ukuran stack
    if (size == 0) return;


    int targetIndex = (size + 1) / 2 - 1; // 

    // Panggil fungsi rekursif, dimulai dari index teratas (top)
    deleteMiddle1(s, s->top, targetIndex);
}

// Fungsi untuk mencetak stack dari top ke bottom
void printStack(struct Stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    s.top = -1; // memanggil stack kosong

    // menambahkan elemen ke stacl
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    printf("Stack awal (Top ke Bottom): ");
    printStack(s);

    // Hapus elemen tengah
    deleteMiddle2(&s);

    printf("Stack setelah elemen tengah dihapus (Top ke Bottom): ");
    printStack(s);

    return 0;
}