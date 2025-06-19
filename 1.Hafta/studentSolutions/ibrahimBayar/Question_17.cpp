// Kullanıcıdan alınan bir dizi için tüm alt dizileri (subarray) üretin.

#include <iostream>

void GetAllSubArrays(int input[], int cols, int rows, int output[][]) {
	
}



int main() {
	int test[] = { 1, 2, 3, 4, 5 }; // 32 sub arrays?
	int n = sizeof(test) / sizeof(test[0]);
	int rows = 1 << n; // 2^5 ?
	int output[rows][n];
	for (int i = 0; i < rows; ++i) for (int j = 0; j < n; ++j) output[i][j] = -1;
}