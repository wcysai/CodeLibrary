/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-22 16:18:20
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll S=20;


ll mult_mod(ll a,ll b,ll c)
{
    a%=c;
    b%=c;
    ll ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}


ll pow_mod(ll x,ll n,ll mod)
{
    if(n==1)return x%mod;
    x%=mod;
    ll tmp=x;
    ll ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}

bool check(ll a,ll n,ll x,ll t)
{
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(ll i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}


bool Miller_Rabin(ll n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;
    ll x=n-1;
    ll t=0;
    while((x&1)==0){x>>=1;t++;}
    for(ll i=0;i<S;i++)
    {
        ll a=rand()%(n-1)+1;
        if(check(a,n,x,t))
            return false;
    }
    return true;
}

ll factor[100],T,n,m;
ll tol;

ll _pow(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}

ll gcd(ll a,ll b)
{
    if(a==0)return 1;//???????
    if(a<0) return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}

ll Pollard_rho(ll x,ll c)
{
    ll i=1,k=2;
    ll x0=rand()%x;
    ll y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
void findfac(ll n)
{
    if(Miller_Rabin(n))
    {
        factor[tol++]=n;
        return;
    }
    ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}
ll sz,a[100],ans;
vector<P> v;
void dfs(ll cur,ll now)
{
    if(cur==sz)
    {
        ll res=_pow(m,now);//printf("%d\n",now);
        for(ll i=0;i<sz;i++)
        {
            ll cnt=v[i].S-a[i];
            if(cnt==0) continue;
            else
            {
                res=res*(v[i].F-1)%MOD;
                res=res*_pow(v[i].F,cnt-1)%MOD;
            }
        }
        ans+=res;
        return;
    }
    for(ll i=0;i<=v[cur].S;i++)
    {
        dfs(cur+1,now);
        now=now*v[cur].F%MOD;
        a[cur]++;
    }
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        memset(a,0,sizeof(a));
        tol=0;
        findfac(n);
        sort(factor,factor+tol);
        v.clear();
        for(ll i=0;i<tol;i++)
        {
            if(v.size()==0||v.back().F!=factor[i]) v.push_back(P(factor[i],1));
            else v.back().S++;
        }
        sz=v.size();ans=0;
        dfs(0,1);
       // printf("%lld\n",ans);
        if(n&1) ans=(ans+n*_pow(m,(n+1)/2))%MOD;
        else ans=(ans+n/2*(_pow(m,n/2+1)+_pow(m,n/2)))%MOD;
        printf("%d\n",ans);
        ans=ans*_pow(2,MOD-2)%MOD;
        ans=ans*_pow(n,MOD-2)%MOD;
        ans=ans*_pow(m,MOD-2)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}

