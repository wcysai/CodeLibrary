#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int tot,q,n,k,a[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
ll delta[MAXN];
int T;
ll s;
int mult;
struct segtree
{
    int len[4*MAXN];
    ll sum[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void add(int k,int v)
    {
        lazy[k]+=v;
        sum[k]+=1LL*len[k]*v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        len[k]=r-l+1; lazy[k]=0;
        if(l==r)
        {
            sum[k]=0;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }      
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}tree;
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
    dfs1(1,1,0);
    dfs2(1,0,1);
    tree.build(1,1,n);
}
void update(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        tree.update(1,1,n,spos[top[u]],spos[u],2);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    tree.update(1,1,n,spos[v],spos[u],2);
}
ll query(int u,int v)
{
    ll res=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=tree.query(1,1,n,spos[top[u]],spos[u]);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    res+=tree.query(1,1,n,spos[v],spos[u]);
    return res;
}
ll get_res(int v)
{
    return s-1LL*mult*dep[v]+query(1,v)+delta[v];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) G[i].clear(),delta[i]=0;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        init();
        s=0; mult=0;
        for(int i=0;i<q;i++)
        {
            int opt,x,w;
            scanf("%d",&opt);
            if(opt==1)
            {
                scanf("%d%d",&x,&w);
                s+=w;
                mult++;
                s-=dep[x];
                s-=2;
                update(1,x);
            }
            else if(opt==2)
            {
                scanf("%d",&x);
                ll res=get_res(x);
                if(res>0) delta[x]-=res;
            }
            else 
            {
                scanf("%d",&x);
                printf("%lld\n",get_res(x));
            }
        }
    }
}
