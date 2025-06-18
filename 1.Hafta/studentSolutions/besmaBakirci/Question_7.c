// Bir dizinin palindrom olup olmadığını kontrol edin
// - Palindrom dizi nedir ? : tersten okunuşu da düz okunuşu ile aynı olan dizidir.
/// Çözüm Yöntemim : Kullanıcıdan bir array alınır 
/// ve bu arrayin ilk ve son indeksleri i ve j değişkenleriyle işaretlenerek,
/// i < j koşulu altında arr[i] ve arr[j] elemanları karşılaştırılır; 
/// eğer eşit ise i bir sonraki elemana ve j bir önceki elemana kaydırılır;
/// döngü tamamlandığında tüm karşılaştırmalar sağlandıysa 
/// dizi palindrom kabul edilir.


#include <stdio.h>

int main(void) {
    int i = 0;              
    int size;               
    int palindrom = 1;      

    printf("Please enter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int j = size - 1;

    while (i < j) {
        if (arr[i] != arr[j]) {
            palindrom = 0;  
            break;
        }
        i++;  
        j--; 
    }

    if (palindrom) {
        printf("The array is a palindrome.\n");
    } else {
        printf("The array isn't a palindrome.\n");
    }

    return 0;
}
