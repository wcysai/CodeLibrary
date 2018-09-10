/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-10 10:40:40
 ************************************************************************/

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
ll n,k;
vector<ll> G[MAXN],val[MAXN];
ll score[MAXN],dp[MAXN];
void dfs(ll v,ll p)
{
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
        val[v].push_back(dp[to]);
    }
    sort(val[v].rbegin(),val[v].rend());
    ll ans=score[1],sum=0;
    for(ll i=0;i<(int)val[v].size();i++)
    {
        sum+=val[v][i];
        ans=max(ans,sum+score[i+2]);
    }
    dp[v]=ans;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) scanf("%lld",&score[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    ll ans=score[0],sum=0;
    for(ll v=1;v<=n;v++)
    {
        sum=0;
        for(ll i=0;i<(int)val[v].size();i++)
        {
            sum+=val[v][i];
            ans=max(ans,sum+score[i+1]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

