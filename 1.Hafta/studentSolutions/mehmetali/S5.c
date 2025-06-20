// Simpson 1/3 kuralı ile yaklaşık integral hesaplayın.
#include <stdio.h>

double sim(double x[], double y[], int n) {
    double h = (x[n-1] - x[0]) / (n-1), s = y[0] + y[n-1];
    for (int i = 1; i < n-1; i++)
        s += (i % 2 ? 4*y[i] : 2*y[i]);
    return s * h / 3;
}

int main() {
    double x[] = {0.5,1.5,2.5,3,3.5,4}, y[6];
    for (int i = 0; i < 6; i++)
        y[i] = 4*x[i]*x[i]*x[i] + 3*x[i]*x[i] + (4.0/3)*x[i] + 7;
    printf("∫ f ≈ %.5f\n", sim(x, y, 6));
    return 0;
}
