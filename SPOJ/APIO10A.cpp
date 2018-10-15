/*************************************************************************
    > File Name: APIO10A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-15 10:34:04
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
typedef pair<ll,ll> P;
ll T,n,t,now,A,B,C,a[MAXN],sum[MAXN];
ll dp[MAXN];
P st[MAXN];
ll get(P u,P v) {return (v.S-u.S)/(u.F-v.F);}
void add(ll u,ll v)
{
    P p=P(u,v);
    while(t-now>1&&get(st[t-1],p)<=get(st[t-1],st[t-2])) t--;
    st[t++]=p;
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        t=0;now=0;
        scanf("%lld",&n);
        scanf("%lld%lld%lld",&A,&B,&C);
        for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        for(ll i=1;i<=n;i++)
        {
            add(-2*A*sum[i-1],dp[i-1]+A*sum[i-1]*sum[i-1]-B*sum[i-1]);
            while(t-now>1&&get(st[now],st[now+1])<sum[i]) now++;
            dp[i]=st[now].F*sum[i]+st[now].S+A*sum[i]*sum[i]+B*sum[i]+C;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}

