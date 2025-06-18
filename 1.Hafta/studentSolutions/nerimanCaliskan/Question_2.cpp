// Bir dizinin tüm elemanlarını ekrana yazdıran bir fonksiyon yazın.

#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {5, 2, 8, 1, 4};
    cout << "Array elements: ";
    printArray(numbers);
    return 0;
}
