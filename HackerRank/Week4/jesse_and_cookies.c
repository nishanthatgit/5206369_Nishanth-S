#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX], size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify_up(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapify_down(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if(l < size && heap[l] < heap[smallest]) smallest = l;
    if(r < size && heap[r] < heap[smallest]) smallest = r;
    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(smallest);
    }
}

void insert(int val) {
    heap[size] = val;
    heapify_up(size);
    size++;
}

int extractMin() {
    if(size == 0) return -1;
    int root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify_down(0);
    return root;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(x);
    }

    int ops = 0;
    while(size > 0 && heap[0] < k) {
        if(size < 2) {
            printf("-1\n");
            return 0;
        }
        int a = extractMin();
        int b = extractMin();
        int new_cookie = a + 2*b;
        insert(new_cookie);
        ops++;
    }

    printf("%d\n", ops);
    return 0;
}
