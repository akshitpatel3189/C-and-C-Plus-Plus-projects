#include <stdio.h>

int main() {
    int terms;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &terms);

    int fib[terms];

    fib[0] = 0;  // First Fibonacci number
    fib[1] = 1;  // Second Fibonacci number

    // Generating Fibonacci series
    for (int i = 2; i < terms; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Fibonacci series up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
    return 0;
}
