//Problem: Count Sorting 1

//Link:https://www.hackerrank.com/challenges/one-month-preparation-kit-countingsort1/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one

#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d", &n);
    
    int arr[n];
    //get input array
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    //declare frequency arrray
    int freqarr[99];
    
    for( i=0;i<100;i++)
    {
        freqarr[i] = 0;
    }
    int temp;
    //update values of frequencyarray based on the given array
    for( i=0;i<n;i++)
    {
        temp = arr[i];
        freqarr[temp]++;
    }
    // print result
    for( i=0;i<100;i++)
    {
        printf("%d ", freqarr[i]);
    }
}
