#include <stdio.h>

void rotasiKalung(int arr[], int n, int k) {
    k = k % n;  //k = jumlah geser, n= jumlah mutiara
    printf("Hasil modifikasi kalung: ");

    for (int i = k; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int main() {
    int kalung[] = {4, 5, 1, 2, 3};
    int n = sizeof(kalung) / sizeof(kalung[0]); // Menghitung total mutiara (n = 5)
    int k = 2; // Jumlah pergeseran ke kiri

    printf("Kalung awal         : "); // menampilkan urutan kalung sebelum digeser
    for (int i = 0; i < n; i++) {
        printf("%d ", kalung[i]);
    }
    printf("\n");

    // memodifikasi urutan kalung
    rotasiKalung(kalung, n, k);

    return 0;
}