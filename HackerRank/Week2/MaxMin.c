#include<stdio.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    
    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    int temp;
    
    for(int i =0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(arr[i]< arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    int mini = arr[k-1] - arr[0];
    
    for(int i = 1;i < n-k; i++){
        int diff = arr[i + k - 1] - arr[i];
        if (diff<mini) {
            mini = diff;
        }
    }
    
    printf("%d",mini);
    
}