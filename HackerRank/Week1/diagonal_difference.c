//problem : Diagonal Difference

//Link : https://www.hackerrank.com/challenges/one-month-preparation-kit-diagonal-difference/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one
#include<stdio.h>
int main()
{
    int size,i,j, d1=0,d2=0, diff;
    scanf("%d",&size);
    
    int arr[size][size];
    
    //getting 2d array
    for( i =0; i<size;i++)
    {
        for( j=0;j<size; j++)
        {
            scanf("%d", &arr[i][j]); 
        }
    }
    
    //calculating diagonal 1
    for( i =0; i<size;i++)
    {
            d1 += arr[i][i]; 
    }
    
    //calculating diagonal 2
    for( j=size-1,i=0; j>= 0 && i<size; j--,i++)
        {
            d2 += arr[i][j]; 
        }
    
    //finding the difference between d1 and d2    
    if( d1> d2)
    {
    diff = d1-d2;
    }
    else
    {
    diff = d2-d1;
    }
    
    printf("%d", diff);
}
