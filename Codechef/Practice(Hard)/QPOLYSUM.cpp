/*************************************************************************
    > File Name: QPOLYSUM.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-12 11:46:16
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll MOD=101;
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=s*a%MOD;
        a=a*a%MOD;
        i>>=1;
    }
    return s;
}
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
namespace polysum
{
    const ll D=100005;
    ll a[D],f[D],g[D],p[D],p1[D],p2[D],b[D],h[D][2],C[D];
    ll calcn(ll d,ll *a,ll n)
    {
        printf("d=%lld n=%lld\n",d,n);
        if(d==0) return a[0];
        if(n<=d) return a[n];
        p1[0]=p2[0]=1;
        for(ll i=0;i<=d;i++)
        {
            ll t=(n-i+MOD)%MOD;
            p1[i+1]=p1[i]*t%MOD;
        }
        for(ll i=0;i<=d;i++)
        {
            ll t=(n-d+i+MOD)%MOD;
            p2[i+1]=p2[i]*t%MOD;
        }
        ll ans=0;
        for(ll i=0;i<=d;i++)
        {
            ll t=g[i]*g[d-1]%MOD*p1[i]%MOD*p2[d-i]%MOD*a[i]%MOD;
            printf("%lld\n",t);
            if((d-i)&1) ans=(ans-t+MOD)%MOD;
            else ans=(ans+t)%MOD;
        }
        return ans;
    }
    void init(ll M)
    {
        f[0]=f[1]=g[0]=g[1]=1;
        for(ll i=2;i<=M+4;i++) f[i]=f[i-1]*i%MOD;
        g[M+4]=pow_mod(f[M+4],MOD-2);
        for(ll i=M+3;i>=1;i--) g[i]=g[i+1]*(i+1)%MOD;
    }
    ll polysum(ll n,ll *a,ll m) //a[0]..a[m] \sum_{i=0}^{n-1} a[i]
    {
        a[m+1]=calcn(m,a,m+1);
        for(ll i=1;i<=m+1;i++) a[i]=(a[i-1]+a[i])%MOD;
        return calcn(m+1,a,n-1);
    }
    ll qpolysum(ll R,ll n,ll *a,ll m) //a[0]...a[m] \sum_{i=0}^{n-1} a[i]*R^{i}
    {
        for(ll i=1;i<=10;i++) printf("g[%lld]=%lld\n",i,g[i]);
        if(R==1) return polysum(n,a,m);
        a[m+1]=calcn(m,a,m+1);
        printf("a[%lld]=%lld\n",m+1,a[m+1]);
        ll r=pow_mod(R,MOD-2),p3=0,p4=0,c,ans;
        h[0][0]=0;h[0][1]=1;
        for(ll i=1;i<=m+1;i++)
        {
            h[i][0]=(h[i-1][0]+a[i-1])*r%MOD;
            h[i][1]=h[i-1][1]*r%MOD;
        }
        for(ll i=0;i<=m+1;i++)
        {
            ll t=g[i]*g[m+1-i]%MOD;
            printf("t=%lld\n",t);
            if(i&1) p3=((p3-h[i][0]*t)%MOD+MOD)%MOD,p4=((p4-h[i][1]*t)%MOD+MOD)%MOD;
            else p3=(p3+h[i][0]*t)%MOD,p4=(p4+h[i][1]*t)%MOD;
        }
        c=pow_mod(p4,MOD-2)*(MOD-p3)%MOD;
        printf("p4=%lld\n",p4);
        for(ll i=0;i<=m+1;i++) h[i][0]=(h[i][0]+h[i][1]*c)%MOD;
        for(ll i=0;i<=m+1;i++) C[i]=h[i][0];
        ans=(calcn(m,C,n)*pow_mod(R,n)-c)%MOD;
        if(ans<0) ans+=MOD;
        return ans;
    }
}
ll t,m,q,n,d,a[MAXN];
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&MOD,&q,&n,&d);
        polysum::init(MOD-5);
        for(ll i=0;i<=d;i++) scanf("%lld",&a[i]);
        if(q==0) printf("%lld\n",a[0]);
        else printf("%lld\n",polysum::qpolysum(q,n,a,d));
    }
    return 0;
}

