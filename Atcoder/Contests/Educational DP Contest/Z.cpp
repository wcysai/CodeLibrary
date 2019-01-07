#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,h[MAXN],dp[MAXN],C,tot,t,now;
P st[MAXN];
ll get(P u,P v) {return (v.S-u.S)/(u.F-v.F);}
void add(ll u,ll v)
{
    P p=P(u,v);
    while(t-now>1&&get(st[t-1],p)<=get(st[t-1],st[t-2])) t--;
    st[t++]=p;
}
bool cmp(P x,P y)
{
    if(x.S!=y.S) return x.S<y.S;
    return x.F<y.F;
}
ll query(ll x)
{
    ll l=-1,r=t-1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(st[mid].F*x+st[mid].S>=st[mid+1].F*x+st[mid+1].S) l=mid;
        else r=mid;
    }
    return st[r].F*x+st[r].S;
}
int main()
{
    scanf("%lld%lld",&N,&C);
    for(ll i=1;i<=N;i++) scanf("%lld",&h[i]);
    dp[1]=0;
    add(-2*h[1],dp[1]+h[1]*h[1]);
    for(ll i=2;i<=N;i++)
    {
        dp[i]=query(h[i])+h[i]*h[i]+C;
        add(-2*h[i],dp[i]+h[i]*h[i]);
    }
    printf("%lld\n",dp[N]);
    return 0;
}

