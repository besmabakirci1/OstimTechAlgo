// Bir dizideki elemanları döndürerek belirli bir sayıda sola veya sağa kaydırın.
#include <stdio.h>
#include <stdbool.h>

void kay(int a[], int n, int k, bool sola) {
    int t[100];
    for (int i=0;i<n;i++) t[i]=a[i];
    for (int i=0;i<n;i++){
        int d = sola?(i+k)%n:(i-k+n)%n;
        a[d]=t[i];
    }
}

int main() {
    int a[]={1,2,3,4,5};
    kay(a,5,2,true);
    for (int i=0;i<5;i++) printf("%d ",a[i]);
    return 0;
}
