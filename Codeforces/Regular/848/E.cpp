#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 19
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,k,a[MAXN];
vector<int> G[MAXN];
vector<int> f[MAXN];
vector<int> g[MAXN];
void ins(vector<int> &v,int x){
    for(int i=29;i>=0;i--){
        if(x&(1<<i)){
            if(!v[i]){
                v[i]=x;
                break;
            }
            x^=v[i];
        }
    }
}
void merge(vector<int> &v1,vector<int> &v2){
    for(int i=29;i>=0;i--) if(v2[i]) ins(v1,v2[i]);
}
int calc(vector<int> &v){
    int x=0;
    for(int i=29;i>=0;i--)
        if(v[i]&&(!(x&(1<<i)))) x^=v[i];
    return x;
}
void dfs1(int v,int p){
    ins(f[v],a[v]);
    for(auto to:G[v]){
        if(to==p) continue;
        dfs1(to,v);
        merge(f[v],f[to]);
    }
}
void dfs2(int v,int p){
    vector<vector<int> > pre,suf;
    vector<int> son;
    for(auto to:G[v]){
        if(to==p) continue;
        ins(g[to],a[v]); merge(g[to],g[v]);
        son.push_back(to);
    }
    int sz=(int)son.size();
    vector<int> tmp; 
    tmp.resize(30);
    pre.push_back(tmp);
    for(int i=0;i<sz;i++){
        merge(tmp,f[son[i]]);
        pre.push_back(tmp);
    }
    for(int i=0;i<30;i++) tmp[i]=0;
    suf.push_back(tmp);
    for(int i=sz-1;i>=0;i--){
        merge(tmp,f[son[i]]);
        suf.push_back(tmp);
    }
    int tot=0;
    for(auto to:G[v]){
        if(to==p) continue;
        merge(g[to],pre[tot]); merge(g[to],suf[sz-1-tot]);
        tot++;
    }
    for(auto to:G[v]) {
        if(to==p) continue;
        dfs2(to,v);
    }
}
int pa[MAXLOGN][MAXN];
int depth[MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) {
            f[i].clear(); f[i].resize(30);
            g[i].clear(); g[i].resize(30);
        }
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n-1;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        init(n);
        dfs1(1,0); dfs2(1,0);
        scanf("%d",&q);
        while(q--){
            int r,v;
            scanf("%d%d",&r,&v);
            if(r==v) printf("%d\n",calc(f[1]));
            else
            {
                int l=lca(r,v);
                if(l==v){
                    int z=get(r,depth[r]-depth[v]-1);
                    printf("%d\n",calc(g[z]));
                }
                else{
                    printf("%d\n",calc(f[v]));
                }
            }
        }
    }
    return 0;
}

