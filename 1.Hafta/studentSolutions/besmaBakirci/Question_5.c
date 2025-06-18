// Verilen bir dizideki çift sayıların ortalamasını hesaplayın.
///Çözüm yöntemim: verilen bir array olacak onun her elemanını gezip içindeki elemanların % ( modu ) == 0 ise çift değilse tek demesi ve çift olarak saptadığı elemanları bir array oluşturup onlara atayıp sonra elemanları toplayıp adete bölmeli sonrasında return 0 diyip kodu durdurması lazım. 

#include <stdio.h> 

int main(){
    int size = 5 ; 
    int even_numbers[size];
    int sum , even_count = 0 ; 
    double average;
    int arr [] = { 3, 4, 5, 6, 7}; 
    for (int i = 0 ; i < size ; i++){
        if (arr[i] % 2 == 0){
            even_numbers[even_count]= arr[i];
            sum += arr[i];
            even_count++;
        }
    }

    if (even_count > 0){
        average = (double) sum / even_count;
        printf("%.2f\n", average); 
    }

    return 0; 
}