#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 125
#define MAXM 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXM],b[MAXM],c[MAXM];
struct edge{int to,cost,id;};
vector<edge> G[MAXN];
int w[MAXM][MAXM];
int fa[MAXN],fcost[MAXN],fid[MAXN],dep[MAXN],tot;
vector<int> u,v;
void add_edge(int u,int v,int cost,int id)
{
    G[u].push_back((edge){v,cost,id});
    G[v].push_back((edge){u,cost,id});
}
//minimum weight bipartite matching
ll km(int n,int m)
{
    u.resize(n+1); v.resize(m+1);
    vector<int> p(m+1),way(m+1);
    for(int i=1;i<=n;i++) 
    {
        p[0]=i;
        int j0=0;
        vector<int> minv(m+1,INF);
        vector<char> used(m+1,false);
        do 
        {
            used[j0]=true;
            int i0=p[j0],delta=INF,j1=0;
            for(int j=1;j<=m;++j)
                if(!used[j]) 
                {
                    int cur=w[i0][j]-u[i0]-v[j];
                    if(cur<minv[j]) minv[j]=cur,way[j]=j0;
                    if(minv[j]<delta) delta=minv[j],j1=j;
                }
            for(int j=0;j<=m;++j) if(used[j]) u[p[j]]+=delta,v[j]-=delta; else minv[j]-=delta;
            j0=j1;
        }while(p[j0]!=0);
        do 
        {
            int j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
    ll res=0;
    for(int i=1;i<=m;i++) res+=w[p[i]][i];
    return -res;
}
void dfs(int v,int p,int d,int cost,int id)
{
    fa[v]=p; fcost[v]=cost; dep[v]=d; fid[v]=id;
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v,d+1,e.cost,e.id);
    }
}
void add_ntree_edge(int u,int v,int cost)
{
    ++tot;
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v])
    {
        if(cost<fcost[u]) w[fid[u]][tot]=cost-fcost[u];
        u=fa[u];
    }
    while(u!=v)
    {
        if(cost<fcost[u]) w[fid[u]][tot]=cost-fcost[u]; 
        if(cost<fcost[v]) w[fid[v]][tot]=cost-fcost[v];
        u=fa[u]; v=fa[v];
    }
}
int main()
{
    freopen("roads.in","r",stdin);
    freopen("roads.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        if(i<=n-1) add_edge(a[i],b[i],c[i],i);
    }
    dfs(1,0,0,0,0);
    for(int i=n;i<=m;i++) add_ntree_edge(a[i],b[i],c[i]);
    int need=max(n-1,tot);
    km(need,need);
    for(int i=1;i<=n-1;i++) c[i]+=u[i];
    for(int i=1;i<=tot;i++) c[n-1+i]-=v[i];
    for(int i=1;i<=m;i++) printf("%d\n",c[i]);
    return 0;
}

