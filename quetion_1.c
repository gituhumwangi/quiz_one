#include <stdio.h>

// Function prototypes
int total(int num, int array[]);
int maximum(int num, int array[]);

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Function calls
    int sum = total(n, arr);
    int max = maximum(n, arr);

    printf("The total is %d\n", sum);
    printf("The maximum is %d\n", max);

    return 0;
}

// Function definitions
int total(int num, int array[]) {
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += array[i];
    }
    return sum;
}

int maximum(int num, int array[]) {
    int max = array[0];
    for (int i = 1; i < num; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
