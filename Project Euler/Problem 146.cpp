#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod_mul(long long a, long long b, long long n) {
    long long res = 0;
    while (b) {
        if(b & 1)
            res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}

long long pow_mod(long long a, long long b, long long n) {
    long long res = 1;
    while(b) {
        if(b & 1)
            res = mod_mul(res, a, n);
        a = mod_mul(a, a, n);
        b >>= 1;
    }
    return res;
}
bool test(ll n,ll a,ll d)
{
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1)) d=d>>1;
    ll t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=mod_mul(t,t,n);
        d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}
bool isPrime(ll n)
{
    if(n<2) return false;
    ll a[]={2,3,7,61,24251};
    for(ll i=0;i<=4;++i) 
    {
        if(n==a[i]) return true;
        if(!test(n,a[i],n-1)) return false;
    }
    return true;
}
int main()
{
    ll ans=0;
    for(ll i=10;i<=150000000;i+=10)
    {
        ll res=i*i;
        if(res%3!=1) continue;
        if(res%7!=2&&res%7!=3) continue;
        if(res%9==0||res%13==0||res%27==0) continue;
        if(isPrime(res+1)&&isPrime(res+3)&&isPrime(res+7)&&isPrime(res+9)&&isPrime(res+13)&&isPrime(res+27)&&(!isPrime(res+19))&&(!isPrime(res+21)))
            ans+=i;
    }
    printf("%I64d\n",ans);
    return 0;
}
