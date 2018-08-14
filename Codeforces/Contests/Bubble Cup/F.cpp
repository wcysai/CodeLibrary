#include<bits/stdc++.h>
#define MAXK 10000007
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll save[MAXK];
ll fact[MAXK];
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
void extgcd(ll a,ll b,ll &x,ll &y)
{
    if(b!=0)
    {
        extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll mod_fact(ll n,ll p,ll &e)
{
    e=0;
    if(n==0) return 1;
    ll res=mod_fact(n/p,p,e);
    e+=n/p;
    if(n/p%2!=0) return res*(p-fact[n%p])%p;
    return res*fact[n%p]%p;
}
ll mod_comb(ll n,ll k,ll p)
{
    if(n<0||k<0||n<k) return 0;
    ll e1,e2,e3;
    ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse(a2*a3%p,p)%p;
}
ll exp_mod(ll a,ll b,ll c)
{
    a%=c;
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%c;
        b>>=1,a=a*a%c;
    }
    return ans;
}
int t;
ll p,q,k;
int main()
{
    scanf("%d",&t);
    memset(fact,0,sizeof(fact));
    fact[0]=1;
    for(int i=1;i<MAXK;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    while(t--)
    {
        scanf("%lld %lld %lld",&p,&q,&k);
        memset(save,0,sizeof(save));
        save[0]=exp_mod(p-q,k,MOD);
        for(int i=2;i<=k;i+=2)
            save[i]=(((((((save[i-2]*mod_inverse(p-q,MOD))%MOD)*mod_inverse(p-q,MOD))%MOD)*q)%MOD)*q)%MOD;
        ll y=exp_mod(p,k,MOD);
        ll res=0;
        for(int i=0;i<=k;i+=2)
            res=(res+(mod_comb(k,i,MOD)*save[i]))%MOD;
        printf("%I64d\n",(res*mod_inverse(y,MOD))%MOD);
    }
    return 0;
}
