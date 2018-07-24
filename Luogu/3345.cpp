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
int n,q,tot,ss,root,st[MAXLOGN][MAXN],vs[MAXN*2-1],dist[MAXN],sz[MAXN],f[MAXN];
int fa[MAXN];
ll sum[MAXN],sum1[MAXN],sum2[MAXN];
vector<edge> CDT[MAXN];
bool centroid[MAXN];
inline int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
void dfs(int v,int p)
{
    st[0][++tot]=dist[v];vs[v]=tot;
    //printf("%d %d\n",v,dist[v]);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to!=p)
        {
            dist[to]=dist[v]+G[v][i].cost;
            dfs(to,v);
            st[0][++tot]=dist[v];
        }
    }
}

void rmq_init(int n)
{
    for(int i=1;1<<i<=n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    tot=0;
    dfs(1,0);
    rmq_init(V*2-1);
}

int dis(int u,int v)
{
    if(vs[u]>vs[v]) swap(u,v);
    int k=31-__builtin_clz(vs[v]-vs[u]+1);
    return dist[u]+dist[v]-2*min(st[k][vs[u]],st[k][vs[v]-(1<<k)+1]);
}
void getroot(int v,int p)
{
    sz[v]=1;f[v]=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(centroid[to]||to==p) continue;
        getroot(to,v);sz[v]+=sz[to];
        f[v]=max(f[v],sz[to]);
    }
    f[v]=max(f[v],ss-sz[v]);
    if(f[v]<f[root])root=v;
}
void solve(int v,int p)
{
    centroid[v]=true;
    fa[v]=p;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(centroid[to]) continue;
        ss=sz[to];f[0]=sz[to];root=0;
        getroot(to,0);CDT[v].push_back((edge){root,to});
        solve(root,v);
    }
    root=v;
}
void pre()
{
    init(n);
    ss=n;f[0]=n;root=0;
    getroot(1,0);
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
    for(int i=0;i<(int)CDT[v].size();i++)
    {
        int to=CDT[v][i].to,cost=CDT[v][i].cost;
        if(query2(cost)<ans) return Query(to);
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
    //printf("%d\n",root);
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
