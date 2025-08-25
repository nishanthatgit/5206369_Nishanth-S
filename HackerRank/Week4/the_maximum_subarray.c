//the maximum subarray

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

       
        int max_ending = arr[0], max_so_far = arr[0];
        for(int i = 1; i < n; i++) {
            if(max_ending + arr[i] > arr[i]) {
                max_ending = max_ending + arr[i];
            } else {
                max_ending = arr[i];
            }

            if(max_ending > max_so_far) {
                max_so_far = max_ending;
            }
        }

        
        int subseq = 0, max_elem = arr[0];
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) subseq += arr[i];
            if(arr[i] > max_elem) max_elem = arr[i];
        }
        if(subseq == 0) subseq = max_elem;

        printf("%d %d\n", max_so_far, subseq);
    }

    return 0;
}
