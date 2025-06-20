// Verilen bir dizide yinelenen (duplicate) elemanları bulun.
#include <stdio.h>

void yinele(int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] == a[j]) { printf("%d ", a[i]); break; }
    printf("\n");
}

int main() {
    int a[] = {1,2,3,2,4,3,5};
    yinele(a,7);
    return 0;
}
