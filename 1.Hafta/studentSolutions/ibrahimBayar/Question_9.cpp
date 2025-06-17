// Verilen bir dizide yalnızca bir kere geçen elemanları listeleyin.

//We could use an unordered map to count the frequencies of the items in the array than print the ones that only appear once on the screen, but this is the intiutive approach for beginners.

#include <vector>

std::vector<int> GetUniqueValues(const std::vector<int>& input) {
    std::vector<int> result;

    for (int i = 0; i < input.size(); ++i) {
        bool isDuplicate = false; // Our control variable

        for (int j = 0; j < input.size(); ++j) {
            if (i != j && input[i] == input[j]) { // i != j prevents checking the value with itself.
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) { // After every inner loop if we didn't find a duplicate that means the value is unique
            result.push_back(input[i]);
        }
    }

    return result;
}