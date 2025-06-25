// Verilen bir dizide elemanların frekansını 
// (kaç kez geçtiğini) bir sözlük şeklinde çıkarın.
/// Çözüm Yöntemim: birinci elemana gelecek bunu geçici bir hafızaya atacak ve bununla diğer elemanlar eşit mi diye kontrol edecek ve bunu tüm elemanlar için yapacak ve bu işlem bittiğinde sözlük gibi şu sayıdan şu kadar var demesini beklememiz lazım 

#include <stdio.h>
#define SIZE 5
int main(void){
    int arr[SIZE] = {2, 2, 5, 9, 10};
    int unique[SIZE];
    int freq[SIZE];
    int count = 0, uniqueCount = 0;
    for(int i = 0 ; i < SIZE; i++){
        int current = arr[i];
        int alreadyCounted = 0;
        for(int j = 0; j < uniqueCount; j++){
            if(unique[j] == current){
                alreadyCounted = 1;
                break;
            }
        }
        if (alreadyCounted){
            continue;
        }
        
        for(int k = 0 ; k < SIZE; k++){
            if(arr[k] == current){
                count++;
            }
        }

        unique[uniqueCount] = current;
        freq[uniqueCount] = count;
        uniqueCount++; 
    }

    printf("Num : Frekans\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d: %d\n", unique[i], freq[i]);
    }

    return 0;
}