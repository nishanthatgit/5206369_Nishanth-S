#include<stdio.h>
#include<string.h>
long long SumOfDigits(long long num)
{
    long long sum=0;
    while(num>0)
    {
        sum += num%10;
        num=num/10;
    }
    return sum;
}
long long SuperDigit(long long num)
{
    while(num>=10)
    {
        num = SumOfDigits(num);
    }
    return num; 
    
}

int main()
{
    char arr[100005];
    long long k;
    scanf("%s %lld",arr,&k);
    long long sum=0;
    for(int i=0;arr[i] != '\0';i++)
    {
        sum += (arr[i]-'0');
    }
    long long total = sum*k;
    printf("%lld\n",SuperDigit(total));
    
    return 0;
    
}
