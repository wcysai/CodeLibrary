/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 22:58:49
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,n,k,a[MAXN];
ll prime[MAXN],miu[MAXN];
ll cnt[62];
bool is_prime[MAXN];
void genmiu(ll n)
{
    ll p=0;
    memset(is_prime,true,sizeof(is_prime));
    memset(miu,0,sizeof(miu));
    is_prime[1]=is_prime[0]=false;
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
    genmiu(100);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        memset(cnt,0,sizeof(cnt));
        cnt[1]=n-1;
        for(ll i=2;i<=60;i++)
        {
            long double res=pow((long double)n+0.1,(long double)1.0/i);
            cnt[i]=(ll)res-1;
        }
        ll ans=0;
        for(ll i=1;i<=60;i++) 
            ans+=miu[i]*cnt[i];
        printf("%lld\n",ans);
    }
    return 0;
}

