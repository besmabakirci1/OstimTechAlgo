// Bir dizi verildiğinde, dizideki tüm elemanları ters çevirin (reverse).
/// Çözüm yöntemim : kullanıcıdan girdi alıp arrayin içine yazılan
///  ve ne kadar size var onu saptayıp sonrasında o size kadar for döngüsü olacak 
///  ve bu for döngüsü first in last out şeklinde yazılacak yani arrayin 0.
///  indeksi size 5 ise 4. indekse sahip olacak 

#include <stdio.h> 

int main(){
    int size ;

    printf("Please enter the size of array : ");
    scanf("%d", &size);

    int arr[size];

    for(int i = 0; i < size ; i++) {
        printf("Please enter element %d: ", i +1 );
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < (size / 2) ; i++){
    int temporary = arr[i];
    arr[i] = arr[(size-1)-i];
    arr[(size-1)-i] = temporary;
    }

    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
} 
