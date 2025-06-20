// Kullanıcıdan alınan bir dizinin palindrom olup olmadığını kontrol edin.
#include <stdio.h>
#include <stdbool.h>

bool pal(int a[], int n) {
    for (int i = 0; i < n/2; i++)
        if (a[i] != a[n-1-i]) return false;
    return true;
}

int main() {
    int a[] = {1,2,3,2,1};
    printf("Palindrom mu? %s\n", pal(a,5) ? "Evet":"Hayır");
    return 0;
}
