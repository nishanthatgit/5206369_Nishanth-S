#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int hackerlandRadioTransmitters(int houses[], int n, int k) {
    qsort(houses, n, sizeof(int), compare);
    int transmitters = 0, i = 0;
    while (i < n) {
        transmitters++;
        int loc = houses[i] + k;
        while (i < n && houses[i] <= loc) i++;
        int pos = houses[i - 1] + k;
        while (i < n && houses[i] <= pos) i++;
    }
    return transmitters;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int houses[n];
    for (int i = 0; i < n; i++) scanf("%d", &houses[i]);
    printf("%d\n", hackerlandRadioTransmitters(houses, n, k));
    return 0;
}
