//Problem : Lonely Interger

//Link: https://www.hackerrank.com/challenges/one-month-preparation-kit-lonely-integer/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one
#include<stdio.h>
int main()
{
    // getting size
    int size,i,j,flag;
    scanf("%d", &size);
    
    int arr[size];
    //getting array elements
    for (i =0; i<size;i++ )
    {
        scanf("%d", &arr[i]);
    }
    //for array with size 1
    if( size == 1)
    {
        printf("%d", arr[0]);
        return 0;
    }
    
    //for array with size greater than 1
    for( i =0; i<size;i++)
    {
        flag = 1;
        for( j=0;j<size;j++)
        {
            if(i != j && arr[i] == arr[j])
            {
              flag = 0;
              break;
            }
        }
        if(flag)
        printf("%d ", arr[i]);
    }
    return 0;
}
