// Verilen bir diziden negatif sayıları çıkarıp, 
// sadece pozitifleri içeren yeni bir dizi oluşturun.
#include <stdio.h>
#define SIZE 5

int main(void){
    int arr[SIZE] = {-12, -4, 5 ,9 ,10};
    int positiveArr[SIZE];
    int positiveCount = 0;


    for(int i = 0; i < SIZE; i++){
        if (arr[i] > 0 ){
            positiveArr[positiveCount] = arr[i];
            positiveCount++;
        }
    }

    printf("Positive NUmbers %d: ", positiveCount);
    for(int i = 0; i < positiveCount; i++){
        printf("\n %d", positiveArr[i]);
    }

    return 0;
 }