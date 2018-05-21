#include<bits/stdc++.h>
#define MAXN 33600000
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXN],miu[MAXN];
bool is_prime[MAXN];
void genmiu(ll n)
{
    ll p=0;
    memset(miu,0,sizeof(miu));
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    miu[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; miu[i]=-1;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    genmiu(33554432);
    ll ans=0,num=1LL<<50;
    for(ll i=1;i<=33554432;i++)
        ans+=miu[i]*(num/(i*i));
    printf("%lld\n",ans);
    return 0;
}

