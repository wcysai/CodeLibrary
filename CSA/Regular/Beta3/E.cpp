/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 14:45:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
vector<int> G[MAXN];
ll R,B,cnt1,cnt2,ans;
char str[MAXN+1];
ll dep[MAXN],cnt[MAXN],mx;
ll delta[MAXN],dp[MAXN];
void dfs(ll v,ll p,ll d)
{
    dep[v]=d;cnt[d]++;mx=max(mx,d);
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs(to,v,d+1);
    }
}
void solve1(ll v,ll p)
{
    if(str[v]=='R'&&(dep[v]&1)) delta[v]=1;
    else if(str[v]=='B'&&(dep[v]%2==0)) delta[v]=-1;
    else delta[v]=0;
    dp[v]=0;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        solve1(to,v);
        dp[v]+=dp[to]+abs(delta[to]);
        delta[v]+=delta[to];
    }
}
void solve2(ll v,ll p)
{
    if(str[v]=='B'&&(dep[v]&1)) delta[v]=-1;
    else if(str[v]=='R'&&(dep[v]%2==0)) delta[v]=1;
    else delta[v]=0;
    dp[v]=0;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        solve2(to,v);
        dp[v]+=dp[to]+abs(delta[to]);
        delta[v]+=delta[to];
    }
}
int main()
{
    scanf("%lld",&n);
    scanf("%s",str+1);
    for(ll i=1;i<=n;i++)
        if(str[i]=='B') B++; else R++;
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    ans=INF;
    dfs(1,0,0);
    for(ll i=0;i<=mx;i++)
        if(i&1) cnt1+=cnt[i]; else cnt2+=cnt[i];
    if(cnt1==B&&cnt2==R)
    {
        solve1(1,0);
        assert(delta[1]==0);
        ans=min(ans,dp[1]);
    }
    if(cnt1==R&&cnt2==B)
    {
        solve2(1,0);
        assert(delta[1]==0);
        ans=min(ans,dp[1]);
    }
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}

