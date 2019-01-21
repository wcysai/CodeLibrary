#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define M 1000000023
#define PHI1 110
#define PHI2 60
#define PHI3 45160
#define PR1 48
#define PR2 35
#define PR3 41511
#define INV1 58
#define INV2 7
#define INV3 44431
#define P1 85
#define P2 18
#define P3 20756
#define Q1 37
#define Q2 44
#define Q3 24406
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll t,n,k,a[MAXN];
ll MOD[4]={3,121,61,45161};
ll PHI[4]={2,110,60,45160};
ll ans[4];
ll r[5][5],x[5];
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll solve(vector<P> &v)
{
    for(ll i=0;i<4;i++)
        for(ll j=i+1;j<4;j++)
            r[i][j]=mod_inverse(v[i].S,v[j].S);
    ll ans=0;
    for(ll i=0;i<4;i++)
    {
        x[i]=v[i].F;
        for(ll j=0;j<i;j++)
        {
            x[i]=r[j][i]*(x[i]-x[j]);
            x[i]=x[i]%v[i].S;
            if(x[i]<0) x[i]+=v[i].S;
        }
    }
    ll base=1;
    for(ll i=0;i<4;i++)
    {
        ans=(ans+base*x[i])%M;
        base=base*v[i].S%M;
    }
    return ans;
}
ll pow_mod(ll a,ll i,ll m)
{
    if(a==0) return 0;
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
ll find_period(ll m)
{
    ll a=1,b=1,cnt=0;
    do
    {
        ll c=(a+b)%m;
        a=b;b=c;cnt++;
    }while(a!=1||b!=1);
    return cnt;
}
ll calc_sum(ll t,ll n,ll m)
{
    if(t<=2) return t;
    ll ans=2;
    ll a=1,b=1;
    for(ll i=1;i<=t-2;i++)
    {
        ll c=a+b; if(c>=m) c-=m;
        a=b;b=c;
        ans+=pow_mod(c,n,m);
        if(ans>=m) ans-=m;
    }
    return ans;
}
int main()
{
    scanf("%lld",&t);
    //printf("%lld %lld %lld\n",pow_mod(PR1,109,MOD1),(1LL*(PR1+1)*(MOD1+1)/2)%MOD1,(1LL*(1-PR1+MOD1)*(MOD1+1)/2)%MOD1);
    //printf("%lld %lld %lld\n",pow_mod(PR2,MOD2-2,MOD2),(1LL*(PR2+1)*(MOD2+1)/2)%MOD2,(1LL*(1-PR2+MOD2)*(MOD2+1)/2)%MOD2);
    //printf("%lld %lld %lld\n",pow_mod(PR3,MOD3-2,MOD3),(1LL*(PR3+1)*(MOD3+1)/2)%MOD3,(1LL*(1-PR3+MOD3)*(MOD3+1)/2)%MOD3);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        for(ll i=0;i<4;i++)
        {
            ll p;
            p=find_period(MOD[i]);
            ll num=n/p,pre=n%p;
            if(i!=1) ans[i]=(1LL*(num%MOD[i])*calc_sum(p,k%PHI[i],MOD[i])+calc_sum(pre,k%PHI[i],MOD[i]))%MOD[i];
            else  ans[i]=(1LL*(num%MOD[i])*calc_sum(p,k,MOD[i])+calc_sum(pre,k,MOD[i]))%MOD[i];
        }
        vector<P> v;v.clear();
        for(ll i=0;i<4;i++) v.push_back(P(ans[i],MOD[i]));
        printf("%lld\n",solve(v));
    }
    return 0;
}
//983730627 679276841
//std: 269933389
//me: 906297040
