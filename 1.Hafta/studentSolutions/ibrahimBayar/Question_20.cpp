// Kullanıcıdan alından bir dizideki tüm elemanlar aynı sayıda tekrar ederken yalnızca 1 farklı sayıya sahip olan elemanı bulun.

#include <iostream>

int OddOneOut(int input[], int size) {
	int freq[size] = { 0 };
	int index[size] = { 0 };

	int x = 0;
	freq[x] = 1;
	// index[x] = 0;

	for (int i = 1; i < size; i++) {
		if (input[i] == input[i - 1]) {
			freq[x]++;
		}
		else {
			freq[++x]++;
			index[x] = i;
		}
	}
	
	for (int i = 1; i < x + 1; i++) {
		if (freq[i] != freq[i - 1]) {
			return input[index[i]];
		}
	}

	return -1;

}

int main() {
	int test[] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5};
	int n = sizeof(test) / sizeof(test[0]);

	std::cout << OddOneOut(test, n);

}