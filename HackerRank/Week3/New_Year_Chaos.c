#include <stdio.h>

void minimumBribes(int q[], int n) {
    int bribes = 0;

    for (int i = 0; i < n; i++) {
        // check if person has moved more than 2 places ahead
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }

        // count how many times q[i] has been overtaken
        // person q[i] could only have been bribed by people in front of them
        for (int j = (q[i] - 2 > 0 ? q[i] - 2 : 0); j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }
    printf("%d\n", bribes);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int q[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }
        minimumBribes(q, n);
    }
    return 0;
}
