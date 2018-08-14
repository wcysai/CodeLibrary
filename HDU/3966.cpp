/*************************************************************************
    > File Name: 3966.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-14 00:18:25
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,q,n,m,k,a[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
deque<int> G[MAXN];
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}
struct segtree
{
    int val[4*MAXN],lazy[4*MAXN];
    void Lazy(int k)
    {
        lazy[k*2]+=lazy[k];lazy[k*2+1]+=lazy[k];
        val[k*2]+=lazy[k];val[k*2+1]+=lazy[k];
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r) {val[k]=tpos[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        val[k]=max(val[k*2],val[k*2+1]);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y) 
        {
            val[k]+=v;
            lazy[k]+=v;
            return;
        }
        Lazy(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v);update(k*2+1,mid+1,r,x,y,v);
        val[k]=max(val[k*2],val[k*2+1]);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return -INF;
        if(l>=x&&r<=y) return val[k];
        Lazy(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
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
    tot=0;dfs1(1,1,1);
    dfs2(1,0,1);
    tree.build(1,1,n);
}
void update(int u,int v,int x)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        tree.update(1,1,n,spos[top[u]],spos[u],x);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    tree.update(1,1,n,spos[v],spos[u],x);
}
int query(int v)
{
    return tree.query(1,1,n,spos[v],spos[v]);
}
char ch[5];
int main()
{
    while(scanf("%d%d%d",&n,&m,&q)==3)
    {
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) in(a[i]);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            in(u);in(v);
            G[u].push_back(v);G[v].push_back(u);
        }
        init();
        int x,y,v;
        for(int i=0;i<q;i++)
        {
            scanf("%s",ch);
            if(ch[0]=='Q')
            {
                in(x);
                printf("%d\n",query(x));
            }
            else
            {
                in(x);in(y);in(v);
                if(ch[0]=='D') v=-v;
                update(x,y,v);
            }
        }
    }
    return 0;
}

