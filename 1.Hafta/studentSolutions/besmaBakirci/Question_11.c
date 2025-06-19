// Bir dizide en büyük ikinci elemanı bulun.
/// Çözüm Yöntemim: sabit bir dizi verilecek bu dizi içinde dönüp sortlayacağız ve daha sonrasında en büyük olana biggest diyeceğiz ve en büyük ikinci eleman da biggestin indexinden -1 olmuş olacak 
#include <stdio.h>
#define SIZE 5
int main(void){
    int arr[SIZE] = {12, 4, 5 ,9 ,10};

    for(int = 0 ; i < SIZE -1 ; i++){
        for(int j = 0; j < SIZE-1-i ; j++){
            if(arr[j] > arr[j+1]){
                int temporary = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temporary;
            }
        }
    }
    
    int biggest= arr[SIZE-1];
    int secondBiggest = arr[SIZE - 2];

    printf("The sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The biggest elemant: %d\n", biggest);
    printf("The second biggest elemant: %d\n", secondBiggest);

    return 0;

}