// Linear Search for Minimum
// Time Complexity: O(n)
// Space Complexity: O(1)
// Bir tamsayı dizisi verildiğinde, dizideki en küçük elemanı bulun.

#include <iostream>
#include <vector>
using namespace std;


int findMinimum(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty." << endl;
        return -1; 
    }

    int min = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    vector<int> numbers = {5, 2, 8, 1, 4};
    int minimum = findMinimum(numbers);
    cout << "Minimum : " << minimum << endl;
    return 0;
}
