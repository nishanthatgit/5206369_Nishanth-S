#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000   // max total length across operations

// Stack node for storing operations
typedef struct Operation {
    int type;           // 1=append, 2=delete
    char *data;         // string involved (for undo)
} Operation;

Operation history[MAX_LEN];
int histTop = -1;

// Current text
char text[MAX_LEN];
int textLen = 0;

// Push an operation to history
void pushHistory(int type, const char *data) {
    histTop++;
    history[histTop].type = type;
    history[histTop].data = strdup(data); // save string
}

// Pop operation from history
Operation popHistory() {
    return history[histTop--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) { // append
            char W[100000];
            scanf("%s", W);
            pushHistory(1, W); // store for undo
            int len = strlen(W);
            strcpy(text + textLen, W);
            textLen += len;
            text[textLen] = '\0';

        } else if (type == 2) { // delete
            int k;
            scanf("%d", &k);
            char deleted[100000];
            strncpy(deleted, text + textLen - k, k);
            deleted[k] = '\0';
            pushHistory(2, deleted); // store deleted part
            textLen -= k;
            text[textLen] = '\0';

        } else if (type == 3) { // print
            int k;
            scanf("%d", &k);
            printf("%c\n", text[k - 1]);

        } else if (type == 4) { // undo
            Operation last = popHistory();
            if (last.type == 1) { // undo append
                int len = strlen(last.data);
                textLen -= len;
                text[textLen] = '\0';
            } else if (last.type == 2) { // undo delete
                int len = strlen(last.data);
                strcpy(text + textLen, last.data);
                textLen += len;
                text[textLen] = '\0';
            }
            free(last.data);
        }
    }

    return 0;
}
