//problem : Plus Minus

//Link : https://www.hackerrank.com/challenges/one-month-preparation-kit-plus-minus/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one
#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d", &n);
    
    int arr[n];
    for( i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    float pos = 0,neg =0 ,zero =0;

    //loop for counting positive, negative and zeros
    for( i =0;i<n;i++)
    {
        if(arr[i]>0)
        pos++;
        else if(arr[i]<0)
        neg++;
        else
        zero++;
    }
    
    printf("%f\n%f\n%f\n", pos/n, neg/n, zero/n);
}
