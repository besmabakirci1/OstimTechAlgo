// Scenario 2
// Bir deneyden elde edilen x = [0.5 1.5 2.5 3 3.5 4] ve (f(x)= 4x^3+3x^2 + 4/3 x + 7(değerleri dizileri verilmiştir. 
// x = 2.5 noktasındaki değeri, Newton ileri fark enterpolasyonu ile tahmin ediniz.

#include <iostream>


double function(double x) {
    return 4 * x * x * x + 3 * x * x + (4.0 / 3.0) * x + 7;
}

int factorial(int x) {
    if (x <= 1) return 1;
    return x * factorial(x - 1);
}


double Mult_U(double u, int x) {
    if (x == 0) return u;
    else return (u - x) * Mult_U(u, x - 1);
}


double FindValue(double input[], int n, double fx[], double x) {

    double** diff = new double* [n];

    for (int i = 0; i < n; ++i) {
        diff[i] = new double[n];
        diff[i][0] = fx[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    double h = input[1] - input[0];
    double u = (x - input[0]) / h;

    // y = y0 + (u/1!)*dy0 + u * (u-1)/ 2! + ... 
    double ans = diff[0][0];

    for (int i = 1; i < n; i++) {
        ans += Mult_U(u, i - 1) / factorial(i) * diff[0][i];
    }

    for (int i = 0; i < n; ++i)
        delete[] diff[i];
    delete[] diff;

    return ans;
}


int main() {
    double x[] = { 0.5, 1.5, 2.5, 3.0, 3.5, 4.0 };
    int n = sizeof(x) / sizeof(x[0]);
    double fx[6];

    for (int i = 0; i < n; ++i)
        fx[i] = function(x[i]);

    double target = 2.5;
    double yhat = FindValue(x, n, fx, target);

    std::cout << "P(" << target << ") = " << yhat << "\n";
    return 0;
}

/* ############## optimised version.

            double function(double x) {
                return 4*x*x*x + 3*x*x + (4.0/3.0)*x + 7;
            }

            double newtonForward(const double x[], const double fx[], int n, double x0) {
                double h      = x[1] - x[0];
                double u      = (x0 - x[0]) / h;
                double result = fx[0];
                double u_term = 1.0;

                double* d = new double[n];
                for (int i = 0; i < n; ++i) 
                    d[i] = fx[i];

                for (int j = 1; j < n; ++j) {
                    // build the next level of forward differences in d[0..n-j-1]
                    for (int i = 0; i < n - j; ++i) {
                        d[i] = d[i+1] - d[i];
                    }
                    u_term *= (u - (j - 1)) / j;
                    result += u_term * d[0];
                }

                delete[] d;
                return result;
            }   
*/