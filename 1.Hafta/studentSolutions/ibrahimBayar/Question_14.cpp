// Verilen bir dizideki ardışık olarak artan en uzun alt diziyi bulun.

#include <iostream>

int GetLongestIncreasingSubArray(int input[], int size, int output[]) {
	int currentLength = 1; // Length seen current moment
	int maxLength = 1; // Maximum length seen so far
	int currentIndex = 0; // The starting point of the current subArray
	int maxIndex = 0; // The starting point of the maximum lengthy subArray

	for (int i = 1; i < size; i++) {
		if (input[i] > input[i - 1]) {
			currentLength++; // If the current number is bigger then the previous one, increment the current length of the subarray.
		}
		else { // If that's not the case, means that the subarray is broken and we start to count again.
			currentLength = 1; 
			currentIndex = i;
		}
		if (currentLength > maxLength) { // After all checks, check if the current length is bigger than the maxLength.
			maxLength = currentLength;
			maxIndex = currentIndex;
		}
	}
	for (int i = 0; i < maxLength; i++) { // Save the results into the answer.
		output[i] = input[maxIndex + i];
	}
	return maxLength; // Also return the maxLenght.
}

/*
int main() {
	int test[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6};
	int n = sizeof(test) / sizeof(test[0]);

	int output[100];
	int length = GetLongestIncreasingSubArray(test, n, output);

	for (int i = 0; i < length; i++) {
		std::cout << output[i] << ", ";
	}
	std::cout << std::endl << length << std::endl;
}
*/