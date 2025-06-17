// Bir dizinin tüm elemanlarını ekrana yazdıran bir fonksiyon yazın.

#include <vector>
#include <iostream>

void Log(std::vector<int> input) {
	for (int i : input) { // foreach loop prints all the items to screen.
		std::cout << i << ", ";
	}
}
