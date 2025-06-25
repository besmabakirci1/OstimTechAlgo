// Scenario 4
// x = [0.5 1.5 2.5 3 3.5 4] ve f(x)= 4x^3 + 3x^2 + 4/3 x + 7 değerleri dizileri verilmiştir.
// Bir fonksiyona ait x ve f(x) değerleri dizisi verilmiştir. 
// Her x noktası için merkezi fark yöntemiyle türevi hesaplayınız.

#include <iostream>
#include <iomanip>

double function(double x) {
    return 4 * x * x * x + 3 * x * x + (4.0 / 3.0) * x + 7;
}

void FindDerivative(const double x[], const double fx[], int n, double dfdx[]) {
    for (int i = 1; i < n - 1; ++i) {
        dfdx[i] = (fx[i + 1] - fx[i - 1]) / (x[i + 1] - x[i - 1]);
    }
    dfdx[0] = dfdx[1];
    dfdx[n - 1] = dfdx[n - 2];
}

int main() {
    double x[] = { 0.5, 1.5, 2.5, 3.0, 3.5, 4.0 };
    int n = sizeof(x) / sizeof(x[0]);

    double fx[n], dfdx[n];
    for (int i = 0; i < n; ++i)
        fx[i] = function(x[i]);

    FindDerivative(x, fx, n, dfdx);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "   x       f'(x)\n";
    std::cout << "-------------------\n";
    for (int i = 0; i < n; ++i) {
        std::cout << std::setw(5) << x[i]
            << "   " << std::setw(10) << dfdx[i] << "\n";
    }
    return 0;
}
