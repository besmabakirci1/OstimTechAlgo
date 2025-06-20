// Sadece 0 ve 1'lerden oluşan bir dizide, maksimum ardışık 1 sayısını bulunuz.
#include <stdio.h>

int birler(int a[], int n) {
    int m=0,c=0;
    for (int i=0;i<n;i++){
        c = (a[i]==1)?c+1:0;
        if (c>m) m=c;
    }
    return m;
}

int main() {
    int a[]={1,1,0,1,1,1,0,1};
    printf("Max 1: %d\n", birler(a,8));
    return 0;
}
