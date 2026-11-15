#include <stdio.h>
#include <math.h>

int mySqrt(int x) {
    if (x == 0) return 0;

    double n = x;
    double epsilon = 0.000001;
    while (1) {
        double next = 0.5 * (n + x/n);
        if (fabs(next - n) < epsilon) {
            return next;
        }
        n = next;
    }
}
// Time to solve: 11min 7sec
// Learned the algorithm for sqrt and how it works under the hood, Newton-Raphson method