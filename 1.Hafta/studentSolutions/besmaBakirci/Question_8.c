// Verilen bir dizide yinelenen (duplicate) elemanları bulun
/// Çözüm Yöntemim: kullanıcıdan bir dize alınır ve 
// birinci indexteki eleman tutularak tüm dizideki elemanlar ile eşit olup olmadığı karşılaştırılır ve 
// sonuç itibarı ile bu tüm elemanlar için tekrar edilir ve sonunda dublicate sayılar yazılır 

#include <stdio.h>

int main(void){
    int n ;
    printf("Please enter the size of array: "); 
    scanf("%d",&n);
    int arr[n];

    printf("Please enter the array's elements: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Duplicate Numbers:\n");

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                printf("%d\n", arr[i]);
                break;
            }
        }
    }
    return 0;
}
