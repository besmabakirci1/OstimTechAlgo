// Bir dizinin tüm elemanlarını ekrana yazdıran bir fonksiyon yazın.

#include <stdio.h>

void printArray(int arr[], int n){
    for( int i = 0 ; i < n ; i++){
        printf("%d\n", arr[i]); 
    }
}

int main(){
    int data[5] = {5,2,9,1,7};
    printArray(data,5);
    return 0;
}
