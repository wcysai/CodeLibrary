#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int T,n,k;
vector<edge> G[MAXN];
int fa[MAXN];
ll f[MAXN],g[MAXN];
vector<ll> down[MAXN];
multiset<ll> ms;
void add_edge(int u,int v,int c)
{
    G[u].push_back((edge){v,c});
    G[v].push_back((edge){u,c});
}
void dfs(int v,int p)
{
    f[v]=0; fa[v]=p;
    down[v].clear();
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==p) continue;
        dfs(to,v);
        down[v].push_back(e.cost+f[to]);
    }
    sort(down[v].begin(),down[v].end(),greater<ll>());
    for(int i=0;i<min((int)down[v].size(),k-1);i++) f[v]+=down[v][i];
}
void dfs2(int v,int p)
{
    down[v].push_back(g[v]);
    sort(down[v].begin(),down[v].end(),greater<ll>());
    ll sum=0;
    ms.clear();
    for(int i=0;i<min((int)down[v].size(),k);i++) 
    {
        sum+=down[v][i];
        ms.insert(down[v][i]);
    }
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==p) continue;
        if(ms.count(f[to]+e.cost)) g[to]=sum-f[to]; else g[to]=sum-(*(ms.begin()))+e.cost;
    }
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==p) continue;
        dfs2(to,v);
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        ll s=0;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u,v,c);
            s+=c;
        }
        if(k==0) {puts("0"); continue;}
        dfs(1,0);
        dfs2(1,0);
        ll ans=-1;
        for(int i=1;i<=n;i++)
        {
            if((int)G[i].size()>k)
            {
                ll sum=g[i];
                for(auto e:G[i])
                {
                    int to=e.to,cost=e.cost;
                    if(to==fa[i]) continue;
                    sum+=cost+f[to];
                }
                ans=max(ans,sum);
            }
        }
        if(ans==-1) printf("%lld\n",s); else printf("%lld\n",ans);
    }
    return 0;
}

