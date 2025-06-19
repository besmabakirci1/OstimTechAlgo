//Bir dizideki elemanları döndürerek (rotate) belirli bir sayıda sola veya sağa kaydırın.

#include <iostream>

void RotateArray(int input[], int steps, int size, int output[]) {
	for (int i = 0; i < size; i++) {
		output[(steps + i) % size] = input[i];
	}
}

/*
int main() {
	int test[] = { 1, 2, 3, 4, 5, 6, 7};
	int steps = 60;
	int n = sizeof(test) / sizeof(test[0]);
	int output[100];
	RotateArray(test, steps, n, output);

	for (int i = 0; i < n; i++) {
		std::cout << output[i] << ", ";
	}
}
*/