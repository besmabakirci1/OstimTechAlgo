// İki sıralı diziyi birleştirip sıralı yeni bir dizi elde edin.

#include <vector>

std::vector<int> MergeSortedArrays(std::vector<int> a, std::vector<int> b) {
	std::vector<int> ans;
	int i = 0; // pointer for array a
	int j = 0; // pointer for array b

	while (i < a.size() && j < b.size()) { // Continue looping until we reach one of the array's end.
		ans.push_back(a[i] < b[j] ? a[i++] : b[j++]); /* if a[i] is smaller than b[j] add a[i] to ans and increment i,
													    if b[j] is smaller than or equal to a[j] add b[j] to ans and increment j. */
	}

	ans.insert(ans.end(), a.begin() + i, a.end()); // if we didn't reach the end of the array a, we append the rest of the a to ans.
	ans.insert(ans.end(), b.begin() + j, b.end());// if we didn't reach the end of the array b, we append the rest of the b to ans.

	return ans;
}