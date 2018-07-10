/*************************************************************************
    > File Name: 1695.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-10 10:05:19
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,a,b,k;
ll prime[MAXN],miu[MAXN];
bool is_prime[MAXN];
void sieve(ll n)
{
    ll p=0;
    memset(miu,0,sizeof(miu));
    memset(is_prime,true,sizeof(is_prime));
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
    sieve(100000);
    scanf("%lld",&t);
    ll kase=0;
    while(t--)
    {
        kase++;
        ll x,y;
        scanf("%lld%lld%lld%lld%lld",&x,&a,&y,&b,&k);
        printf("Case %lld: ",kase);
        if(k==0)
        {
            puts("0");
            continue;
        }
        if(a>b) swap(a,b);
        ll ans=0,ans2=0;
        for(ll d=1;d<=a/k;d++)
            ans+=miu[d]*(a/(k*d))*(b/(k*d));
        for(ll d=1;d<=a/k;d++)
            ans2+=miu[d]*(a/(k*d))*(a/(k*d));
        printf("%lld\n",ans-ans2/2);
    }
    return 0;
}

