// Sadece 0 ve 1'lerden oluşan bir dizide, maksimum ardışık 1 sayısını bulunuz.

#include <iostream>

int ConsecutiveOnes(int input[], int size) {
	int currentCount = 0;
	int maxCount = 0;

	for (int i = 0; i < size; i++) {
		if (input[i] == 1) {

			currentCount++;

			if (currentCount > maxCount) {
				maxCount = currentCount;
			}
		}
		else {
			currentCount = 0;
		}
	}
	return maxCount;
}

int main() {
	int test[] = { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0 , 1, 1, 0 };
	int n = sizeof(test) / sizeof(test[0]);

	std::cout << ConsecutiveOnes(test, n);

}