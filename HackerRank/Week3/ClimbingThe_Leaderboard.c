#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *ranked = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }

    /* build unique descending scores */
    int *uniq = malloc(n * sizeof(int));
    int ucount = 0;
    if (n > 0) {
        uniq[ucount++] = ranked[0];
        for (int i = 1; i < n; i++) {
            if (ranked[i] != ranked[i - 1]) {
                uniq[ucount++] = ranked[i];
            }
        }
    }

    int m;
    scanf("%d", &m);
    int *player = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    /* start from the lowest unique rank and move up as player scores increase */
    int pos = ucount - 1;
    for (int i = 0; i < m; i++) {
        int score = player[i];
        while (pos >= 0 && score >= uniq[pos]) {
            pos--;
        }
        printf("%d\n", pos + 2);
    }

    free(ranked);
    free(uniq);
    free(player);
    return 0;
}

    
