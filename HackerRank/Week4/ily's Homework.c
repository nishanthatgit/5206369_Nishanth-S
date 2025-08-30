#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int swaps1=0,swaps2=0;
    int b[n],c[n];
    for(int i=0;i<n;i++){b[i]=a[i];c[i]=a[i];}
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++) if(b[j]<b[min]) min=j;
        if(min!=i){int t=b[i];b[i]=b[min];b[min]=t;swaps1++;}
    }
    for(int i=0;i<n;i++){
        int max=i;
        for(int j=i+1;j<n;j++) if(c[j]>c[max]) max=j;
        if(max!=i){int t=c[i];c[i]=c[max];c[max]=t;swaps2++;}
    }
    printf("%d",swaps1<swaps2?swaps1:swaps2);
}
