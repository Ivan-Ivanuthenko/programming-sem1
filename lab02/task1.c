#include <stdio.h>

int main(void)
{
    double xStart, xEnd, dX;

    printf("Enter Xstart: ");
    if (scanf("%lf", &xStart) != 1)
        return 1;

    printf("Enter Xend: ");
    if (scanf("%lf", &xEnd) != 1)
        return 1;

    printf("Enter dX: ");
    if (scanf("%lf", &dX) != 1)
        return 1;

    if (xStart >= xEnd || dX <= 0)
    {
        printf("Error: invalid input data.\n");
        return 1;
    }

    printf("\n+------------+--------------+\n");
    printf("|     X      |      Y       |\n");
    printf("+------------+--------------+\n");

    for (double x = xStart; x <= xEnd + dX * 1e-9; x += dX)
    {
        double y;

        if (x <= -1.0)
            y = x + 1.0;
        else if (x < 1.0)
            y = 1.0 - x * x;
        else
            y = x - 1.0;

        printf("| %10.2lf | %12.4lf |\n", x, y);
    }

    printf("+------------+--------------+\n");

    return 0;
}