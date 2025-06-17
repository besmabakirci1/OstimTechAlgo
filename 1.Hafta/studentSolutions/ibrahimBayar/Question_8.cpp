// Verilen bir dizide yinelenen (duplicate) elemanları bulun

#include <vector>

// Marks the index locations of the values in input array. Exp: [1, 1, 2, 3] ----> [1, 1, 0, 0]
std::vector<bool> FlagRepeatedElements(std::vector<int> input) {

	std::vector<bool> isDuplicate( input.size(), false ); // We assume there is no repeated values in the array.

	for (int i = 0; i < input.size() - 1; i++) {

		if(!isDuplicate[i]) { // if it's already flagged as a repeated value we don't check it.

			for (int j = i + 1; j < input.size(); j++) {

				if (input[i] == input[j]) {
					isDuplicate[i] = true; // We mark the indexes
					isDuplicate[j] = true; // of the repeated values.
				}

			}

		}

	}
	return isDuplicate;
}

//-------------------------------------------------------------------------------
// Gives the unique values of repetitions: Exp: [1, 1, 1, 3, 4, 5, 5,] ----> [1, 5]

std::vector<int> GetUniqueRepeatedValues(std::vector<int> input) {

	std::vector<bool> isDuplicate(input.size(), false); // We assume there is no repeated values in the array.
	std::vector<int> ans;
	bool triggered = false;

	for (int i = 0; i < input.size() - 1; i++) {

		if (!isDuplicate[i]) {

			for (int j = i + 1; j < input.size(); j++) {

				if (input[i] == input[j]) {
					isDuplicate[j] = true; // We flag the value we find as duplicate

					if (!triggered) { // and we check if we already flagged some values in the inner loop.
						isDuplicate[i] = true; // the logic will only trigger this line if we find the value as a duplicate for the first time.
						ans.push_back(input[i]); // add the value into the answer.
						triggered = true; // And mark the loop as "trigerred at least once".
					}
				}
			}
		}
		triggered = false; // After each inner loop is done reset.
	}
	return ans;
}