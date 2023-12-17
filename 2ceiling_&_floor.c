#include <stdio.h>

double myCeil(double num) {
    int intPart = (int)num; // Get the integer part of the number
    double result = (num > intPart) ? intPart + 1 : num; // If there is a fractional part, round up
    return result;
}

double myFloor(double num) {
    int intPart = (int)num; // Get the integer part of the number
    double result = (num < intPart) ? intPart - 1 : num; // If there is a fractional part, round down
    return result;
}

int main() {
    double num;

    // Input a number
    printf("Enter a floating-point number: ");
    scanf("%lf", &num);

    // Calculate and display the custom ceil and floor values
    printf("Custom Ceil value: %.2f\n", myCeil(num));
    printf("Custom Floor value: %.2f\n", myFloor(num));

    return 0;
}
