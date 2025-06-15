// Bir dizideki tüm elemanların toplamını hesaplayın.

#include <vector>

int Sum(std::vector<int> input) {
	int sum = 0;
	for (int i : input) { // Go through each element and add them to the total sum.
		sum += i;
	}
	return sum;
}