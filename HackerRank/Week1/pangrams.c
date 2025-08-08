//problem : pangram

//link :https://www.hackerrank.com/challenges/one-month-preparation-kit-pangrams/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[1000];
    scanf("%[^\n]", str);
    
    int ispangram = 0,flag;
    char tempchar;
    
    for( tempchar = 'a';tempchar <= 'z'; tempchar ++ )
    {
        for( int i=0;i<strlen(str);i++)
        {
            if(tolower(str[i]) == tempchar)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        } 
        if(flag)
        ispangram = 1;
        else 
        {
            ispangram = 0;
            break;
        }
    }  
    
    if(ispangram)
    printf("pangram");
    else
    printf("not pangram");
}
