// Verilen bir dizide yalnızca bir kere geçen elemanları listeleyin.
#include <stdio.h>

void tekil(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) if (a[j] == a[i]) c++;
        if (c == 1) printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1,2,2,3,4,4,5};
    tekil(a,7);
    return 0;
}
