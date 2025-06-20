// Bir dizideki tüm elemanların toplamını hesaplayın.
#include <stdio.h>

int toplam(int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s;
}

int main() {
    int a[] = {1,2,3,4};
    printf("Toplam: %d\n", toplam(a,4));
    return 0;
}
