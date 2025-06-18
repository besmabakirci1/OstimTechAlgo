// Verilen bir dizideki çift sayıların ortalamasını hesaplayın.
///Çözüm yöntemim: verilen bir array olacak onun her elemanını gezip içindeki elemanların % ( modu ) == 0 ise çift değilse tek demesi ve çift olarak saptadığı elemanları bir array oluşturup onlara atayıp sonra elemanları toplayıp adete bölmeli sonrasında return 0 diyip kodu durdurması lazım. 

#include <iostream>
#include <vector>
using namespace std;

double averageOfEvens(const vector<int>& arr) {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) { 
            sum += arr[i];  
            count++;         
        }
    }

    if (count == 0) {
        cout << "No even numbers in the array." << endl;
        return 0.0; 
    }

    return static_cast<double>(sum) / count;
}

int main() {
    vector<int> numbers = {1, 4, 6, 3, 7, 8};
    double avg = averageOfEvens(numbers);
    cout << "Average of even numbers: " << avg << endl;
    return 0;
}
