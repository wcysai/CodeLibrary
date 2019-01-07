#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,M,f[MAXN],g[MAXN],ans[MAXN];
vector<int> G[MAXN];
void add_edge(ll u,ll v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(ll v,ll p)
{
    f[v]=1;
    vector<int> pre,suf;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        f[v]=1LL*f[v]*(f[to]+1)%M;
    }
    pre.clear();suf.clear();
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        pre.push_back(f[to]+1); suf.push_back(f[to]+1);
    }
    ll sz=(int)pre.size();
    if(sz==0) return;
    if(sz==1)
    {
        for(auto to:G[v]) 
        {
            if(to==p) continue;
            else g[to]=1;
        }
        return;
    }
    for(ll i=1;i<sz;i++) pre[i]=1LL*pre[i-1]*pre[i]%M;
    for(ll i=sz-2;i>=0;i--) suf[i]=1LL*suf[i+1]*suf[i]%M;
    ll cnt=0;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        if(cnt==0) g[to]=suf[1]%M;
        else if(cnt==sz-1) g[to]=pre[sz-2]%M;
        else g[to]=1LL*pre[cnt-1]*suf[cnt+1]%M;
        cnt++;
    }
}
void dfs2(ll v,ll p)
{
    ans[v]=1LL*f[v]*(g[v]+1)%M;
    for(auto to:G[v])
    {
        if(to==p) continue;
        g[to]=1LL*g[to]*(g[v]+1)%M;
        dfs2(to,v);
    }
}
int main()
{
    scanf("%lld%lld",&n,&M);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);add_edge(u,v);
    }
    dfs(1,0);
    g[1]=0;dfs2(1,0);
    for(ll i=1;i<=n;i++) printf("%lld\n",ans[i]%M);
    return 0;
}

