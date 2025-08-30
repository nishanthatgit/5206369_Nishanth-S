#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char g[101][101];
int vis[101][101];
int q[10001][3];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int bfs(int sx,int sy,int ex,int ey){
    int f=0,r=0;
    q[r][0]=sx;q[r][1]=sy;q[r][2]=0;vis[sx][sy]=1;
    while(f<=r){
        int x=q[f][0],y=q[f][1],d=q[f][2];f++;
        if(x==ex && y==ey) return d;
        for(int k=0;k<4;k++){
            int nx=x,ny=y;
            while(1){
                nx+=dx[k];ny+=dy[k];
                if(nx<0||ny<0||nx>=n||ny>=n) break;
                if(g[nx][ny]=='X') break;
                if(!vis[nx][ny]){
                    vis[nx][ny]=1;
                    r++;q[r][0]=nx;q[r][1]=ny;q[r][2]=d+1;
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",g[i]);
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d",bfs(a,b,c,d));
}
