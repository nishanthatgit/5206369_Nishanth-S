//problem mini max sum

//link :https://www.hackerrank.com/challenges/one-month-preparation-kit-mini-max-sum/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one

#include <stdio.h>
int main()
{
    int size =5,i;
    long int arr[size];

    //getting array
    for( int i =0;i<size;i++)
    {
        scanf("%ld", &arr[i]);
    }
    long int largest = arr[0], smallest = arr[0], max = 0, min = 0;

    
    for( i=0;i<size;i++)
    {
        //finding largest element
        if(largest < arr[i])
        largest = arr[i];

        //finding smallest element
        if( smallest > arr[i])
        smallest = arr[i];

        //finding sum of elements
        max += arr[i];
        min += arr[i];
    }

    //calculating max and min values
    max = max - smallest;
    min = min - largest;
    printf("%ld %ld", min , max); 
}
