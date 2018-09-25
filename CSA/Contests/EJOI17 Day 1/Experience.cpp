/*************************************************************************
    > File Name: Experience.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-25 14:56:36
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
ll n,a[MAXN];
vector<int> G[MAXN];
ll dp[MAXN][2];//dp[v][0]:increase dp[v][1]:decrease
void solve(ll v,ll p)
{
    ll s=0;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        solve(to,v);
        s+=max(dp[to][0],dp[to][1]);
    }
    dp[v][0]=dp[v][1]=s;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        if(a[to]>a[v]) dp[v][0]=max(dp[v][0],s-max(dp[to][0],dp[to][1])+a[to]-a[v]+dp[to][0]);
        if(a[to]<a[v]) dp[v][1]=max(dp[v][1],s-max(dp[to][0],dp[to][1])+a[v]-a[to]+dp[to][1]);
    }
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
    solve(1,0);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
    return 0;
}

