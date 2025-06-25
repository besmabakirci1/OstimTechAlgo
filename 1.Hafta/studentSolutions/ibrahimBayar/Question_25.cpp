// Scenario 5
// x = [0.5 1.5 2.5 3 3.5 4] ve f(x)= 4x^3 + 3x^2 + 4/3 x + 7 değerleri dizileri verilmiştir. 
// Verilen x ve f(x) değerleri ile a = x[0], b = x[-1] aralığında yaklaşık integrali hesaplayınız. 
// Aralık eşit bölünmüş olmalıdır (Simpson 1/3 kuralı uygulanabilir olmalı).

#include <iostream>

double function(double x) {
    return 4 * x * x * x + 3 * x * x + (4.0 / 3.0) * x + 7;
}

// Splits intervals between a...b in N equal parts and applies Composite Simpson Rule.
// N is even. ?

double FindIntegral(double a, double b, int N) {
    if (N % 2 != 0) ++N;
    double h = (b - a) / N;

    double sum = function(a) + function(b);

    for (int i = 1; i < N; ++i) {
        double xi = a + i * h;
        sum += (i % 2 == 0 ? 2 * function(xi) : 4 * function(xi));
    }
    return sum * (h / 3.0);
}

int main() {
    double x[] = { 0.5, 1.5, 2.5, 3.0, 3.5, 4.0 };
    int n = sizeof(x) / sizeof(x[0]);
    double a = x[0], b = x[n - 1];

    int N = n - 1; 
    double result = FindIntegral(a, b, N);

    std::cout << "Approx integral = " << result << std::endl;

    return 0;
}

// Will output 354.812 which is the correct approximation.