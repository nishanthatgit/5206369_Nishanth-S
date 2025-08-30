#include <stdio.h>
#include <string.h>

#define MAX 100000
char dict[MAX][60];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",dict[i]);
        for(int j=0;j<i;j++){
            if(strncmp(dict[i],dict[j],strlen(dict[i]))==0 ||
               strncmp(dict[j],dict[i],strlen(dict[j]))==0){
                printf("BAD SET\n%s",dict[i]);
                return 0;
            }
        }
    }
    printf("GOOD SET");
}
