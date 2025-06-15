// Bir dizinin palindrom olup olmadığını kontrol edin

#include <vector>

bool IsPalindrom(std::vector<int> input) {
	
	int left = 0; //Left pointer
	int right = input.size() - 1; // Right pointer

	while (left < right) { // Loop until we reach middle

		if (input[left] != input[right]) { // If any of the left and right values don't match, it's not a palindrome.
			return false;
		}

		left++;
		right--;
	}
	return true;
}