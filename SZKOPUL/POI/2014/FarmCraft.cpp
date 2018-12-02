/*************************************************************************
    > File Name: FarmCraft.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-02 21:01:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,c[MAXN],dp[MAXN],sz[MAXN];
vector<int> G[MAXN];
struct app
{
    ll t,sz;
};
bool cmp(app x,app y)
{
    return max(x.t,2*x.sz+y.t)<max(y.t,2*y.sz+x.t);
}
void dfs(ll v,ll p)
{
    sz[v]=1;
    static vector<app> vec;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
    vec.clear();
    for(auto to:G[v])
    {
        if(to==p) continue;
        vec.push_back((app){dp[to],sz[to]});
    }
    sort(vec.begin(),vec.end(),cmp);
    ll cur=0,ans=0;
    for(ll i=0;i<(int)vec.size();i++) 
    {
        ans=max(ans,cur+1+vec[i].t);
        cur+=2*vec[i].sz;
    }
    dp[v]=max(c[v],ans);
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    //for(int i=1;i<=n;i++) printf("%lld %lld\n",i,dp[i]);
    printf("%lld\n",max(dp[1],c[1]+2*(n-1)));
    return 0;
}

