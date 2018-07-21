/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-21 14:11:50
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
ll n,T;
ll x[MAXN],a[MAXN];
ll precnt[MAXN],sufcnt[MAXN];
ll pre[MAXN],suf[MAXN];
bool C(ll now,ll dis)
{
    ll id=lower_bound(x+1,x+n+2,x[now]-dis)-x;
    ll cnt1=precnt[now-1]-precnt[id-1],sum1=pre[now-1]-pre[id-1];
    id=upper_bound(x+1,x+n+2,x[now]+dis)-x;
    id--;
    ll cnt2=precnt[id]-precnt[now],sum2=pre[id]-pre[now];
    return (2*(cnt1*x[now]-sum1)+2*(sum2-cnt2*x[now])<=T);
}
ll find_ans(ll now,ll dis)
{
    ll id=lower_bound(x+1,x+n+2,x[now]-dis)-x;
    ll cnt1=precnt[now-1]-precnt[id-1],sum1=pre[now-1]-pre[id-1];
    id=upper_bound(x+1,x+n+2,x[now]+dis)-x;
    id--;
    ll cnt2=precnt[id]-precnt[now],sum2=pre[id]-pre[now];
    ll left=T-2*(cnt1*x[now]-sum1)-2*(sum2-cnt2*x[now]);
    ll num=left/2/(dis+1);
    return cnt1+cnt2+a[now]+num;
}
int main()
{
    scanf("%lld%lld",&n,&T);
    for(ll i=1;i<=n;i++) scanf("%lld%lld",&x[i],&a[i]);
    x[n+1]=INF+1;
    for(ll i=1;i<=n;i++) precnt[i]=precnt[i-1]+a[i];
    for(ll i=1;i<=n;i++) pre[i]=pre[i-1]+a[i]*x[i];
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll l=0,r=(int)1e9;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(C(i,mid)) l=mid; else r=mid;
        }
        ans=max(ans,find_ans(i,l));
    }
    printf("%lld\n",ans);
    return 0;
}

