// Scenario 1
// Kullanıcıdan alınan sensör verisi dizisinde bazı değerler eksik (None olarak verilmiş). Eksik olan verileri, komşu iki değer arasında doğrusal enterpolasyon yöntemiyle hesaplayarak doldurunuz.

#include <iostream>

constexpr double MISSING = -1.0;

void FillArray(double input[], int n) {
    for (int i = 0; i < n; i++) {

        if (input[i] == MISSING) {
            int left = i - 1;
            int right = i + 1;

            while (left >= 0 && input[left] == MISSING) {
                left--;
            }
            while (right < n && input[right] == MISSING) {
                right++;
            }

            if (left >= 0 && right < n) {
                input[i] = input[left] + (input[right] - input[left]) * (double)(i - left) / (right - left);

            }
            else {
                // We can't fill the missing value.
            }
        }
    }
}


int main() {
    constexpr int N = 8;
    double test[N] = {
        1.0,
        MISSING,  // missing
        2.5,
        3.0,
        MISSING,  // missing
        MISSING,  // missing
        5.5,
        6.0
    };

    FillArray(test, N);

    for (int i = 0; i < N; ++i) {
        std::cout << test[i] << ", ";
    }

    return 0;
}