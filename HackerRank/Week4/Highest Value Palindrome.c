#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n+1];
    scanf("%s", s);

    int l = 0, r = n-1;
    int *changed = (int*)calloc(n, sizeof(int));

    while (l < r) {
        if (s[l] != s[r]) {
            if (s[l] > s[r]) s[r] = s[l];
            else s[l] = s[r];
            changed[l] = changed[r] = 1;
            k--;
        }
        l++; r--;
    }

    if (k < 0) {
        printf("-1\n");
        return 0;
    }

    l = 0; r = n-1;
    while (l <= r && k > 0) {
        if (l == r) {
            if (s[l] != '9' && k > 0) s[l] = '9';
        } else {
            if (s[l] != '9') {
                if (changed[l] && k >= 1) {
                    s[l] = s[r] = '9';
                    k--;
                } else if (!changed[l] && k >= 2) {
                    s[l] = s[r] = '9';
                    k -= 2;
                }
            }
        }
        l++; r--;
    }

    printf("%s\n", s);
    free(changed);
    return 0;
}
