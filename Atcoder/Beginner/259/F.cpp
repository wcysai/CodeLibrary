#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,d[MAXN];
vector<P> G[MAXN];
ll f[MAXN],g[MAXN];
void dfs(int v,int p)
{
    for(auto e:G[v])
    {
        int to=e.F,cost=e.S;
        if(to==p) continue;
        dfs(to,v);
    }
    ll sum=0;
    vector<ll> inc;
    for(auto e:G[v])
    {
        int to=e.F,cost=e.S;
        if(to==p) continue;
        sum+=f[to]; 
        inc.push_back(g[to]-f[to]+cost);
    }
    sort(inc.begin(),inc.end(),greater<ll>());
    if(d[v]==0) {f[v]=sum; g[v]=-INF; return;}
    for(int i=0;i<d[v]-1;i++)
    {
        if(i>=(int)inc.size()) break;
        sum+=max(0LL,inc[i]);
    }
    g[v]=sum;
    if(d[v]-1<(int)inc.size()) sum+=max(0LL,inc[d[v]-1]);
    f[v]=sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(P(v,w)); G[v].push_back(P(u,w));
    }
    dfs(1,0);
    printf("%lld\n",f[1]);
    return 0;
}

