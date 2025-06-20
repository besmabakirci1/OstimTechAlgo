// Verilen bir dizideki ardışık olarak artan en uzun alt diziyi bulun.
#include <stdio.h>

int uzun(int a[], int n) {
    int m=1,c=1;
    for (int i=1;i<n;i++) {
        c = (a[i]>a[i-1]?c+1:1);
        if (c>m) m=c;
    }
    return m;
}

int main() {
    int a[]={1,2,2,3,4,5,1};
    printf("Uzunluk: %d\n", uzun(a,7));
    return 0;
}
