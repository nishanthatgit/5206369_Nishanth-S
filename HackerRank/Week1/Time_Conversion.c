//problem: Time Conversion

//link:https://www.hackerrank.com/challenges/one-month-preparation-kit-time-conversion/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one

#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    
    scanf("%s", str);
    int i;
    int temp1,temp2,temp3;

    //checking for edge cases
    if(str[8] == 'P' && str[0]=='1' && str[1]=='2')
    goto skip;
    else if (str[8] == 'A' && str[0]=='1' && str[1]=='2')
    {
        str[0] = '0';
        str[1] = '0';
    }
    
    //if the time is PM, converting to 24hr format by adding 12
    if(str[8] == 'P')
    {
          // subracting '0' to make the char as int
          temp1 = str[0] - '0';
          temp2 = str[1] - '0';
          temp3 = (temp1*10) + temp2 +12;
          
          //adding '0' to make int as char
          str[0] = temp3/10 + '0';
          str[1] = temp3%10 + '0';
    }
    
    skip:
    for( i=0;i<strlen(str);i++)
    {
        if(str[i] == 'P'||str[i] == 'A')
        {
        break;
        }
        printf("%c", str[i]);
    }
    
    
}
