// Negatifleri çıkarıp pozitifleri kopyalayın.
#include <stdio.h>

int poz(int a[], int n, int o[]) {
    int k=0;
    for (int i=0;i<n;i++) if (a[i]>=0) o[k++]=a[i];
    return k;
}

int main() {
    int a[]={-1,2,-3,4,5}, o[5];
    int m=poz(a,5,o);
    for (int i=0;i<m;i++) printf("%d ", o[i]);
    return 0;
}
