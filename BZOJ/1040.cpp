/*************************************************************************
    > File Name: 1040.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-05 00:31:42
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN];
vector<ll> G[MAXN];
bool used[MAXN];
ll ans=0,U=-1,V=-1;
ll dp[MAXN][2];
void dfs(ll v,ll p)
{
    used[v]=true;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        if(used[to]) {U=to; V=v; continue;}
        dfs(to,v); 
    }
}
void dfs2(ll v,ll p)
{
    dp[v][0]=0;dp[v][1]=a[v];
    int cnt=0;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        if((v==V&&to==U)||(v==U&&to==V)) 
        {
            cnt++;
            if(cnt==1) continue;
        }   
        dfs2(to,v);
        dp[v][0]+=max(dp[to][0],dp[to][1]);
        dp[v][1]+=dp[to][0];
    }
}
void solve(ll v)
{
    dfs(v,0);
    ll res=0;
    dfs2(U,0);
    res=max(res,dp[U][0]);
    dfs2(V,0);
    res=max(res,dp[V][0]);
    ans+=res;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ll v;scanf("%lld",&v);G[v].push_back(i);G[i].push_back(v);
    }
    memset(used,false,sizeof(used));
    for(ll i=1;i<=n;i++) if(!used[i]) solve(i);
    printf("%lld\n",ans);
    return 0;
}

