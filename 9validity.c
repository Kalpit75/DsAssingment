#include <stdio.h>

// Function to evaluate the logical expression
int evaluate(int p, int q, int r) {
    int left_side = (!p || q) && (!q || r);
    int right_side = !p || r;
    return left_side == right_side;
}

int main() {
    printf("Truth Table for (p->q)^(q->r)->(p->r)\n");
    printf("p\tq\tr\t(p->q)^(q->r)\t(p->r)\tValid?\n");

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                int result = evaluate(p, q, r);
                printf("%d\t%d\t%d\t%d\t\t\t%d\t\t%s\n", p, q, r, (!p || q) && (!q || r), !p || r, result ? "Yes" : "No");
                
                // If the argument is invalid for any combination, print and exit
                if (!result) {
                    printf("The argument is invalid.\n");
                    return 0;
                }
            }
        }
    }

    printf("The argument is valid for all combinations.\n");

    return 0;
}
