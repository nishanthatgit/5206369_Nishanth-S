//Sales by Match

//Link:https://www.hackerrank.com/challenges/one-month-preparation-kit-sock-merchant/problem?h_l=interview&isFullScreen=false&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-two

#include<stdio.h>
int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for( int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    int sockcount = sockmerchant(size,arr);
    printf("%d", sockcount);
    return 0;
}
int sockmerchant(int size, int*arr)
{
    int sock[101] = {0};
    for(int i =0;i<size;i++)
    {
        sock[arr[i]]++;
    }
    int sockcount = 0;
    for( int i=0;i<101;i++)
    {
        sockcount += sock[i]/2;
    }
    return sockcount;
}

