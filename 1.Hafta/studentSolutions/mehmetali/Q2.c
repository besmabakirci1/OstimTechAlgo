// Bir dizinin tüm elemanlarını ekrana yazdıran bir fonksiyon yazın.
#include <stdio.h>

void yaz(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {3,7,4,6};
    yaz(a,4);
    return 0;
}
