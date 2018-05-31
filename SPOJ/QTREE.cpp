#include<bits/stdc++.h>
#define MAXN 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge
{
    int to,cost;
};
struct node
{
    int l,r,maxi;
};
int t,tot,n,k,a[MAXN],u[MAXN],v[MAXN],cost[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
struct segtree
{
    node seg[4*MAXN];
    int id[MAXN];
    void build(int k,int l,int r)
    {
        seg[k].l=l;seg[k].r=r;
        if(l==r)
        {
            seg[k].maxi=a[tpos[l]];
            id[l]=k;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        seg[k].maxi=max(seg[k*2].maxi,seg[k*2+1].maxi);
    }      
    void update(int k,int x)
    {
        k=id[k];
        seg[k].maxi=x;
        while(k>1)
        {
            k=k/2;
            seg[k].maxi=max(seg[k*2].maxi,seg[k*2+1].maxi);
        }
    }
    int query1(int k,int l,int r)
    {
        if(seg[k].l>r||seg[k].r<l) return -INF;
        if(seg[k].l>=l&&seg[k].r<=r) return seg[k].maxi;
        return max(query1(k*2,l,r),query1(k*2+1,l,r));
    }
    int query_max(int l,int r) 
    {
        return query1(1,l,r);
    }
}tree;
vector<edge> G[MAXN];
void dfs1(int v,int p,int d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p) continue;
        a[to]=G[v][i].cost;
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
        int to=G[v][i].to;
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void init()
{
    tot=0;dfs1(1,1,1);
    dfs2(1,0,1);
    memset(a,0,sizeof(a));
    for(int i=0;i<n-1;i++)
    {
        u[i]=dep[u[i]]>dep[v[i]]?u[i]:v[i];
        a[u[i]]=cost[i];
    }
    tree.build(1,1,n);
}
void update(int k,int x)
{
    tree.update(spos[k],x);
}
int query_max(int u,int v)
{
    int res=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=max(res,tree.query_max(spos[top[u]],spos[u]));
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    if(u!=v) res=max(res,tree.query_max(spos[wson[v]],spos[u]));
    return res;
}
char str[10];
int x,y;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&cost[i]);
            G[u[i]].push_back((edge){v[i],cost[i]});G[v[i]].push_back((edge){u[i],cost[i]});
        }
        init();
        while(cin>>str)
        {
            if(str[0]=='D') break;
            scanf("%d%d",&x,&y);
            if(str[0]=='C') update(u[x-1],y);
            else printf("%d\n",query_max(x,y));
        }
    }
    return 0;
}



