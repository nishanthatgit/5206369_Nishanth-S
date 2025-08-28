#include <stdio.h>

#define RMAX 205
#define CMAX 205

int r, c, n;
char grid[RMAX][CMAX];
char fullg[RMAX][CMAX];
char nextg[RMAX][CMAX];

void fill_with_bombs(char arr[RMAX][CMAX]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = 'O';
        }
        arr[i][c] = '\0';
    }
}

void detonate(const char src[RMAX][CMAX], char dest[RMAX][CMAX]) {
    // Start from a full grid of bombs
    fill_with_bombs(dest);

    // Directions: right, down, left, up, self
    int dx[5] = {0, 1, 0, -1, 0};
    int dy[5] = {1, 0, -1, 0, 0};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (src[i][j] == 'O') {
                for (int k = 0; k < 5; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                        dest[ni][nj] = '.';
                    }
                }
            }
        }
        dest[i][c] = '\0';
    }
}

int main(void) {
    if (scanf("%d %d %d", &r, &c, &n) != 3) return 0;

    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
        grid[i][c] = '\0';  // ensure null-termination
    }

    if (n == 1) {
        for (int i = 0; i < r; i++) {
            printf("%s\n", grid[i]);
        }
        return 0;
    }

    if (n % 2 == 0) {
        fill_with_bombs(fullg);
        for (int i = 0; i < r; i++) {
            printf("%s\n", fullg[i]);
        }
        return 0;
    }

    // For odd n >= 3, pattern cycles every 4 seconds:
    // n % 4 == 3 -> detonate once (state at t=3)
    // n % 4 == 1 -> detonate twice (state at t=5)
    detonate(grid, nextg);  // state at t=3
    if (n % 4 == 3) {
        for (int i = 0; i < r; i++) {
            printf("%s\n", nextg[i]);
        }
    } else {
        char next2[RMAX][CMAX];
        detonate(nextg, next2);  // state at t=5
        for (int i = 0; i < r; i++) {
            printf("%s\n", next2[i]);
        }
    }

    return 0;
}
