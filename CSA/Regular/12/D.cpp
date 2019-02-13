#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll Q,a,b,x;
ll solve(ll a,ll x)
{
    if(a<x) return 0;
    a-=x;
    vector<P> v;
    ll cnt=0;
    for(ll i=60;i>=0;i--)
    {
        if((x>>i)&1) continue;
        v.push_back(P(i,cnt));
        cnt++;
    }
    ll ans=0;
    for(auto p:v)
    {
        if(a>=(1LL<<p.F))
        {
            ans+=(1LL<<(cnt-p.S-1));
            a-=(1LL<<p.F);
        }
    }
    return ans+1;
}
int main()
{
    scanf("%lld",&Q);
    while(Q--)
    {
        scanf("%lld%lld%lld",&a,&b,&x);
        printf("%lld\n",solve(b,x)-solve(a-1,x));
    }
    return 0;
}

