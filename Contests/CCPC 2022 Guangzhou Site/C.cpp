#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+10;
vector<int> G[maxn],H[maxn],F[maxn];
int p[maxn],n,m,T,pre[maxn],f[maxn],vis[maxn],val[maxn],ans[maxn];
int deg[maxn];
int ffind(int x){
    if (x==pre[x]) return x;
    return pre[x]=ffind(pre[x]);
}
void _union(int x,int y){
    x=ffind(x); y=ffind(y);
    if (x!=y) pre[y]=x;
}
void dfs1(int u){
    vis[u]=1;
    for (auto v:G[u]){
        if (vis[v]) continue;
        dfs1(v);
    }
}
void dfs2(int u){
    vis[u]=1;
    for (auto v:H[u]){
        if (vis[v]) continue;
        dfs2(v);
    }
}
bool ir[maxn];
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) G[i].clear(),H[i].clear();
        for (int i=1;i<=m;i++){
            int u,v;scanf("%d%d",&u,&v);
            G[u].pb(v); H[v].pb(u);
        }
        for (int i=1;i<=n;i++) f[i]=1,vis[i]=0;
        dfs1(1);
        for (int i=1;i<=n;i++) f[i]&=vis[i],vis[i]=0;
        dfs2(n);
        for (int i=1;i<=n;i++) f[i]&=vis[i];
        for (int i=1;i<=n;i++) pre[i]=i;
        for (int i=1;i<=n;i++) if (f[i]){
            int last=-1; 
            for (auto j:H[i]){
                if (!f[j]) continue;
                if (last!=-1) _union(last,j); 
                last=j; 
            }
            p[i]=last;
        }
        if (!f[1]){
            puts("Yes");
            for (int i=1;i<=n;i++) printf("1 ");puts("");
        }
        for (int i=1;i<=n;i++) if (f[i]&&ffind(i)==i) ir[i]=1; else ir[i]=0;
        for (int i=1;i<=n;i++) deg[i]=0,F[i].clear();
        for (int i=1;i<=n;i++) if (f[i])
            for (auto j:G[i]) if (f[j]){
                int u=ffind(i),v=ffind(j);
                F[u].pb(v); deg[v]++;
            }
        queue<int> Q; 
        for (int i=1;i<=n;i++) val[i]=-1;
        int cur=0; 
        for (int i=1;i<=n;i++) if (ir[i]&&!deg[i]) Q.push(i),val[i]=++cur;
        while (!Q.empty()){
            int u=Q.front(); Q.pop();
            for (auto v:F[u]){
                deg[v]--;
                if (!deg[v]) Q.push(v),val[v]=++cur;
            }
        }
        for (int i=2;i<=n;i++) if (f[i]) val[i]=val[ffind(i)];
        ans[1]=1; 
        for (int i=2;i<=n;i++) if (!f[i]) ans[i]=1; else ans[i]=val[i]-val[p[i]];
        bool flag=1;
        for (int i=1;i<=n;i++) flag&=(ans[i]>0);
        if (!flag){puts("No");}
        else {
            puts("Yes");
            for (int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
        }
    }
    return 0;
}