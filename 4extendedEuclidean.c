#include <stdio.h>

// Function to find the extended GCD (greatest common divisor) using Extended Euclidean algorithm
int extendedEuclidean(int a, int b, int *x, int *y) {
    // Base case
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    // Recursive call
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int x, y;
    int gcd = extendedEuclidean(num1, num2, &x, &y);

    printf("Extended GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("Coefficients (x, y) are: (%d, %d)\n", x, y);

    return 0;
}
