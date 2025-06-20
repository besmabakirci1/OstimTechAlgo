// En küçük karelerle ax + b fonksiyonu bulun.
#include <stdio.h>

void ls(double x[], double y[], int n, double *a, double *b) {
    double sx=0, sy=0, sxy=0, sxx=0;
    for (int i = 0; i < n; i++) {
        sx += x[i];  sy += y[i];
        sxy += x[i]*y[i];  sxx += x[i]*x[i];
    }
    *a = (n*sxy - sx*sy) / (n*sxx - sx*sx);
    *b = (sy - (*a)*sx) / n;
}

int main() {
    double x[] = {1,2,3,4}, y[] = {2,3,5,7}, a, b;
    ls(x, y, 4, &a, &b);
    printf("f(x) = %.2fx + %.2f\n", a, b);
    return 0;
}
