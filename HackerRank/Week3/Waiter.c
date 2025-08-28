#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100000

// Function to check prime
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Generate first q primes
void generatePrimes(int primes[], int q) {
    int count = 0, num = 2;
    while (count < q) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int plates[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &plates[i]);
    }

    int primes[q];
    generatePrimes(primes, q);

    // Work stacks
    int *A = (int*)malloc(n * sizeof(int));
    int topA = -1;

    // Initialize A with input plates (last input = top of stack)
    for (int i = 0; i < n; i++) {
        A[++topA] = plates[i];
    }

    // Perform iterations
    for (int i = 0; i < q; i++) {
        int prime = primes[i];
        int *nextA = (int*)malloc(n * sizeof(int));
        int topNextA = -1;

        int *B = (int*)malloc(n * sizeof(int));
        int topB = -1;

        // Process current A
        while (topA >= 0) {
            int plate = A[topA--];  // pop from A
            if (plate % prime == 0) {
                B[++topB] = plate;  // push to B
            } else {
                nextA[++topNextA] = plate; // keep in nextA
            }
        }

        // Print B from top to bottom
        while (topB >= 0) {
            printf("%d\n", B[topB--]);
        }

        free(A);
        free(B);
        A = nextA;
        topA = topNextA;
    }

    // Print remaining A (from top to bottom)
    while (topA >= 0) {
        printf("%d\n", A[topA--]);
    }

    free(A);
    return 0;
}
