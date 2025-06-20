// Kullanıcıdan alınan bir dizideki tüm elemanlar aynı sayıda tekrar ederken yalnızca 1 farklı sayıya sahip olan elemanı bulun.
#include <stdio.h>

int fark(int a[], int n) {
    int k[100], f[100];
    int u=0;
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<u;j++) if(k[j]==a[i]){ f[j]++; break; }
        if(j==u){ k[u]=a[i]; f[u++]=1; }
    }
    int c=f[0];
    for(int i=1;i<u;i++) if(f[i]<c) c=f[i];
    for(int i=0;i<u;i++) if(f[i]!=c) return k[i];
    return -1;
}

int main() {
    int a[]={5,5,6,6,6,5,5};
    printf("Farklı: %d\n", fark(a,7));
    return 0;
}
