/*************************************************************************
    > File Name: 4757.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 22:53:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 20
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int trie[MAXM][2],root[MAXN],sz[MAXM],fa[MAXN];
int tot;
int st[MAXLOGN+1][MAXN*2];
vector<int> G[MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
int newnode()
{
    ++tot;
    trie[tot][0]=trie[tot][1]=0;
    return tot;
}
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x,int y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n)
{
    for(int i=1;i<=n;++i) st[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(1,0,0,k);
    rmq_init(V*2-1);
}
int query(int l, int r)
{
    int k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
int lca(int u,int v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
void insert(int u,int v,int x)
{
    int now1=root[u],now2=root[v];
    for(int i=15;i>=0;i--)
    {
        int id=(x>>i)&1;
        trie[now1][id]=newnode();
        trie[now1][!id]=trie[now2][!id];
        now1=trie[now1][id];now2=trie[now2][id];
        sz[now1]=sz[now2]+1;
    }
}
int query(int u,int v,int x)
{
    int k=lca(u,v);
    int res=0;
    int now1=root[u],now2=root[v],now3=root[k];
    for(int i=15;i>=0;i--)
    {
        int id=(x>>i)&1;
        if(sz[trie[now1][!id]]+sz[trie[now2][!id]]-2*sz[trie[now3][!id]]>0)
        {
            res+=(1<<i);
            id=!id;
        }
        now1=trie[now1][id];now2=trie[now2][id];now3=trie[now3][id];
    }
    return max(res,x^a[k]);
}
void dfs2(int v,int p)
{
    root[v]=newnode();fa[v]=p;
    insert(v,p,a[v]);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs2(to,v);
    }
}
int main()
{
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=1;i<=tot;i++) sz[i]=0;
        tot=0;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[v].push_back(u);G[u].push_back(v);
        }
        init(n);
        dfs2(1,0);
        while(q--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",query(x,y,z));
        }
    }
    return 0;
}

