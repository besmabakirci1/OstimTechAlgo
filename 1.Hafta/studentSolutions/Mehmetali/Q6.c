// Bir dizi verildiğinde, dizideki tüm elemanları ters çevirin.
#include <stdio.h>

void ters(int a[], int n) {
    for (int i = 0; i < n/2; i++) {
        int t = a[i]; a[i] = a[n-1-i]; a[n-1-i] = t;
    }
}

int main() {
    int a[] = {1,2,3,4,5};
    ters(a,5);
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    return 0;
}
