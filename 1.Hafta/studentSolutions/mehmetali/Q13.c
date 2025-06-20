// Verilen bir dizide elemanların frekansını bir sözlük şeklinde çıkarın.
#include <stdio.h>

int frek(int a[], int n, int k[], int f[]) {
    int u=0;
    for (int i=0;i<n;i++) {
        int j;
        for (j=0;j<u;j++) if (k[j]==a[i]){ f[j]++; break; }
        if (j==u) { k[u]=a[i]; f[u++]=1; }
    }
    return u;
}

int main() {
    int a[]={1,2,2,3,1,4,2}, k[7], f[7];
    int u=frek(a,7,k,f);
    for (int i=0;i<u;i++) printf("%d: %d\n", k[i], f[i]);
    return 0;
}
