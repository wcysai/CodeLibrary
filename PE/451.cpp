#include<bits/stdc++.h>
#define MAXN 20000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,factor[MAXN],prime[MAXN],ans[MAXN];
void sieve(ll n)
{
    ll p=0;
    factor[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(!factor[i])
        {
            factor[i]=i;
            prime[p++]=i;
        }
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            factor[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}
ll pow_mod(ll a,ll i,ll m)
{
    if(i==0) return 1;
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
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
int main()
{
    sieve(20000000);
    vector<ll> v;
    for(ll i=2;i<=20000000;i++) ans[i]=1;
    for(ll i=3;i<=20000000;i++)
    {
        ll t=i,cnt=0,mult=1;v.clear();
        while(t>1)
        {
            ll u=factor[t],tt=t;
            if(u!=2)
            {
                while(t%u==0) t=t/u;
                v.push_back(tt/t);
            }
            else
            {
                while(t%u==0) t=t/u,cnt++,mult*=2; 
            }
        }
        ll sz=v.size();
        for(ll j=0;j<(1<<sz);j++)
        {
            ll s=1;
            for(ll k=0;k<sz;k++)
                if((j>>(sz-1-k))&1) s*=v[k];
            for(ll k=0;k<4;k++)
            {
                ll res=s;
                if(cnt>0)
                {
                    if(k==0) res=s*mult/2;
                    if(k==1) res=s;
                    if(k==2) res=s*2;
                    if(k==3) res=s*mult;
                }
                ll x,y;
                //printf("%lld %lld %lld %lld\n",i,res,i/res,ans[i]);
                ll a=res,b=i/res;
                if(a==1||b==1) continue;
                if(gcd(a,b)==2)
                {
                    a/=2;b/=2;
                    extgcd(a,b,x,y);
                    x=(b-x%b)%b;
                    if(2*a*x+1<i-1) ans[i]=max(ans[i],2*a*x+1);
                    if(2*a*x+1+i/2<i-1) ans[i]=max(ans[i],2*a*x+1+i/2);
                    //if(i==196) printf("%lld %lld %lld\n",a,b,x);
                    //printf("%lld\n",ans);
                }
                else
                {
                    extgcd(a,b,x,y);
                    //if(i==15||i==189) printf("%lld %lld %lld\n",a,b,x);
                    x=(b-x%b)%b;
                    x=2*x%b;
                    //if(i==6||i==15||i==189) printf("%lld %lld %lld %lld\n",a,b,x,a*x+1);
                    if(a*x+1<i-1) ans[i]=max(ans[i],a*x+1);
                    //printf("%lld\n",ans);
                }
            }
        }
        if(i%10000==0) printf("%lld %lld\n",i,ans[i]);
    }
    ll sum=0;
    for(ll i=3;i<=20000000;i++) sum+=ans[i]; 
    printf("%lld\n",sum);
    return 0;
}
