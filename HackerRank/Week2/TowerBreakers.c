//Link : https://www.hackerrank.com/challenges/one-month-preparation-kit-tower-breakers-1/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-two



#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);  

    for(int i = 0;i < n;i++) {
    
    int n,m;
    
        scanf("%d%d",&n,&m);
        
        if(m == 1 || n % 2 == 0) 
        {
            printf("2\n"); 
        }
        else{
            printf("1\n");
        }
    }
}
