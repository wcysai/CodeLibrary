#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN],sz[MAXN],dp[MAXN][MAXN][2];
ll cur[MAXN][2],upd[MAXN][2];
vector<int> G[MAXN];
void dfs(ll v,ll p)
{
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
    if(a[v]>0)
    {
        cur[0][0]=a[v];
        cur[0][1]=a[v];
    }
    else
    {
        cur[0][0]=INF;
        cur[0][1]=a[v];
    }
    for(auto to:G[v])
    {
        if(to==p) continue;
        for(ll i=0;i<n;i++) upd[i][0]=upd[i][1]=INF;
        for(ll j=0;j<sz[to];j++)
        {
            if(dp[to][j][0]!=INF)
            {
                for(ll i=0;i<sz[v];i++) if(cur[i][0]!=INF) upd[i+j][0]=min(upd[i+j][0],cur[i][0]+dp[to][j][0]);
                for(ll i=0;i<sz[v];i++) upd[i+j][1]=min(upd[i+j][1],cur[i][1]+dp[to][j][0]);
                for(ll i=0;i<sz[v];i++) if(cur[i][0]!=INF) upd[i+j+1][0]=min(upd[i+j+1][0],cur[i][0]);
                for(ll i=0;i<sz[v];i++) if(cur[i][1]!=INF) upd[i+j+1][1]=min(upd[i+j+1][1],cur[i][1]);
            }
            if(dp[to][j][1]!=INF)
            {
                for(ll i=0;i<sz[v];i++) if(cur[i][0]!=INF) upd[i+j][1]=min(upd[i+j][1],cur[i][0]+dp[to][j][1]);
                for(ll i=0;i<sz[v];i++) upd[i+j][1]=min(upd[i+j][1],cur[i][1]+dp[to][j][1]);
            }
            if(dp[to][j][1]<0)
            {
                for(ll i=0;i<sz[v];i++) if(cur[i][0]!=INF) upd[i+j+1][0]=min(upd[i+j+1][0],cur[i][0]);
                for(ll i=0;i<sz[v];i++) if(cur[i][1]!=INF) upd[i+j+1][1]=min(upd[i+j+1][1],cur[i][1]);
            }
        }
        sz[v]+=sz[to];
        for(ll i=0;i<sz[v];i++) cur[i][0]=upd[i][0],cur[i][1]=upd[i][1];
    }
    for(ll i=0;i<sz[v];i++) dp[v][i][0]=cur[i][0],dp[v][i][1]=cur[i][1];
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    ll ans=INF;
    for(ll i=0;i<=n-1;i++)
    {
        //printf("%lld %lld\n",dp[1][i][0],dp[1][i][1]);
        if(dp[1][i][0]!=INF) ans=min(ans,i);
        if(dp[1][i][1]<0) ans=min(ans,i);
    }
    printf("%lld\n",ans);
    return 0;
}

