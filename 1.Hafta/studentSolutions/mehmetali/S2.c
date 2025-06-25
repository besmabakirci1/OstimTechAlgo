// Newton ileri fark enterpolasyonuyla f(2.5) tahmini.
#include <stdio.h>

double nf(double x[], double y[], int n, double t) {
    double d[10][10];
    for (int i = 0; i < n; i++) d[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            d[i][j] = d[i+1][j-1] - d[i][j-1];
    double h = x[1] - x[0], p = (t - x[0]) / h, res = d[0][0], prod = 1;
    for (int i = 1; i < n; i++) {
        prod *= (p - (i - 1)) / i;
        res += prod * d[0][i];
    }
    return res;
}

int main() {
    double x[] = {0.5,1.5,2.5,3,3.5,4}, y[6];
    for (int i = 0; i < 6; i++)
        y[i] = 4*x[i]*x[i]*x[i] + 3*x[i]*x[i] + (4.0/3)*x[i] + 7;
    printf("f(2.5) ≈ %.5f\n", nf(x, y, 6, 2.5));
    return 0;
}
