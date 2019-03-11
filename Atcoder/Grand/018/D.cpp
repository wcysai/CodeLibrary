#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
struct edge{int to,cost;};
int n;
vector<edge> G[MAXN];
int mincost[MAXN],sz[MAXN];
int id=-1;
ll ans,dp[MAXN];
ll res1=0,res2=0;
void add_edge(int u,int v,int w)
{
    G[u].push_back((edge){v,w});
    G[v].push_back((edge){u,w});
    mincost[u]=min(mincost[u],w);
    mincost[v]=min(mincost[v],w);
}
void dfs(int v,int p)
{
    sz[v]=1;
    bool f=true;
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v);
        if(sz[e.to]*2==n) res1=e.cost;
        if(sz[e.to]*2>=n) f=false; 
        sz[v]+=sz[e.to];
        dp[v]+=dp[e.to];
        dp[v]+=2LL*min(sz[e.to],(n-sz[e.to]))*e.cost;
    }
    if(2*(n-sz[v])>=n) f=false;
    if(f) res2=mincost[v];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) mincost[i]=INF;
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    dfs(1,0);
    if(res1) printf("%lld\n",dp[1]-res1); else printf("%lld\n",dp[1]-res2);
    return 0;
}

