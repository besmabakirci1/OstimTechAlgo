// Kullanıcıdan alınan bir dizi için tüm alt dizileri (subarray) üretin.

// if the input array has "-1" in them this won't work. There should be a better solution.

#include <iostream>

const int N = 5;   // max input size

void GetAllSubArrays(int input[], int n, int output[][N]) {
    // Compute total number of subsets = 2^n
    int rows = 1 << n; // bitshifts n times. --> decimal "1" = binary "00000001" --> bitshift 2 times: "00000100" = 4

    // For each bitmask from 0 to 2^n−1 for this case 0 - 31
    for (int mask = 0; mask < rows; ++mask) {
        int idx = 0;  // write position in output[mask]

        // Check each bit j of mask
        for (int j = 0; j < n; ++j) {
            // if bit j is set, include input[j]
            if (mask & (1 << j)) { // Bitwise "and"
                output[mask][idx++] = input[j];
            }
        }

        // Fill remaining slots with -1 to mark “no element”
        for (int k = idx; k < n; ++k) {
            output[mask][k] = -1;
        }
        /*
            * after the loops the output array looks like:
            *
            *    { -1, -1, -1, -1, -1 }, // mask=00000 -> {}
            *    {  1, -1, -1, -1, -1 }, // mask=00001 -> {1}
            *    {  2, -1, -1, -1, -1 }, // mask=00010 -> {2}
            *    {  1,  2, -1, -1, -1 }, // mask=00011 -> {1,2}
            *    {  3, -1, -1, -1, -1 }, // mask=00100 -> {3}
            *    {  1,  3, -1, -1, -1 }, // mask=00101 -> {1,3}
            *    {  2,  3, -1, -1, -1 }, // mask=00110 -> {2,3}
            *    {  1,  2,  3, -1, -1 }, // mask=00111 -> {1,2,3}
            *    {  4, -1, -1, -1, -1 }, // mask=01000 -> {4}
            *    {  1,  4, -1, -1, -1 }, // mask=01001 -> {1,4}
            *    {  2,  4, -1, -1, -1 }, // mask=01010 -> {2,4}
            *    {  1,  2,  4, -1, -1 }, // mask=01011 -> {1,2,4}
            *    {  3,  4, -1, -1, -1 }, // mask=01100 -> {3,4}
            *    {  1,  3,  4, -1, -1 }, // mask=01101 -> {1,3,4}
            *    {  2,  3,  4, -1, -1 }, // mask=01110 -> {2,3,4}
            *    {  1,  2,  3,  4, -1 }, // mask=01111 -> {1,2,3,4}
            *    {  5, -1, -1, -1, -1 }, // mask=10000 -> {5}
            *    {  1,  5, -1, -1, -1 }, // mask=10001 -> {1,5}
            *    {  2,  5, -1, -1, -1 }, // mask=10010 -> {2,5}
            *    {  1,  2,  5, -1, -1 }, // mask=10011 -> {1,2,5}
            *    {  3,  5, -1, -1, -1 }, // mask=10100 -> {3,5}
            *    {  1,  3,  5, -1, -1 }, // mask=10101 -> {1,3,5}
            *    {  2,  3,  5, -1, -1 }, // mask=10110 -> {2,3,5}
            *    {  1,  2,  3,  5, -1 }, // mask=10111 -> {1,2,3,5}
            *    {  4,  5, -1, -1, -1 }, // mask=11000 -> {4,5}
            *    {  1,  4,  5, -1, -1 }, // mask=11001 -> {1,4,5}
            *    {  2,  4,  5, -1, -1 }, // mask=11010 -> {2,4,5}
            *    {  1,  2,  4,  5, -1 }, // mask=11011 -> {1,2,4,5}
            *    {  3,  4,  5, -1, -1 }, // mask=11100 -> {3,4,5}
            *    {  1,  3,  4,  5, -1 }, // mask=11101 -> {1,3,4,5}
            *    {  2,  3,  4,  5, -1 }, // mask=11110 -> {2,3,4,5}
            *    {  1,  2,  3,  4,  5 }  // mask=11111 -> {1,2,3,4,5}
        */
    }
}

int main() {

    int test[N] = { 1, 2, 3, 4, 5};
    int n = sizeof(test) / sizeof(test[0]);
    int rows = 1 << n;
    int output[1 << N][N];

    GetAllSubArrays(test, n, output);

    // print them
    for (int i = 0; i < rows; ++i) {
        std::cout << "{ ";
        for (int j = 0; j < n; ++j) {
            if (output[i][j] != -1)
                std::cout << output[i][j] << " ";
        }
        std::cout << "}\n";
    }

    return 0;
}
