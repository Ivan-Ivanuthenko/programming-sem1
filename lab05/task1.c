
#include <stdio.h>
#include <math.h>

int calculate_triangle(const double *a, const double *b,
                       double *c, double *p)
{
    if (a == NULL || b == NULL || c == NULL || p == NULL)
    {
        return 1;
    }

    if (!isfinite(*a) || !isfinite(*b) || *a <= 0 || *b <= 0)
    {
        return 1;
    }

    *c = sqrt((*a) * (*a) + (*b) * (*b));
    *p = *a + *b + *c;

    return 0;
}

int main(void)
{
    double a = 3.0;
    double b = 4.0;

    double c = 0.0;
    double p = 0.0;

    int result;

    result = calculate_triangle(&a, &b, &c, &p);

    if (result == 0)
    {
        printf("Cathetus A: %.2f\n", a);
        printf("Cathetus B: %.2f\n", b);
        printf("Hypotenuse C: %.2f\n", c);
        printf("Perimeter P: %.2f\n", p);
    }
    else
    {
        printf("Error: incorrect input data!\n");
    }

    return 0;
}
