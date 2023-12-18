#include <stdio.h>

#define MAX_ELEMENTS 10

typedef struct {
    char elements[MAX_ELEMENTS];
    double membership[MAX_ELEMENTS];
    int count;
} FuzzySet;

// Function to initialize a fuzzy set
void initializeFuzzySet(FuzzySet *set) {
    set->count = 0;
}

// Function to add an element with its membership to a fuzzy set
void addElement(FuzzySet *set, char element, double membership) {
    if (set->count < MAX_ELEMENTS) {
        set->elements[set->count] = element;
        set->membership[set->count] = membership;
        set->count++;
    } else {
        printf("Fuzzy set is full. Cannot add more elements.\n");
    }
}

// Function to display a fuzzy set
void displayFuzzySet(FuzzySet set) {
    printf("{ ");
    for (int i = 0; i < set.count; i++) {
        printf("(%c, %.2lf) ", set.elements[i], set.membership[i]);
    }
    printf("}\n");
}

// Function to perform fuzzy set union
FuzzySet fuzzySetUnion(FuzzySet set1, FuzzySet set2) {
    FuzzySet result;
    initializeFuzzySet(&result);

    for (int i = 0; i < set1.count; i++) {
        addElement(&result, set1.elements[i], set1.membership[i]);
    }

    for (int i = 0; i < set2.count; i++) {
        int index = -1;
        for (int j = 0; j < result.count; j++) {
            if (set2.elements[i] == result.elements[j]) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            addElement(&result, set2.elements[i], set2.membership[i]);
        } else {
            // Perform maximum operation for membership
            if (set2.membership[i] > result.membership[index]) {
                result.membership[index] = set2.membership[i];
            }
        }
    }

    return result;
}

// Function to perform fuzzy set intersection
FuzzySet fuzzySetIntersection(FuzzySet set1, FuzzySet set2) {
    FuzzySet result;
    initializeFuzzySet(&result);

    for (int i = 0; i < set1.count; i++) {
        for (int j = 0; j < set2.count; j++) {
            if (set1.elements[i] == set2.elements[j]) {
                // Perform minimum operation for membership
                double minMembership = (set1.membership[i] < set2.membership[j]) ? set1.membership[i] : set2.membership[j];
                addElement(&result, set1.elements[i], minMembership);
                break;
            }
        }
    }

    return result;
}

// Function to perform fuzzy set complement
FuzzySet fuzzySetComplement(FuzzySet set) {
    FuzzySet result;
    initializeFuzzySet(&result);

    for (int i = 0; i < set.count; i++) {
        // Perform complement operation for membership
        addElement(&result, set.elements[i], 1 - set.membership[i]);
    }

    return result;
}

int main() {
    FuzzySet set1, set2, result;

    // Initialize fuzzy sets
    initializeFuzzySet(&set1);
    initializeFuzzySet(&set2);

    // Add elements to fuzzy sets
    addElement(&set1, 'A', 0.8);
    addElement(&set1, 'B', 0.5);
    addElement(&set1, 'C', 0.3);

    addElement(&set2, 'B', 0.7);
    addElement(&set2, 'C', 0.9);
    addElement(&set2, 'D', 0.6);

    // Display fuzzy sets
    printf("Fuzzy Set 1: ");
    displayFuzzySet(set1);

    printf("Fuzzy Set 2: ");
    displayFuzzySet(set2);

    // Perform fuzzy set union
    result = fuzzySetUnion(set1, set2);
    printf("\nFuzzy Set Union: ");
    displayFuzzySet(result);

    // Perform fuzzy set intersection
    result = fuzzySetIntersection(set1, set2);
    printf("\nFuzzy Set Intersection: ");
    displayFuzzySet(result);

    // Perform fuzzy set complement
    result = fuzzySetComplement(set1);
    printf("\nFuzzy Set 1 Complement: ");
    displayFuzzySet(result);

    return 0;
}
