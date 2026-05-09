#include <stdio.h>

int main(){
 int n;
 int jumlah = 0; 
    
    printf("masukkan nilai n= ");
    scanf("%d", &n);

    for (int i=1; i<=n ; i++){
        jumlah += i;
    }
     printf("Hasil jumlahan hingga n = %d", jumlah); 
        return 0
} 