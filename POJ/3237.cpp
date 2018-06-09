/*************************************************************************
    > File Name: 3237.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com
    > Created Time: 2018-06-10 00:21:44
 ************************************************************************/
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<map>
#include<queue>
#include<set>
#define MAXN 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct node
{
    int l,r,maxi,mini,lazy;
};
struct edge
{
    int to,cost;
};
vector<edge> G[MAXN];
int t,tot,q,n,k,a[MAXN],u[MAXN],v[MAXN],cost[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
struct segtree
{
    node seg[4*MAXN];
    int id[MAXN];
    void Lazy(int k)
    {
        if(!seg[k].lazy) return;
        if(seg[k].l!=seg[k].r)
        {
            for(int i=k*2;i<=k*2+1;i++)
            {
                int t=seg[i].maxi;
                seg[i].maxi=-seg[i].mini;
                seg[i].mini=-t;
                seg[i].lazy^=1;
            }
        }
        seg[k].lazy=0;
    }
    void merge(int k)
    {
        seg[k].maxi=max(seg[k*2].maxi,seg[k*2+1].maxi);
        seg[k].mini=min(seg[k*2].mini,seg[k*2+1].mini);
    }
    void build(int k,int l,int r)
    {
        seg[k].l=l;seg[k].r=r;seg[k].lazy=0;
        if(l==r)
        {
            seg[k].maxi=seg[k].mini=a[tpos[l]];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        merge(k);
    }
    void update1(int k,int l,int r,int x)
    {
        if(seg[k].l>r||seg[k].r<l) return;
        if(seg[k].l>=l&&seg[k].r<=r) {seg[k].maxi=seg[k].mini=x; return;}
        Lazy(k);
        update1(k*2,l,r,x);update1(k*2+1,l,r,x);
        merge(k);
    }
    void update2(int k,int l,int r)
    {
        if(seg[k].l>r||seg[k].r<l) return;
        if(seg[k].l>=l&&seg[k].r<=r)
        {
            int t=seg[k].maxi;
            seg[k].maxi=-seg[k].mini;
            seg[k].mini=-t;
            seg[k].lazy^=1;
            return;
        }
        Lazy(k);
        update2(k*2,l,r);update2(k*2+1,l,r);
        merge(k);
    }
    int query(int k,int l,int r)
    {
        if(seg[k].l>r||seg[k].r<l) return -INF;
        if(seg[k].l>=l&&seg[k].r<=r) return seg[k].maxi;
        Lazy(k);
        return max(query(k*2,l,r),query(k*2+1,l,r));
    }
}tree;
void dfs1(int v,int p,int d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
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
        int to=G[v][i].to;
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void init()
{
    tot=0;dfs1(1,1,1);
    dfs2(1,0,1);
    for(int i=0;i<n-1;i++)
    {
        u[i]=dep[u[i]]>dep[v[i]]?u[i]:v[i];
        a[u[i]]=cost[i];
    }
    tree.build(1,1,n);
}
int query_max(int u,int v)
{
    int res=-INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=max(res,tree.query(1,spos[top[u]],spos[u]));
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    if(u!=v) res=max(res,tree.query(1,spos[wson[v]],spos[u]));
    return res;
}
void _neg(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        tree.update2(1,spos[top[u]],spos[u]);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    if(u!=v) tree.update2(1,spos[wson[v]],spos[u]);
}
char str[10];
int x,y;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(wson,0,sizeof(wson));
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&cost[i]);
            G[u[i]].push_back((edge){v[i],cost[i]});G[v[i]].push_back((edge){u[i],cost[i]});
        }
        init();
        while(true)
        {
            scanf("%s",str);
            if(str[0]=='D') break;
            scanf("%d%d",&x,&y);
            if(str[0]=='C') tree.update1(1,spos[u[x-1]],spos[u[x-1]],y);
            else if(str[0]=='N') _neg(x,y);
            else printf("%d\n",query_max(x,y));
        }
    }
    return 0;
}
