//program to add and multiply large integer
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 100

void addLargeIntegers(char num1[], char num2[], char result[]) {
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0;
        int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[maxLen - 1 - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result[0] = carry + '0';
        result[maxLen] = '\0';
    } else {
        result[maxLen - 1] = '\0';
    }
}

void multiplyLargeIntegers(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int product[MAX_DIGITS * 2] = {0};

    for (int i = 0; i < len1; i++) {
        int carry = 0;
        int digit1 = num1[len1 - 1 - i] - '0';

        for (int j = 0; j < len2; j++) {
            int digit2 = num2[len2 - 1 - j] - '0';
            int sum = digit1 * digit2 + product[i + j] + carry;
            product[i + j] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0) {
            product[i + len2] += carry;
        }
    }

    int resultLen = 0;
    for (int i = 0; i < len1 + len2; i++) {
        if (product[i] > 0 || resultLen > 0) {
            result[resultLen++] = product[i] + '0';
        }
    }

    result[resultLen] = '\0';

    if (resultLen == 0) {
        strcpy(result, "0");
    }
}

int main() {
    char num1[MAX_DIGITS], num2[MAX_DIGITS], resultAdd[MAX_DIGITS + 1], resultMultiply[MAX_DIGITS * 2 + 1];

    printf("Enter the first large integer: ");
    scanf("%s", num1);

    printf("Enter the second large integer: ");
    scanf("%s", num2);

    addLargeIntegers(num1, num2, resultAdd);
    multiplyLargeIntegers(num1, num2, resultMultiply);

    printf("Sum: %s\n", resultAdd);
    printf("Product: %s\n", resultMultiply);

    return 0;
}
