/*************************************************************************
    > File Name: CCIRCLES.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-07 04:16:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,Q,x[MAXN],y[MAXN],r[MAXN],K;
ll ans[1000005];
ll _sqrt(ll x)
{
    ll L=0,R=600001;
    while(R-L>1)
    {
        ll mid=(L+R)/2;
        if(mid*mid<=x) L=mid; else R=mid;
    }
    return L;
}
int main()
{
    scanf("%lld%lld",&N,&Q);
    for(ll i=0;i<N;i++) scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
    for(ll i=0;i<N;i++)
        for(ll j=i+1;j<N;j++)
        {
            ll d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            ll cur=_sqrt(d);
            ll gR=max(r[i],r[j]),sR=min(r[i],r[j]);
            if((gR+sR)*(gR+sR)<=d)
            {
                ll L=cur-gR-sR,R=cur+gR+sR;
                if(cur*cur!=d) L++;
                ans[L]++;ans[R+1]--;
            }
            else if(d>=(gR-sR)*(gR-sR))
            {
                ll L=0,R=cur+gR+sR;
                ans[L]++;ans[R+1]--;
            }
            else
            {
                ll L=gR-sR-cur,R=gR+sR+cur;
                ans[L]++;ans[R+1]--;
            }
        }
    for(ll i=1;i<=1000000;i++) ans[i]+=ans[i-1];
    for(ll i=0;i<Q;i++)
    {
        scanf("%lld",&K);printf("%lld\n",ans[K]);
    }
    return 0;
}

