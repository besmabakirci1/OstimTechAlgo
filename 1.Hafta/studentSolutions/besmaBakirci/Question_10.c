// İki sıralı diziyi birleştirip sıralı yeni bir dizi elde edin.
/// Çözüm Yöntemim: kullanıcıdan iki farklı dizi alınacak ve bunları birleştirip yeni bir dizi oluşturacağız sonra bu yeni dizinin elemanlarını sıralayacağız.
#include <stdio.h>
int main(void){
    int n1 , n2 ;
    printf("Please enter the size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];

    printf("Please enter the size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];

    int mergedArray[n1 + n2];

    printf("Please enter %d elements for first array:\n ", n1);
    for(int i = 0 ; i < n1; i++){
        scanf("%d", &arr1[n1]);
        mergedArray[i] = arr1[i];
    }
    
    printf("Please enter %d elements for second array:\n ", n2);
    for(int j = 0 ; j < n2; j++){
        scanf("%d", &arr2[j]);
        mergedArray[n1 + j] = arr2[j];
    }

    int n3 = n1 + n2;

    for (int pass = 0; pass < n3 - 1; pass++) {
        for (int k = 0; k < n3 - 1 - pass; k++) {
            if (mergedArray[k] > mergedArray[k + 1]) {
                int tmp = mergedArray[k];
                mergedArray[k] = mergedArray[k + 1];
                mergedArray[k + 1] = tmp;
            }
        }
    }

    printf("Merged and sorted array (%d elements):\n", n3);
    for (int i = 0; i < n3; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}

