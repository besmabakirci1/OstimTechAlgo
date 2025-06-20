// İki sıralı diziyi birleştirip sıralı yeni bir dizi elde edin.
#include <stdio.h>

void birles(int a[], int na, int b[], int nb, int c[]) {
    int i=0,j=0,k=0;
    while (i<na && j<nb) c[k++] = (a[i]<b[j]?a[i++]:b[j++]);
    while (i<na) c[k++] = a[i++];
    while (j<nb) c[k++] = b[j++];
}

int main() {
    int a[]={1,3,5}, b[]={2,4,6}, c[6];
    birles(a,3,b,3,c);
    for (int i=0;i<6;i++) printf("%d ", c[i]);
    return 0;
}
