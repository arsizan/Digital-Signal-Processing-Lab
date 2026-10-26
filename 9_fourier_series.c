//fourier series
#include <stdio.h>
#include <math.h>
//ok
#define PI 3.14159265358979323846

// Midpoint rule for numerical integration
// This is the numerical equivalent of MATLAB's continuous 'int()' function
double integrate(double (*func)(double, int, double), int n, double w0, double a, double b) {
    int steps = 10000; // Number of subdivisions for accuracy
    double dt = (b - a) / steps;
    double sum = 0.0;
    
    for (int i = 0; i < steps; i++) {
        double t = a + i * dt + dt / 2.0; // midpoint of the current interval
        sum += func(t, n, w0) * dt;
    }
    return sum;
}

// Integrand for a0: f(t) = 1 in the interval [0, 1]
double integrand_a0(double t, int n, double w0) {
    return 1.0;
}

// Integrand for an: 1 * cos(n * w0 * t)
double integrand_an(double t, int n, double w0) {
    return 1.0 * cos(n * w0 * t);
}

// Integrand for bn: 1 * sin(n * w0 * t)
double integrand_bn(double t, int n, double w0) {
    return 1.0 * sin(n * w0 * t);
}

int main() {
    // Variable setup equivalent to the MATLAB script
    double w0 = PI;
    double T0 = 2.0;
    int n_max = 5;

    // 1. Calculate a0 = (1/T0) * int(1, t, 0, 1)
    double a0 = (1.0 / T0) * integrate(integrand_a0, 0, w0, 0.0, 1.0);
    printf("a0 =\n  %f\n\n", a0);

    // 2. Calculate an = (2/T0) * int(1*cos(n*w0*t), t, 0, 1)
    printf("an =\n  [ ");
    for (int n = 1; n <= n_max; n++) {
        double an = (2.0 / T0) * integrate(integrand_an, n, w0, 0.0, 1.0);
        
        // Snap very small floating-point rounding artifacts (e.g., 1e-16) to 0
        if (fabs(an) < 1e-10) an = 0.0;
        
        printf("%f ", an);
    }
    printf("]\n\n");

    // 3. Calculate bn = (2/T0) * int(1*sin(n*w0*t), t, 0, 1)
    printf("bn =\n  [ ");
    for (int n = 1; n <= n_max; n++) {
        double bn = (2.0 / T0) * integrate(integrand_bn, n, w0, 0.0, 1.0);
        
        // Snap very small floating-point rounding artifacts to 0
        if (fabs(bn) < 1e-10) bn = 0.0;
        
        printf("%f ", bn);
    }
    printf("]\n");

    return 0;
}


//fourier series
// #include <stdio.h>
// #include <math.h>

// #define PI 3.14159265358979323846
// #define STEPS 100000

// double w0 = PI;
// double T0 = 2.0;
// double t_start = 0.0;      /* integration limits */
// double t_end   = 1.0;

// /* ===== signal: change only this function ===== */
// double f(double t)
// {
//     return 1.0;
// }
// /* ============================================= */

// /* kind: 0 -> f(t),  1 -> f(t)cos(n w0 t),  2 -> f(t)sin(n w0 t) */
// double integrate(int kind, int n)
// {
//     double dt = (t_end - t_start) / STEPS;
//     double sum = 0.0;
//     int i;
//     for (i = 0; i < STEPS; i++)
//     {
//         double t = t_start + i*dt + dt/2.0;
//         double v = f(t);
//         if (kind == 1)      v = v * cos(n*w0*t);
//         else if (kind == 2) v = v * sin(n*w0*t);
//         sum += v * dt;
//     }
//     return sum;
// }

// int main()
// {
//     int n, n_max = 5;
//     double a0, an, bn;

//     a0 = (1.0/T0) * integrate(0, 0);
//     printf("a0 =\n  %f\n\n", a0);

//     printf("an =\n  [ ");
//     for (n = 1; n <= n_max; n++)
//     {
//         an = (2.0/T0) * integrate(1, n);
//         if (fabs(an) < 1e-6) an = 0.0;
//         printf("%f ", an);
//     }
//     printf("]\n\n");

//     printf("bn =\n  [ ");
//     for (n = 1; n <= n_max; n++)
//     {
//         bn = (2.0/T0) * integrate(2, n);
//         if (fabs(bn) < 1e-6) bn = 0.0;
//         printf("%f ", bn);
//     }
//     printf("]\n");

//     return 0;
// }