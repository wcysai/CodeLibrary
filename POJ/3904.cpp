/*************************************************************************
    > File Name: 3904.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-10 10:34:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],cnt[MAXN],f[MAXN];
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
            is_prime[i*prime[j]]=false;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    sieve(10000);
    while(scanf("%lld",&n)==1)
    {
        memset(cnt,0,sizeof(cnt));
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            for(ll j=1;j*j<=a[i];j++)
            {
                if(a[i]%j==0)
                {
                    cnt[j]++;
                    if(j*j!=a[i]) cnt[a[i]/j]++;
                }
            }
        }
        for(ll i=1;i<=10000;i++) f[i]=cnt[i]*(cnt[i]-1)*(cnt[i]-2)*(cnt[i]-3)/24;
        ll ans=0;
        for(ll j=1;j<=10000;j++) ans+=miu[j]*f[j];
        printf("%lld\n",ans);
    }
    return 0;
}

