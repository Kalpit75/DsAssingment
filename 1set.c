#include <stdio.h>

// Function to perform set union
void setUnion(int set1[], int size1, int set2[], int size2) {
    int i, j;
    int unionSet[size1 + size2];

    // Copy elements of set1 to unionSet
    for (i = 0; i < size1; i++) {
        unionSet[i] = set1[i];
    }

    // Check and add elements of set2 to unionSet if they are not already present
    for (i = 0; i < size2; i++) {
        int isDuplicate = 0;
        for (j = 0; j < size1 + i; j++) {
            if (set2[i] == unionSet[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionSet[size1 + i] = set2[i];
        }
    }

    // Display the union set
    printf("Union: { ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", unionSet[i]);
    }
    printf("}\n");
}

// Function to perform set intersection
void setIntersection(int set1[], int size1, int set2[], int size2) {
    int i, j;
    int intersectionSet[size1 < size2 ? size1 : size2];

    // Check and add common elements of set1 and set2 to intersectionSet
    int index = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                intersectionSet[index++] = set1[i];
                break;
            }
        }
    }

    // Display the intersection set
    printf("Intersection: { ");
    for (i = 0; i < index; i++) {
        printf("%d ", intersectionSet[i]);
    }
    printf("}\n");
}

// Function to perform set difference (set1 - set2)
void setDifference(int set1[], int size1, int set2[], int size2) {
    int i, j;
    int differenceSet[size1];
    int index = 0;

    // Check and add elements of set1 that are not present in set2 to differenceSet
    for (i = 0; i < size1; i++) {
        int isPresent = 0;
        for (j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                isPresent = 1;
                break;
            }
        }
        if (!isPresent) {
            differenceSet[index++] = set1[i];
        }
    }

    // Display the difference set
    printf("Difference (set1 - set2): { ");
    for (i = 0; i < index; i++) {
        printf("%d ", differenceSet[i]);
    }
    printf("}\n");
}

// Function to perform Cartesian product
void cartesianProduct(int set1[], int size1, int set2[], int size2) {
    int i, j;

    // Display the Cartesian product
    printf("Cartesian Product: { ");
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            printf("(%d, %d) ", set1[i], set2[j]);
        }
    }
    printf("}\n");
}

int main() {
    int set1[] = {1, 2, 3, 4};
    int size1 = sizeof(set1) / sizeof(set1[0]);

    int set2[] = {3, 4, 5, 6};
    int size2 = sizeof(set2) / sizeof(set2[0]);

    // Perform set operations
    setUnion(set1, size1, set2, size2);
    setIntersection(set1, size1, set2, size2);
    setDifference(set1, size1, set2, size2);
    cartesianProduct(set1, size1, set2, size2);

    return 0;
}
