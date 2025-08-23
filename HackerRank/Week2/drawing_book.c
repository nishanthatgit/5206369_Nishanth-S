//drawing book

//link:https://www.hackerrank.com/challenges/one-month-preparation-kit-drawing-book/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-two

#include<stdio.h>
int main()
{
    
    int n,p;
    scanf("%d%d",&n,&p);
    int page = n+1;
    int book[page];
    int result;
    for( int i=0;i<page;i++)
    {
        book[i] = i;
    }
    
    int half = page/2;
    
    if(p+1 > half)
    {
        result = (n-p)/2;
    }
    else 
    {
        result = p/2;
    }
    
    printf("%d", result);
    return 0;

}