// Kullanıcıdan alınan sıfırları sona alarak, diğer elemanların yerini değiştirmeden yeni bir dizi oluşturun.

#include <iostream>

void ZerosToEnd(int input[], int size, int output[]) {
	int j = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (input[i] != 0) {
			output[j++] = input[i];
		}
		else {
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		output[j++] = 0;
	}
}




int main() {
	int test[] = { 1, 0, 2, 0, 3, 0, 4, 0, 5 };
	int n = sizeof(test) / sizeof(test[0]);
	int output[100];

	ZerosToEnd(test, n, output);

	for (int i = 0; i < n; i++) {
		std::cout << output[i] << ", ";
	}

}