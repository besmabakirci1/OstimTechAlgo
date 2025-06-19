//	11	Bir dizide en büyük ikinci elemanı bulun.

#include <vector>

int SecondLargestNumber(std::vector<int> input) {
	int first = -1; // -1 means There was less than 2 members.
	int second = -1;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] > first) {
			second = first;
			first = input[i];
		}
	}
	return second;
}