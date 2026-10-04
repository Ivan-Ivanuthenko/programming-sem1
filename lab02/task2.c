#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100000

int main(void)
{
    double x, epsilon;

    printf("Enter X (-1 < X < 1): ");
    if (scanf("%lf", &x) != 1)
        return 1;

    printf("Enter epsilon: ");
    if (scanf("%lf", &epsilon) != 1)
        return 1;

    if (x <= -1.0 || x >= 1.0)
    {
        printf("Error: X is outside the convergence interval (-1, 1).\n");
        return 1;
    }

    if (epsilon <= 0.0)
    {
        printf("Error: epsilon must be greater than 0.\n");
        return 1;
    }

    int n = 1;
    int iterations = 0;

    double term = 1.0;
    double sum = 0.0;

    while (fabs(term) >= epsilon && iterations < MAX_ITERATIONS)
    {
        sum += term;
        iterations++;

        n++;
        term = term * ((double)n * x / (n - 1));
    }

    if (iterations >= MAX_ITERATIONS && fabs(term) >= epsilon)
    {
        printf("Warning: maximum number of iterations reached.\n");
    }

    double exact = 1.0 / ((1.0 - x) * (1.0 - x));
    double absoluteError = fabs(sum - exact);
    double relativeError = absoluteError / fabs(exact);

    printf("\nResults:\n");
    printf("X              = %.10lf\n", x);
    printf("Epsilon        = %.10e\n", epsilon);
    printf("Series sum     = %.10lf\n", sum);
    printf("Exact value    = %.10lf\n", exact);
    printf("Absolute error = %.10e\n", absoluteError);
    printf("Relative error = %.10e\n", relativeError);
    printf("Iterations     = %d\n", iterations);

    return 0;
}