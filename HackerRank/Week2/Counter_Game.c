#include <stdio.h>
#include <stdbool.h>

// Function to check if n is a power of 2
bool isPowerOfTwo(unsigned long long n) {
    return n && !(n & (n - 1));
}

// Function to find the largest power of 2 less than n
unsigned long long largestPowerOfTwo(unsigned long long n) {
    unsigned long long p = 1ULL;
    while (p << 1ULL <= n) {
        p <<= 1ULL;
    }
    return p;
}

// Main game function
const char* counterGame(unsigned long long n) {
    int moves = 0;

    while (n > 1) {
        if (isPowerOfTwo(n)) {
            n /= 2;
        } else {
            n -= largestPowerOfTwo(n);
        }
        moves++;
    }

    if (moves % 2 == 1)
        return "Louise";   // odd moves -> Louise wins
    else
        return "Richard";  // even moves -> Richard wins
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        printf("%s\n", counterGame(n));
    }

    return 0;
}
