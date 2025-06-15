// Bir dizi verildiğinde, dizideki tüm elemanları ters çevirin (reverse).

#include <vector>

void Reverse(std::vector<int>& input) {

	int left = 0;  // Left pointer
	int right = input.size() - 1; //Right pointer
	int buffer = 0;

	while (left < right) { // Until we reach the middle we loop.

		buffer = input[left];      //    
		input[left] = input[right];//    Swap the values.
		input[right] = buffer;     //       

		left++;    // Increment or decrement the pointers.
		right--;
	}
}