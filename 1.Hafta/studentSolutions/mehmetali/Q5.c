// Verilen bir dizideki çift sayıların ortalamasını hesaplayın.
#include <stdio.h>

double ortcift(int a[], int n) {
    int s = 0, c = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0) { s += a[i]; c++; }
    return c ? (double)s / c : 0;
}

int main() {
    int a[] = {1,2,3,4,5,6};
    printf("Çift ortalaması: %.2f\n", ortcift(a,6));
    return 0;
}
