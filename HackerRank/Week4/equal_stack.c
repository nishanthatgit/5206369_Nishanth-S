//equal_stacks:

#include <stdio.h>

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int a[n1], b[n2], c[n3];
    int s1 = 0, s2 = 0, s3 = 0;

 
    for(int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
        s1 += a[i];
    }


    for(int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
        s2 += b[i];
    }

   
    for(int i = 0; i < n3; i++) {
        scanf("%d", &c[i]);
        s3 += c[i];
    }

    int i = 0, j = 0, k = 0;

    while(!(s1 == s2 && s2 == s3)) {
        if(s1 >= s2 && s1 >= s3) {
            s1 -= a[i++];
        } 
        else if(s2 >= s1 && s2 >= s3) {
            s2 -= b[j++];
        } 
        else {
            s3 -= c[k++];
        }
    }

    printf("%d\n", s1);
    return 0;
}
