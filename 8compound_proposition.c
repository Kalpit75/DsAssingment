#include <stdio.h>

// Function to calculate the value of a proposition given the truth values of its variables
int evaluateProposition(int a, int b, int c) {
    // Example compound proposition: (a AND b) OR (NOT c)
    return ((a && b) || (!c));
}

// Function to generate and display the truth table
void generateTruthTable() {
    printf("Truth Table for (a AND b) OR (NOT c):\n");
    printf("| a | b | c | Result |\n");
    printf("|---|---|---|--------|\n");

    for (int a = 0; a <= 1; ++a) {
        for (int b = 0; b <= 1; ++b) {
            for (int c = 0; c <= 1; ++c) {
                int result = evaluateProposition(a, b, c);
                printf("| %d | %d | %d |   %d    |\n", a, b, c, result);
            }
        }
    }
}

int main() {
    generateTruthTable();

    return 0;
}
