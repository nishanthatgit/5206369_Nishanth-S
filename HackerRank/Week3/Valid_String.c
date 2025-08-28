#include <stdio.h>
#include <string.h>

char* isValid(char s[]) {
    int freq[26] = {0};
    int len = strlen(s);

    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    int counts[26], cLen = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            counts[cLen++] = freq[i];
        }
    }

    // find min and max frequency
    int min = counts[0], max = counts[0];
    for (int i = 1; i < cLen; i++) {
        if (counts[i] < min) min = counts[i];
        if (counts[i] > max) max = counts[i];
    }

    // Case 1: all same
    if (min == max) {
        return "YES";
    }

    // count how many times min and max appear
    int minCount = 0, maxCount = 0;
    for (int i = 0; i < cLen; i++) {
        if (counts[i] == min) minCount++;
        if (counts[i] == max) maxCount++;
    }

    // Case 2: one frequency occurs once and is 1 (we can remove that char)
    if (min == 1 && minCount == 1 && maxCount + minCount == cLen) {
        return "YES";
    }

    // Case 3: difference between max and min is 1 and max occurs once
    if ((max - min == 1) && maxCount == 1) {
        return "YES";
    }

    return "NO";
}

int main() {
    char s[100005];
    scanf("%s", s);

    printf("%s\n", isValid(s));
    return 0;
}
