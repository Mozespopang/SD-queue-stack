#include <stdio.h>
#define MAX 10

typedef struct { // membentuk struktur queue
    int data[MAX];
    int front;
    int rear;
} Queue; 

void initQueue(Queue *q) { // pointer q untuk mengakses strutur queue
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue *q) { // kondisi queue kosong
    return q->front > q->rear;
}
void enqueue(Queue *q, int value) { // elemen baru dimasukkan ke queue
    q->rear++; // posisi rear naik 1
    q->data[q->rear] = value; // menyimpan value pada posisi tersebut
}
int dequeue(Queue *q) { // menghapus data dari front
    int value = q->data[q->front]; // mengambil nilai front
    q->front++; // posisi front digeser ke indeks berikutnya 
    return value; // mengembalikan nilai yang di dequeue
}

int main() {
    int n, k;// n = jumlah elemen yang dimasukkan, k = jumlah geser
    Queue q;
    printf("Masukkan jumlah pearl (spasi) jumlah geser\n");
    scanf("%d %d", &n, &k);
    initQueue(&q);

    for (int i = 0; i < n; i++) { // melakukan loop sebanyak n untuk membaca nilai pearl
        int pearl;
        scanf("%d", &pearl);
        enqueue(&q, pearl); // memasukkan elemen ke queue
    }
    for (int i = 0; i < k; i++) { // loop sebanyak k kali
        int temp = dequeue(&q); // elemen yang di dequeue disimpan ke temp
        enqueue(&q, temp); // elemen di temp kembali dimasukkan ke rear queue
    }
    while (!isEmpty(&q)) { // selama queue belum kosong elemen dikeluarkan dengan dequeue
        printf("%d ", dequeue(&q));
    }
    return 0;
}