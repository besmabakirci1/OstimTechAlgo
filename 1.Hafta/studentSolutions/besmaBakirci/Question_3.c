// 	Bir dizideki tüm elemanların toplamını hesaplayın.

#include <stdio.h>

void sumInt(int arr[], int n){
    int total = 0;  
    for (int i = 0 ; i < n ; i++){
        total += arr[i];
    }
    printf("The sum of array's elements: %d\n ", total);
}

int main(){
    int data[5] = {5,2,9,1,7};
    sumInt(data,5);
    return 0;
}
