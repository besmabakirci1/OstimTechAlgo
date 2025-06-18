// 	Bir dizideki tüm elemanların toplamını hesaplayın.

#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int>& arr){
    int total=0;
    for(int i=0; arr.size();i++){
        total+=arr[i];
    }
    return total;
}

int main() {
    vector<int> numbers = {5, 2, 8, 1, 4};
    int sum = sumArray(numbers);
    cout << "Sum of elements: " << sum << endl;
    return 0;
}