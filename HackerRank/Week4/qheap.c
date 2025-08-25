#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// simple array-based min-heap
int heap[MAX], size = 0;

void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
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

int getMin() {
    return heap[0];
}

void deleteVal(int val) {
    // find val
    for(int i = 0; i < size; i++) {
        if(heap[i] == val) {
            heap[i] = heap[size-1];
            size--;
            heapify_down(i);
            heapify_up(i);
            break;
        }
    }
}

int main() {
    int q;
    scanf("%d", &q);

    while(q--) {
        int type, v;
        scanf("%d", &type);

        if(type == 1) {
            scanf("%d", &v);
            insert(v);
        }
        else if(type == 2) {
            scanf("%d", &v);
            deleteVal(v);
        }
        else {
            printf("%d\n", getMin());
        }
    }

    return 0;
}
