// Verilen bir dizide ardışık toplamı belirli bir sayıya eşit olan alt diziyi bulun.
#include <stdio.h>
#include <stdbool.h>

bool alt(int a[], int n, int t, int *s, int *l) {
    for (int i=0;i<n;i++){
        int sm=0;
        for (int j=i;j<n;j++){
            sm+=a[j];
            if (sm==t){ *s=i; *l=j-i+1; return true; }
        }
    }
    return false;
}

int main() {
    int a[]={1,2,3,7,5}, s,l;
    if (alt(a,5,12,&s,&l)) printf("Baş:%d Uzun:%d\n",s,l);
    return 0;
}
