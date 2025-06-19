// Verilen bir dizide ardışık toplamı belirli bir sayıya eşit olan alt diziyi (subarray) bulun.

// Time complexity: O(n^2)

#include <iostream>

// ####################### This is the first version i wrote ################
/*
int FindSpecialSubArray(int input[], int size, int target, int output[]) {
	int i = 0;
	int m = 0;
	int length = 0;
	bool found = false;
	int currentSum = 0;

	while (i < size && !found) {
		currentSum = 0;
		for (int j = i; j < size; j++) {
			currentSum += input[j];
			if (currentSum == target) {
				found = true;
				for (int k = i; k < j + 1; k++) {
					output[m++] = input[k];
				}
				length = j - i + 1;
				break;
			}
		}
		i++;
	}
	return length;
}
*/

// #################### This is the prettified one :) #########################

int FindSpecialSubArray(int arr[], int n, int target, int out[]) {
	// Try each possible starting index
	for (int start = 0; start < n; ++start) {
		int sum = 0; // reset running sum for this start

		// Extend subarray from 'start' up to the end
		for (int end = start; end < n; ++end) {
			sum += arr[end]; // add current element to sum

			if (sum == target) {        // if we hit the target sum
				int len = end - start + 1;  // compute subarray length

				// copy the found subarray into out[]
				for (int k = 0; k < len; ++k) {
					out[k] = arr[start + k];
				}

				return len; // early exit with the length
			}
		}
		// if we finish the inner loop without return, move to next start
	}

	return 0;  // no matching subarray found
}

/*
int main() {

	int test[] = { 1, 2, 3, 4};
	int n = sizeof(test) / sizeof(test[0]);
	int target = 6;
	int output[100];

	int length = FindSpecialSubArray(test, n, target, output);

	for (int i = 0; i < length; i++) {
		std::cout << output[i] << ", ";
	}

}
*/