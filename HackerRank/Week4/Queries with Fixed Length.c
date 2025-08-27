#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (q--) {
        int d;
        scanf("%d", &d);
        int deque[n], front = 0, back = -1;
        int res = 1e9;

        for (int i = 0; i < n; i++) {
            while (front <= back && arr[deque[back]] <= arr[i]) back--;
            deque[++back] = i;
            if (deque[front] <= i - d) front++;
            if (i >= d - 1) {
                if (arr[deque[front]] < res) res = arr[deque[front]];
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
