#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    long long *arr = (long long*)calloc(n + 2, sizeof(long long));

    while (m--) {
        int a, b;
        long long k;
        scanf("%d %d %lld", &a, &b, &k);
        arr[a] += k;
        arr[b + 1] -= k;
    }

    long long max = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        curr += arr[i];
        if (curr > max) max = curr;
    }

    printf("%lld\n", max);
    free(arr);
    return 0;
}
