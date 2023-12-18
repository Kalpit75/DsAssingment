#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fisherYatesShuffle(int arr[], int size) {
    // Seed the random number generator
    srand(time(NULL));

    // Start from the last element and swap one by one
    for (int i = size - 1; i > 0; i--) {
        // Generate a random index between 0 and i (inclusive)
        int j = rand() % (i + 1);

        // Swap arr[i] with the randomly selected element
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size should be greater than 0.\n");
        return 1;
    }

    // Create an array of integers from 1 to n
    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // Shuffle the array using Fisher-Yates algorithm
    fisherYatesShuffle(array, n);

    // Display the shuffled array
    printf("Shuffled Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
