#include <stdio.h>

int add(int a, int b) {
    int carry = 0, result = 0, bit, base = 1;

    while (a > 0 || b > 0 || carry) {
        int bitA = a % 10;
        int bitB = b % 10;
        int sum = bitA + bitB + carry;
        bit = sum % 2;
        carry = sum / 2;
        result = result + bit * base;
        base *= 10;
        a /= 10;
        b /= 10;
    }

    return result;
}

int multiply(int a, int b) {
    int result = 0, base = 1;

    while (b > 0) {
        int bitB = b % 10;
        if (bitB == 1) {
            result = add(result, a * base);
        }
        base *= 10;
        b /= 10;
    }

    return result;
}

// int divide(int a, int b) {
//     int quotient = 0, remainder = 0, base = 1;

//     while (a > 0) {
//         remainder = add(remainder, (a % 10) * base);
//         a /= 10;
//         int div = 0;
//         while (remainder >= b) {
//             remainder = add(remainder, b);
//             div = add(div, 1);
//         }
//         quotient = quotient * 10 + div;
//         base *= 10;
//     }

//     return quotient;
// }

int main() {
    int x, y;

    printf("Enter two binary numbers: ");
    scanf("%d %d", &x, &y);

    printf("Addition Result: %d\n", add(x, y));
    printf("Multiplication Result: %d\n", multiply(x, y));
    // printf("Division Result: %d\n", divide(x, y));

    return 0;
}
    