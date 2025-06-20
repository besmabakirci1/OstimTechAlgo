// Bir tamsayı dizisi verildiğinde, dizideki en küçük elemanı bulun.

#include <stdio.h>

int min(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < m) m = a[i];
    return m;
}

int main() {
    int a[] = {5,2,8,1,9}, n = 5;
    printf("En küçük eleman: %d\n", min(a,n));
    return 0;
}
