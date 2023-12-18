#include <stdio.h>

#define MAX_SIZE 10

// Function to check if a relation is reflexive
int isReflexive(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        if (!matrix[i][i]) {
            return 0; // Not reflexive
        }
    }
    return 1; // Reflexive
}

// Function to check if a relation is symmetric
int isSymmetric(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

// Function to check if a relation is transitive
int isTransitive(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {
                for (int k = 0; k < size; k++) {
                    if (matrix[j][k] && !matrix[i][k]) {
                        return 0; // Not transitive
                    }
                }
            }
        }
    }
    return 1; // Transitive
}

// Function to check if two relations are equivalent
int areEquivalent(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0; // Not equivalent
            }
        }
    }
    return 1; // Equivalent
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;

    // Get the size of the set from the user
    printf("Enter the size of the set: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size of the set.\n");
        return 1;
    }

    // Initialize a matrix for the relation
    int relation[MAX_SIZE][MAX_SIZE];

    // Get the relation from the user
    printf("Enter the relation matrix (0 or 1):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &relation[i][j]);
        }
    }

    // Display the relation matrix
    printf("\nRelation Matrix:\n");
    displayMatrix(relation, size);

    // Check properties and equivalence
    if (isReflexive(relation, size)) {
        printf("\nThe relation is reflexive.\n");
    } else {
        printf("\nThe relation is not reflexive.\n");
    }

    if (isSymmetric(relation, size)) {
        printf("The relation is symmetric.\n");
    } else {
        printf("The relation is not symmetric.\n");
    }

    if (isTransitive(relation, size)) {
        printf("The relation is transitive.\n");
    } else {
        printf("The relation is not transitive.\n");
    }

    // Create another relation for equivalence check
    int equivalentRelation[MAX_SIZE][MAX_SIZE];

    printf("\nEnter another relation matrix for equivalence check:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &equivalentRelation[i][j]);
        }
    }

    if (areEquivalent(relation, equivalentRelation, size)) {
        printf("\nThe two relations are equivalent.\n");
    } else {
        printf("\nThe two relations are not equivalent.\n");
    }

    return 0;
}
