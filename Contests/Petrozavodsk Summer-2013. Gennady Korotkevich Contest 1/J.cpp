#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int prime[MAXN],p;
bool is_prime[MAXN];
ll n;
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll solve(ll x)
{
    ll ret=1;
    if(x==0) return ret;
    for(int i=0;i<p;i++)
    {
        if(x%prime[i]==0)
        {
            int cnt=0;
            while(x%prime[i]==0) cnt++,x/=prime[i];
            ret*=(cnt+1);
            if(x==1) break;
        }
    }
    if(x>1) ret=2LL*ret;
    return ret;
}
int main()
{
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    p=sieve(1000000);
    scanf("%lld",&n);
    ll ans=0;
    for(int i=1;1LL*i*i<=n;i++)
    {
        if(n%i) continue;
        ans+=solve(i-1);
        if(1LL*i*i!=n) ans+=solve(n/i-1);
    }
    printf("%lld\n",ans);
    return 0;
}
