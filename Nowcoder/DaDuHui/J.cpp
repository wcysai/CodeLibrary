/*************************************************************************
    > File Name: J.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-05 12:01:55
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
ll t,n,a[15];
ll dp[15][130][130];
ll mod;
ll dfs(ll now,ll sum,ll rem,bool limit)
{
    if(now==-1) return(sum==mod&&!rem);
    if(dp[now][sum][rem]!=-1&&!limit) return dp[now][sum][rem];
    ll ed=limit?a[now]:9;
    ll res=0;
    for(ll i=0;i<=ed;i++)
    {
        if(i+sum>mod) break;
        res+=dfs(now-1,sum+i,(rem*10+i)%mod,limit&&i==a[now]);
    }
    if(!limit) dp[now][sum][rem]=res;
    return res;
}
int main()
{
    scanf("%lld",&t);
    ll tot=0;
    while(t--)
    {
        tot++;printf("Case %lld: ",tot);
        scanf("%lld",&n);
        ll tt=0;
        while(n) a[tt++]=n%10,n=n/10; 
        ll ans=0;
        for(ll i=1;i<=9*tt;i++)
        {
            mod=i;
            memset(dp,-1,sizeof(dp));
            ans+=dfs(tt-1,0,0,true);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

