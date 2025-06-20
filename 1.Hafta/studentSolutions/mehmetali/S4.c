// Merkezi fark yöntemiyle türevi hesaplayın.
#include <stdio.h>

void md(double x[], double y[], int n, double d[]) {
    double h = x[1] - x[0];
    d[0] = (y[1] - y[0]) / h;
    for (int i = 1; i < n-1; i++)
        d[i] = (y[i+1] - y[i-1]) / (2*h);
    d[n-1] = (y[n-1] - y[n-2]) / h;
}

int main() {
    double x[] = {0.5,1.5,2.5,3,3.5,4}, y[6], d[6];
    for (int i = 0; i < 6; i++)
        y[i] = 4*x[i]*x[i]*x[i] + 3*x[i]*x[i] + (4.0/3)*x[i] + 7;
    md(x, y, 6, d);
    for (int i = 0; i < 6; i++)
        printf("f'(%.1f) = %.3f\n", x[i], d[i]);
    return 0;
}
