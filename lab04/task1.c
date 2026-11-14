#include <stdio.h>

double calculatePolynomial(double a, double b, double c, double x);

double calculatePolynomial(double a, double b, double c, double x)
{
    static int zeroCount = 0;

    double y = a * x * x + b * x + c;

    if (y == 0.0)
    {
        zeroCount++;
    }

    printf("Number of zero results: %d\n", zeroCount);

    return y;
}

int main(void)
{
    int n;

    double a, b, c, x, y;

    printf("Polynomial: Y = AX^2 + BX + C\n");
    printf("Enter number of calculations: ");

    if (scanf("%d", &n) != 1 || n <= 0 || n > 100)
    {
        printf("Invalid input!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nCalculation %d\n", i + 1);

        printf("Enter A: ");
        scanf("%lf", &a);

        printf("Enter B: ");
        scanf("%lf", &b);

        printf("Enter C: ");
        scanf("%lf", &c);

        printf("Enter X: ");
        scanf("%lf", &x);

        y = calculatePolynomial(a, b, c, x);

        printf("Result Y = %.2f\n", y);
    }

    return 0;
}