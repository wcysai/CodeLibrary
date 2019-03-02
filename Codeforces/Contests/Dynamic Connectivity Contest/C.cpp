#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,q,n,m,k,a[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
int ans=0;
vector<P> vec;
struct segtree
{
    int sum[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushdown(int k,int l,int r)
    {
        if(lazy[k]==-1) return;
        int mid=(l+r)/2;
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        sum[k*2]=(mid-l+1)*lazy[k];
        sum[k*2+1]=(r-mid)*lazy[k];
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1;
        if(l==r)
        {
            sum[k]=0;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }      
    void update1(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            ans-=(r-l+1)-sum[k];
            sum[k]=(r-l+1);lazy[k]=1;
            return;
        }
        pushdown(k,l,r);
        int mid=(l+r)/2;
        update1(k*2,l,mid,x,y);update1(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    void update2(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            ans+=sum[k];
            sum[k]=0;lazy[k]=0;
            return;
        }
        pushdown(k,l,r);
        int mid=(l+r)/2;
        update2(k*2,l,mid,x,y);update2(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
}tree;
vector<int> G[MAXN];
void dfs1(int v,int p,int d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs1(to,v,d+1);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int num)
{
    top[v]=num;
    spos[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void init()
{
    tot=0;
    memset(wson,0,sizeof(wson));//important when multiple test cases!!!
    dfs1(1,1,1);
    dfs2(1,0,1);
    tree.build(1,1,n);
}
void add_edge(int u,int v)
{
    if(u==v) return;
    vec.push_back(P(u,v));
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        tree.update1(1,1,n,spos[top[u]],spos[u]);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    tree.update1(1,1,n,spos[wson[v]],spos[u]);
}
void erase_edge(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        tree.update2(1,1,n,spos[top[u]],spos[u]);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    tree.update2(1,1,n,spos[wson[v]],spos[u]);
}
void clear()
{
    for(auto p:vec) erase_edge(p.F,p.S);
    vec.clear();
}
int main()
{
    freopen("bridges2.in","r",stdin);
    freopen("bridges2.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        G[i].push_back(x);G[x].push_back(i);
    }
    init();
    ans=n-1;
    for(int i=0;i<m;i++)
    {
        int k;scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        printf("%d\n",ans);
        clear();
        assert(ans==n-1);
    }
    return 0;
}

