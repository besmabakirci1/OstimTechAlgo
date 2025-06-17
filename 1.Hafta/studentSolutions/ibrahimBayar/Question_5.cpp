// Verilen bir dizideki çift sayıların ortalamasını hesaplayın.

#include <vector>

int EvenSum(std::vector<int> input) {
	int sum = 0;
	for (int i : input) {
		if (i % 2 == 0) { // Add the value to the total sum if it's divisable by 2.
			sum += i;
		}
	}
	return sum;
}