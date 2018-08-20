/*************************************************************************
    > File Name: 4326.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-20 08:58:29
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define MAXLOGN 23
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],dd[MAXN];
int st[MAXLOGN][2*MAXN];
vector<P> G[MAXN];
int vs[MAXN*2-1],mx;
int depth[MAXN*2-1],dep[MAXN];
int id[MAXN];
int u[MAXN],v[MAXN],len[MAXN];
void dfs(int v,int p,int d,int cost,int pa,int &k)
{
    id[v]=k;dep[v]=cost;
    vs[k]=v;dd[v]=pa;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i].F!=p)
        {
            dfs(G[v][i].F,v,d+1,cost+G[v][i].S,G[v][i].S,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x, int y)
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
    dfs(1,0,0,0,0,k);
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
int dis(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
void dfs2(int v,int p)
{
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].F;
        if(to==p) continue;
        dfs2(to,v);
        a[v]+=a[to];
    }
}
bool C(int x)
{
    if(x>=mx) return true;
    for(int i=1;i<=n;i++) a[i]=0;
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(len[i]<=x) continue;
        cnt++;
        int l=lca(u[i],v[i]);
        a[u[i]]++;a[v[i]]++;a[l]-=2;
    }
    dfs2(1,0);
    for(int i=2;i<=n;i++)
    {
        if(a[i]==cnt)
        {
            if(dd[i]>=mx-x) return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(P(v,w));G[v].push_back(P(u,w));
    }
    init(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        len[i]=dis(u[i],v[i]);mx=max(mx,len[i]);
    }
    int l=-1,r=1000000000;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%d\n",r);
    return 0;
}
