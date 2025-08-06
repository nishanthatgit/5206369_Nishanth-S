//Problem: SubArray Division 1

//Link:https://www.hackerrank.com/challenges/one-month-preparation-kit-the-birthday-bar/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one

#include<stdio.h>
int main()
{
    int size,j,i,k,tot,count;
    
    scanf("%d", &size);
    
    int arr[size];
    
    for(i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d %d", &tot, &count);
    
    int tempsum =0,result = 0, elementcount = 0;
    //counting the possible ways, untill the sum reachs the ron's birth day or the count reaches ron's birth month
    for( j=0;j<size;j++)
    {
        for( i=j,k =1 ;i<size && k<=count ;i++,k++)
        {
            tempsum += arr[i];
            if(tempsum == tot && k == count)
            {
                result++;
                tempsum =0;
            }
            if(k== count)
            {
                tempsum =0;
            }
        }
    }
    printf("%d", result);
    
    return 0;
}
