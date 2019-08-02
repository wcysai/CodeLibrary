#include<bits/stdc++.h>
#define MAXN 45
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef long long ll;
int n;
ll m;
void add(int &a,int b) {a+=b; while(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int fact[MAXN],invf[MAXN];
struct poly
{
    ll w,n;
    int y[MAXN],pre[MAXN],suf[MAXN],val[MAXN];
    void init()
    {
        for(int i=0;i<=n;i++) val[i]=1LL*invf[i]*(((n-i)&1)?MOD-invf[n-i]:invf[n-i])%MOD*y[i]%MOD;
        pre[0]=suf[n+2]=1;
    }
    int getval(ll x)
    {
        x/=w;
        if(x<=n) return y[x];
        x%=MOD;
        int ans=0;
        for(int i=1;i<=n+1;i++) pre[i]=1LL*pre[i-1]*(x-i+1)%MOD;
        for(int i=n+1;i>=1;i--) suf[i]=1LL*suf[i+1]*(x-i+1)%MOD;
        for(int i=0;i<=n;i++) ans=(ans+1LL*pre[i]*suf[i+2]%MOD*val[i]%MOD+MOD)%MOD;
        return ans;
    }
}f[MAXN];
int tmp[MAXN];
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=40;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[40]=pow_mod(fact[40],MOD-2);
    for(int i=39;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    while(scanf("%d%lld",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            f[i].n=i;
            scanf("%lld",&f[i].w);
            memset(f[i].y,0,sizeof(f[i].y));
        }
        f[1].y[1]=f[1].y[0]=1;
        for(int i=2;i<=n;i++)
        {
            ll cur=m%f[i].w;f[i-1].init();
            for(int j=0;j<=i;j++)
            {
                tmp[j]=f[i-1].getval(cur);
                if(cur>m) break;
                cur+=f[i].w;
            }
            for(int j=0;j<=i;j++)
                for(int k=0;k<=j;k++)
                    add(f[i].y[j],tmp[k]);
        }
        f[n].init();
        printf("%d\n",(f[n].getval(m)%MOD+MOD%MOD));
    }
    return 0;
}
