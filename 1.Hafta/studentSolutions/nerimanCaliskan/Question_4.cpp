// Bir dizide belirli bir sayının kaç kere geçtiğini bulun.
#include <iostream>
#include <vector>
using namespace std;

int countOccurrences(const vector<int>& arr, int target) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> numbers = {5, 2, 8, 2, 4, 2, 1};
    int targetNumber = 2;
    int frequency = countOccurrences(numbers, targetNumber);
    cout << "Number " << targetNumber << " appears " << frequency << " times in the array." << endl;
    return 0;
}
