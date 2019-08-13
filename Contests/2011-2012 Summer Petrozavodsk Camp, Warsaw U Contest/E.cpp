#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
vector<int> G[MAXN];
ll sz[MAXN],maxd[MAXN],maxi[MAXN],dp[MAXN];
void dfs(ll v,ll p)
{
    sz[v]=1;
    maxi[v]=-INF;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
        maxi[v]=max(sz[to],maxi[v]);
    }
}
void dfs2(ll v,ll p,ll d)
{
    dp[v]=0;
    sz[v]=1;
    maxd[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v,d+1);
        sz[v]+=sz[to];
        dp[v]+=dp[to]+2*sz[to];
        maxd[v]=max(maxd[v],maxd[to]);
    }
}
ll ans[MAXN];
int main()
{
    freopen("inspection.in","r",stdin);
    freopen("inspection.out","w",stdout);
    scanf("%lld",&n);
    if(n==1)
    {
        puts("0");
        return 0;
    }
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(ll i=2;i<=n;i++) maxi[i]=max(maxi[i],n-sz[i]);
    memset(ans,-1,sizeof(ans));
    for(ll i=1;i<=n;i++)
    {
        if(maxi[i]<=n/2)
        {
            bool flag=true;
            if(maxi[i]*2==n) flag=false;
            ll res=-1;
            dfs2(i,0,0);
            for(auto to:G[i])
            {
                if(flag||maxi[to]*2==n) res=max(res,maxd[to]);
            }
            ans[i]=dp[i]-res;
        }
    }
    for(ll i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}
