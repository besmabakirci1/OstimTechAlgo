// Bir dizide en büyük ikinci elemanı bulun.
#include <stdio.h>

int ikibuy(int a[], int n) {
    int b1=a[0], b2=a[1];
    for (int i=2;i<n;i++) {
        if (a[i]>b1) { b2=b1; b1=a[i]; }
        else if (a[i]>b2) b2=a[i];
    }
    return b2;
}

int main() {
    int a[]={5,1,9,7,9,3};
    printf("2. en büyük: %d\n", ikibuy(a,6));
    return 0;
}
