// Bir tamsayı dizisi verildiğinde, dizideki en küçük elemanı bulun.

#include <vector>

int findMin(std::vector<int> input) {
	int min = input[0]; // Start by assuming the first item is the smallest.
	for (int i = 0; i < input.size() - 1; i++) { // Loop until we reach the end.
		if (input[i] > input[i + 1]) { // If the next item is smaller that is the current smallest item we know of.
			min = input[i + 1];
		}
	}
	return min;
}