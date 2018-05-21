#include<bits/stdc++.h>
#define MAXN 100020
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXN],rem[MAXN];
bool is_prime[MAXN];
ll n,t,a[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
ll cal(ll x)
{
    ll s=0,res=0;
    memset(rem,0,sizeof(rem));
    for(ll i=0;i<n;i++)
    {
        rem[a[i]%x]++;
        s+=a[i]%x;
    }
    ll k=s/x;
    for(ll i=x-1;i>=0;i--)
    {
        res+=min(k,rem[i])*(x-i);
        k-=min(k,rem[i]);
        if(k==0) break;
    }
    return res;
}
int main()
{
    scanf("%lld",&t);
    ll p=sieve(MAXN-1);
    ll ans=INF;
    while(t--)
    {
        scanf("%lld",&n);
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        ans=sum;
        for(ll i=0;i<p;i++)
            if(sum%prime[i]==0)
                ans=min(ans,cal(prime[i]));
        printf("%lld\n",ans);
    }
    return 0;
}


