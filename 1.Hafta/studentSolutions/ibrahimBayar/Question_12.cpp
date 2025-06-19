// Verilen bir diziden negatif sayıları çıkarıp, sadece pozitifleri içeren yeni bir dizi oluşturun.

#include <vector>

std::vector<int> GetPositiveArray(std::vector<int> input) {
	std::vector<int> ans;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 0) {
			ans.push_back(input[i]);
		}
	}
	return ans;
}