/*************************************************************************
    > File Name: 3345.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-23 07:01:13
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
#define INF 100000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
vector<edge> G[MAXN];
int n,q,root,a[MAXN],st[MAXLOGN][MAXN],vs[MAXN*2-1],depth[MAXN*2-1],dist[MAXN],id[MAXN],sz[MAXN],d[MAXN];
int fa[MAXN];
ll sum[MAXN],sum1[MAXN],sum2[MAXN];
bool centroid[MAXN];
inline int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
void dfs(int v,int p,int d,int &k,int Dist)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    dist[v]=Dist;
    //printf("%d %d\n",v,dist[v]);
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i].to!=p)
        {
            dfs(G[v][i].to,v,d+1,k,Dist+G[v][i].cost);
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
    dfs(1,0,0,k,0);
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
    return dist[u]+dist[v]-2*dist[lca(u,v)];
}
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void solve(int v,int p)
{
    centroid[v]=true;
    fa[v]=p;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(centroid[to]) continue;
        root=getroot(to,v,sz[to]).S;
        solve(root,v);
    }
    root=v;
}
void pre()
{
    init(n);
    root=getroot(1,0,n).S;
    solve(root,0);
}
void update(int v,int dlt)
{
    int t=v;
    sum[v]+=dlt;
    while(fa[v])
    {
        int dist=dis(fa[v],t);
        sum2[v]+=1LL*dlt*dist;
        sum1[fa[v]]+=1LL*dlt*dist;
        sum[fa[v]]+=dlt;
        v=fa[v];
    }
}
ll query2(int v)
{
    ll ans=sum1[v];
    int t=v;
    while(fa[v])
    {
        ans+=1LL*(sum[fa[v]]-sum[v])*dis(fa[v],t)+sum1[fa[v]]-sum2[v];
        v=fa[v];
    }
    return ans;
}
ll Query(int v)
{
    ll ans=query2(v);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(query2(to)<ans) return Query(to);
    }
    return ans;
}
int main()
{
    n=read();q=read();    
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        u=read();v=read();w=read();
        G[u].push_back((edge){v,w});G[v].push_back((edge){u,w});
    }
    pre();
    //printf("%d\n",dis(2,8));
    //printf("%d\n",lca(2,8));
    for(int i=0;i<q;i++)
    {
        int u,v;
        u=read();v=read();
        update(u,v);
        //printf("%d\n",query2(2));
        printf("%lld\n",Query(root));
    }
    return 0;
}
