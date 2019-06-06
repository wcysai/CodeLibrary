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
int n,m;
struct edge{int to; ll cost;};
vector<edge> G[MAXN];
ll val[MAXN];
bool vis[MAXN];
vector<ll> basis;
void add_edge(int u,int v,ll cost)
{
    G[u].push_back((edge){v,cost});
    G[v].push_back((edge){u,cost});
}
void dfs(int v)
{
    vis[v]=true;
    for(auto e:G[v])
    {
        int to=e.to; ll cost=e.cost;
        if(vis[to]) basis.push_back(cost^val[to]^val[v]);
        else
        {
            val[to]=val[v]^cost;
            dfs(to);
        }
    }
}
ll bas[MAXN],a[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v; ll w;
        scanf("%d%d%lld",&u,&v,&w);
        add_edge(u,v,w);
    }
    dfs(1);
    for(int i=0;i<(int)basis.size();i++)
    {
        ll x=basis[i];
        for(int j=60;j>=0;j--)
        {
            if(x&(1LL<<j))
            {
                if(!bas[j])
                {
                    bas[j]=x;
                    break;
                }
                x^=bas[j];
            }
        }
    }
    ll ans=0;
    for(int j=60;j>=0;j--)
    {
        if(!(ans&(1LL<<j)))
        {
            if(bas[j]) ans^=bas[j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}

