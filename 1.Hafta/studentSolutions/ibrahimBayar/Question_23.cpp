#include <iostream>
using namespace std;

// input[i][0] = x_i, input[i][1] = y_i
void LinearRegression(double input[][2], int n, double& a, double& b) {
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumXX = 0;

    for (int i = 0; i < n; ++i) {
        double xi = input[i][0];
        double yi = input[i][1];
        sumX += xi;
        sumY += yi;
        sumXY += xi * yi;
        sumXX += xi * xi;
    }

    // a = (n*Σ(xy) – Σx * Σy) / (n*Σ(x²) – (Σx)²)
    a = (n * sumXY - sumX * sumY)
        / (n * sumXX - sumX * sumX);

    // b = (Σy – a * Σx) / n
    b = (sumY - a * sumX) / n;
}

int main() {
    // Test data where true model is y = 2x + 1
    double test[][2] = {
        {3, 5},
        {2, 3},
        {1, 1},
        {0, -1}
    };

    int n = sizeof(test) / sizeof(test[0]);
    double a, b;
    LinearRegression(test, n, a, b);

    cout << "y = " << a << "x" << (b > 0 ? "+ " : "") << b << "\n";
    return 0;
}
