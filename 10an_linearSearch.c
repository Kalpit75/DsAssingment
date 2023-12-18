#include <stdio.h>

// Function to compute a^n using recursion
long long power(int a, int n) {
    if (n == 0)
        return 1;
    else
        return a * power(a, n - 1);
}

// Function to compute (b^n) % m using recursion
long long modPower(int b, int n, int m) {
    if (n == 0)
        return 1;
    else {
        long long temp = modPower(b, n / 2, m);
        temp = (temp * temp) % m;

        if (n % 2 == 0)
            return temp;
        else
            return (temp * b) % m;
    }
}

// Function to perform linear search using recursion
int linearSearch(int arr[], int key, int size, int index) {
    if (index == size)
        return -1; // Key not found

    if (arr[index] == key)
        return index; // Key found at current index

    return linearSearch(arr, key, size, index + 1); // Recursive call for the next index
}

int main() {
    int choice;

    printf("Choose an operation:\n");
    printf("1. Compute a^n\n");
    printf("2. Compute (b^n) %% m\n");
    printf("3. Perform Linear Search\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int a, n;
            printf("Enter the base (a): ");
            scanf("%d", &a);

            printf("Enter the exponent (n): ");
            scanf("%d", &n);

            long long result = power(a, n);
            printf("%d^%d = %lld\n", a, n, result);
            break;
        }

        case 2: {
            int b, n, m;
            printf("Enter the base (b): ");
            scanf("%d", &b);

            printf("Enter the exponent (n): ");
            scanf("%d", &n);

            printf("Enter the modulus (m): ");
            scanf("%d", &m);

            long long result = modPower(b, n, m);
            printf("(%d^%d) %% %d = %lld\n", b, n, m, result);
            break;
        }

        case 3: {
            int size, key;

            printf("Enter the size of the array: ");
            scanf("%d", &size);

            int arr[size];

            printf("Enter the elements of the array:\n");
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }

            printf("Enter the key to search: ");
            scanf("%d", &key);

            int result = linearSearch(arr, key, size, 0);

            if (result != -1)
                printf("Key %d found at index %d.\n", key, result);
            else
                printf("Key %d not found in the array.\n", key);

            break;
        }

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
