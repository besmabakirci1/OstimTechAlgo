// Eksik (NaN) değerleri lineer enterpolasyonla doldur.
#include <stdio.h>
#include <math.h>

void doldur(double x[], int n) {
    for (int i = 0; i < n; i++) {
        if (isnan(x[i])) {
            int l = i-1, r = i+1;
            while (r < n && isnan(x[r])) r++;
            double y0 = x[l], y1 = x[r];
            for (int k = l+1; k < r; k++)
                x[k] = y0 + (y1 - y0) * ((k - l) / (double)(r - l));
            i = r;
        }
    }
}

int main() {
    double x[] = {1.0, NAN, NAN, 4.0, 5.0};
    int n = 5;
    doldur(x, n);
    for (int i = 0; i < n; i++) printf("%.2f ", x[i]);
    return 0;
}
