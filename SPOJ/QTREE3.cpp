/*************************************************************************
    > File Name: QTREE3.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 01:57:04
 ************************************************************************/

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
struct node
{
    int l,r,num;
};
int tot,q,n,k,id[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
struct segtree
{
    node seg[4*MAXN];
    int id[MAXN];
    void build(int k,int l,int r)
    {
        seg[k].l=l;seg[k].r=r;seg[k].num=INF;
        if(l==r)
        {
            id[l]=k;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
    }      
    void update(int k)
    {
        int l=k;
        k=id[k];
        if(seg[k].num==INF) seg[k].num=l;else seg[k].num=INF;
        while(k>1)
        {
            k=k/2;
            seg[k].num=min(seg[k*2].num,seg[k*2+1].num);
        }
    }
    int query(int k,int l,int r)
    {
        if(seg[k].l>r||seg[k].r<l) return INF;
        if(seg[k].l>=l&&seg[k].r<=r) return seg[k].num;
        return min(query(k*2,l,r),query(k*2+1,l,r));
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
    tot=0;dfs1(1,1,1);
    dfs2(1,0,1);
    tree.build(1,1,n);
}
int query(int u)
{
    int res=INF;
    while(top[u]!=1)
    {
        int x=tree.query(1,spos[top[u]],spos[u]);
        if(x!=INF) res=x;     
        u=pa[top[u]];
    }
    int x=tree.query(1,spos[1],spos[u]);
    if(x!=INF) res=x;
    if(res==INF) return -1; else return tpos[res];
}
int x,y;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    init();
    while(q--)
    {
        scanf("%d%d",&x,&y);
        if(x==0) tree.update(spos[y]);
        else printf("%d\n",query(y));
    }
    return 0;
}

