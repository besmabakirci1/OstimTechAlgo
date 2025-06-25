// Bir dizide belirli bir sayının kaç kere geçtiğini bulun.
#include <stdio.h>

int say(int a[], int n, int x) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x) c++;
    return c;
}

int main() {
    int a[] = {1,2,3,2,4,2};
    printf("2 sayısı %d kez geçti\n", say(a,6,2));
    return 0;
}
