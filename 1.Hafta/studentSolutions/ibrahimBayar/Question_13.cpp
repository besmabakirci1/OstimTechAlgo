// Verilen bir dizide elemanların frekansını (kaç kez geçtiğini) bir sözlük şeklinde çıkarın.

// Time complexity: O(n+m)
// Space complexity: O(n+m)

#include <vector>

std::vector<int> GetFrequency(std::vector<int> input) { // O(n) space (passed by value)

	int max = 0; // O(m)

	for (int i = 0; i < input.size(); i++) {
		if (input[i] > max) max = input[i];
	}

	std::vector<int> freq(max+1, 0);

	for (int i = 0; i < input.size(); i++) {
		freq[input[i]]++;
	}
	return freq;
}