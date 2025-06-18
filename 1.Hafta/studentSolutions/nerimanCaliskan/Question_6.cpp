// Bir dizi verildiğinde, dizideki tüm elemanları ters çevirin (reverse).
/// Çözüm yöntemim : kullanıcıdan girdi alıp arrayin içine yazılan
///  ve ne kadar size var onu saptayıp sonrasında o size kadar for döngüsü olacak 
///  ve bu for döngüsü first in last out şeklinde yazılacak yani arrayin 0.
///  indeksi size 5 ise 4. indekse sahip olacak 

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> numbers(size);
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    reverseArray(numbers);

    cout << "Reversed array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}