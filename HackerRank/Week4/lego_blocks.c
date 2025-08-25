//lego blocks

#include <stdio.h>
#define MOD 1000000007

long long power(long long a, long long b) {
    long long res = 1;
    while(b > 0) {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        long long row[m+1];
        row[0] = 1;
        for(int i = 1; i <= m; i++) {
            row[i] = 0;
            for(int k = 1; k <= 4; k++) {
                if(i-k >= 0) row[i] = (row[i] + row[i-k]) % MOD;
            }
        }

        long long total[m+1];
        for(int i = 1; i <= m; i++) {
            total[i] = power(row[i], n);
        }

        long long solid[m+1];
        solid[0] = 1;
        for(int i = 1; i <= m; i++) {
            solid[i] = total[i];
            for(int j = 1; j < i; j++) {
                solid[i] = (solid[i] - (solid[j] * total[i-j]) % MOD + MOD) % MOD;
            }
        }

        printf("%lld\n", solid[m]);
    }

    return 0;
}
