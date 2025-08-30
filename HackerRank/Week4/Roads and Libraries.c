#include <stdio.h>
#include <stdlib.h>

#define MAX 100005
int vis[MAX];
int adj[MAX][MAX/10],deg[MAX];
int n;

void dfs(int u,int* cnt){
    vis[u]=1;(*cnt)++;
    for(int i=0;i<deg[u];i++){
        int v=adj[u][i];
        if(!vis[v]) dfs(v,cnt);
    }
}

int main(){
    int q;scanf("%d",&q);
    while(q--){
        int m;long long cl,cr;
        scanf("%d%d%lld%lld",&n,&m,&cl,&cr);
        for(int i=1;i<=n;i++){vis[i]=0;deg[i]=0;}
        for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);
            adj[u][deg[u]++]=v;
            adj[v][deg[v]++]=u;
        }
        long long ans=0;
        if(cl<=cr){ans=(long long)n*cl;}
        else{
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    int cnt=0;
                    dfs(i,&cnt);
                    ans+=cl+(cnt-1)*cr;
                }
            }
        }
        printf("%lld\n",ans);
    }
}
