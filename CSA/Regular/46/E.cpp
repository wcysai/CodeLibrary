/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-05 18:30:40
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
ll n,d,a[MAXN];
ll L[MAXN],R[MAXN];
ll dp[MAXN],st[MAXN],sum[MAXN];
ll solve(ll x)
{
    if(dp[x]!=-1) return dp[x];
    if(L[x]==0&&R[x]==n+1) return dp[x]=1;
    ll s=sum[R[x]-1]-sum[L[x]];
    if(L[x]!=0&&s+d>=a[L[x]]&&solve(L[x])==1) return dp[x]=1;
    if(R[x]!=0&&s+d>=a[R[x]]&&solve(R[x])==1) return dp[x]=1;
    return dp[x]=0;
}
int main()
{
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    memset(dp,-1,sizeof(dp));
    ll t=0;
	for(ll i=1;i<=n;i++)
	{
		while(t>0&&a[st[t-1]]<=a[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(ll i=n;i>=1;i--)
	{
		while(t>0&&a[st[t-1]]<=a[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
    for(ll i=1;i<=n;i++) if(dp[i]==-1) solve(i);
    for(ll i=1;i<=n;i++) if(dp[i]==1) printf("%lld ",i);
    return 0;
}

