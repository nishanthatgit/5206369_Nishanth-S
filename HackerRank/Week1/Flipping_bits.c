//Problem: Flipping Bits

//Link:https://www.hackerrank.com/challenges/one-month-preparation-kit-flipping-bits/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one

#include <stdio.h>
int main()
{
    int size,i;
    scanf("%d", &size);

    unsigned int arr[size];
    
    for( i=0; i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for( i=0; i<size;i++)
    {
    printf("%u\n", ~arr[i]);
    }
}
