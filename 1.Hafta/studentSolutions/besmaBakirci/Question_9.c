// Verilen bir dizide yalnızca bir kere geçen elemanları listeleyin.
#include <stdio.h>

int main(void){
    int n, j;
    printf("Please enter the size of array: "); 
    scanf("%d",&n);
    int arr[n];
   
    printf("Please enter the array's elements: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Unique Numbers:\n");
    for(int i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(arr[i] == arr[j] && i != j){
                break;
            }
        }
         if(j == n ){
        printf("%d\n", arr[i]);
        }
    }
    return 0;
}
