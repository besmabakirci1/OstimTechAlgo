// Kullanıcıdan alınan sıfırları sona alarak, diğer elemanların yerini değiştirmeden yeni bir dizi oluşturun.
#include <stdio.h>

void sifirsona(int a[], int n) {
    int p=0;
    for (int i=0;i<n;i++) if(a[i]!=0) a[p++]=a[i];
    while(p<n) a[p++]=0;
}

int main() {
    int a[]={0,1,0,3,12};
    sifirsona(a,5);
    for (int i=0;i<5;i++) printf("%d ",a[i]);
    return 0;
}
