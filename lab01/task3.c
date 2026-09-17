#include <stdio.h>

int main(void) {
    double TC, TF, TK;

    printf("Enter temperature in Celsius (C): ");

    if (scanf("%lf", &TC) != 1) {
        printf("Error: please enter a valid number.\n");
        return 1;
    }

    TF = TC * 9.0 / 5.0 + 32.0;
    TK = TC + 273.15;

    if (TK < 0) {
        printf("Error: temperature cannot be below absolute zero.\n");
        return 1;
    }

    printf("\nTemperature in Fahrenheit: %.2f F\n", TF);
    printf("Temperature in Kelvin: %.2f K\n", TK);

    return 0;
}