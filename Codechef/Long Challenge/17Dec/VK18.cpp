#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
ll n,t,k;
ll a[MAXN];
ll dp[2*MAXN],sum[2*MAXN];
ll res[MAXN];
ll cal(ll x)
{
    ll s=0;
    while(x>0)
    {
        if((x%10)&1) s+=x%10; else s-=x%10;
        x=x/10;
    }
    return max(s,-s);
}
int main()
{
    for(ll i=2;i<2*MAXN;i++)
        dp[i]=cal(i);
    sum[1]=0;
    for(ll i=2;i<2*MAXN;i++)
        sum[i]=sum[i-1]+dp[i];
    res[1]=2;
    for(ll i=2;i<MAXN;i++)
        res[i]=res[i-1]+2*(sum[2*i]-sum[i])-dp[2*i];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",res[n]);
    }
    return 0;
}
