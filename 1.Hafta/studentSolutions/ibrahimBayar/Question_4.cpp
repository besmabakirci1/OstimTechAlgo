// Bir dizide belirli bir sayının kaç kere geçtiğini bulun.

#include <vector>

int Reocurrance(int x, std::vector<int> input) {
	int count = 0;
	for (int i : input) {
		if (x == i) { // Every time we find value x increment the counter by 1.
			count++;
		}
	}
	return count;
}