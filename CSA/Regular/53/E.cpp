/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-09 21:41:58
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN (1<<17)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll cnt[MAXN],dp[MAXN];
int main()
{
    scanf("%lld",&n);
    memset(cnt,0,sizeof(cnt));
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        cnt[a[i]]++;
    }
    for(ll i=0;i<17;i++)
        for(ll j=0;j<(1<<17);j++)
            if(!(j&(1<<i))) cnt[j]+=cnt[j^(1<<i)];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<(1<<17);i++) if(cnt[i]) dp[i]=i;
    for(ll i=0;i<17;i++)
        for(ll j=0;j<(1<<17);j++)
            if(j&(1<<i)) dp[j]=max(dp[j],dp[j^(1<<i)]);
    ll now=0,ans=0;
    for(ll i=0;i<n;i++)
    {
        ll mask=(1<<17)-1-a[i],cur=cnt[dp[mask]];
        if(dp[mask]==0) cur--;
        if((dp[mask]|a[i])>now)
        {
            ans=cur;
            now=dp[mask]|a[i];
        }
        else if((dp[mask]|a[i])==now) ans+=cur;
    }
    printf("%lld %lld\n",now,ans/2);
    return 0;
}

