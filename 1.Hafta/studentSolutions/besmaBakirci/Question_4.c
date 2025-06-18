// Bir dizide belirli bir sayının kaç kere geçtiğini bulun.

#include <stdio.h>

int countOccurrences(int arr[], int n, int x) {
    int count = 0;              
    for (int i = 0; i < n; i++) { 
        if (arr[i] == x) {        
            count++;           
        }
    }
    return count;               
}

int main (){
    int n ;
    printf("Please enter the length of the array: ");
    scanf("%d", &n);
    int data[n];
    printf("Please enter %d integers separated by spaces:\n", n);   
    for (int i = 0 ; i < n ; i++){
        scanf("%d", & data[i]);
    } 
    int first = data[0];
    int occurrences = countOccurrences(data, n, first);
    printf("Dizinin ilk elemanı %d, toplamda %d kez geçiyor.\n",
        first, occurrences);

    return 0;
}
