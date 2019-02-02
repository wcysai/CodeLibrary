#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=5*(1e5)+10;
struct xxx{
    int y,nxt;
}a[N*2];
int h[N],dep[N],top[N],mx[N],son[N],pre[N],pos[N];
int dfn[N];
ll f[N*10],g[N*10];
int T,n,m,tot,dfn_t,lis_pos;
ll ans;
void add(int x,int y){a[++tot].y=y; a[tot].nxt=h[x]; h[x]=tot;}
void dfs(int fa,int x,int d){
    int u;
    dep[x]=d; mx[x]=1;
    pre[x]=fa; son[x]=0;
    for (int i=h[x];i!=-1;i=a[i].nxt){
        u=a[i].y;
        if (u==fa) continue;
        dfs(x,u,d+1);
        mx[x]=max(mx[x],mx[u]+1);
        if (mx[son[x]]<mx[u]+1) son[x]=u;
    }
}
void dfs1(int fa,int x){
    int u;
    dfn[x]=++dfn_t;
    if (son[x]){
        top[son[x]]=top[x];
        dfs1(x,son[x]);
    }
    for (int i=h[x];i!=-1;i=a[i].nxt){
        u=a[i].y;
        if (u==fa||u==son[x]) continue;
        top[u]=u; pos[u]=lis_pos+mx[u];
        lis_pos+=mx[u]*2;
        dfs1(x,u);
    }
}
int locf(int x,int i){return dfn[x]+i;}
int locg(int x,int i){return pos[top[x]]-(dep[x]-dep[top[x]])+i;}
void calc(int x,int u){
    for (int i=1;i<=mx[u];++i)
        ans+=f[locf(u,i-1)]*g[locg(x,i)];
    for (int i=1;i<mx[u];++i)
        ans+=g[locg(u,i)]*f[locf(x,i-1)];
    for (int i=0;i<mx[u]-1;++i)
        g[locg(x,i)]+=g[locg(u,i+1)];
    for (int i=1;i<=mx[u];++i){
        g[locg(x,i)]+=f[locf(x,i)]*f[locf(u,i-1)];
        f[locf(x,i)]+=f[locf(u,i-1)];
    }
}
void solve(int fa,int x){
    int u;
    if (!son[x]){
        f[locf(x,0)]=1; g[locg(x,0)]=0;
        return;
    }
    solve(x,son[x]);
    g[locg(x,mx[x])]=g[locg(x,mx[x]-1)]=0;
    ans+=g[locg(x,0)];
    f[locf(x,0)]=1;
    for (int i=h[x];i!=-1;i=a[i].nxt){
        u=a[i].y;
        if (u==fa||u==son[x]) continue;
        solve(x,u);
        calc(x,u);
    }
}
void init(){
    memset(h,-1,sizeof(h));
    tot=0;
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
}

int main(){
    scanf("%d",&T);
    while(T--)
    {
        int x,y;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(pre,0,sizeof(pre));
        memset(son,0,sizeof(son));
        init();
        for (int i=1;i<n;++i){
            scanf("%d%d",&x,&y);
            add(x,y); add(y,x);
        }
        dfs(0,1,1);
        dfn_t=0; lis_pos=0; 
        top[1]=1; pos[1]=lis_pos+mx[1];
        lis_pos=mx[1]*2;
        dfs1(0,1);
        ans=0;
        solve(0,1);
        printf("%lld\n",ans);
    }
}
