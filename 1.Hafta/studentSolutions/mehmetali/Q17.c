// Kullanıcıdan alınan bir dizi için tüm alt dizileri (subarray) üretin.
#include <stdio.h>

void altlar(int a[], int n) {
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++) {
            printf("[");
            for (int k=i;k<=j;k++) printf("%d",a[k]);
            printf("]");
        }
    printf("\n");
}

int main() {
    int a[]={1,2,3};
    altlar(a,3);
    return 0;
}
