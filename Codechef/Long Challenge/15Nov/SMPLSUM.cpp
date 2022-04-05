/*************************************************************************
    > File Name: SMPLSUM.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-10 09:10:49
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,k,prime[MAXN],ans[MAXN],low[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    ans[1]=1;low[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; low[i]=i; ans[i]=i*(i-1)+1; }
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) 
            {
                low[i*prime[j]]=low[i]*prime[j];
                if(low[i]==i) ans[i*prime[j]]=ans[i]*prime[j]*prime[j]-(prime[j]-1);
                else ans[i*prime[j]]=ans[i/low[i]]*ans[low[i]*prime[j]];
                break;
            }
            low[i*prime[j]]=prime[j];
            ans[i*prime[j]]=ans[i]*ans[prime[j]];
        }
    }
    return p;
}
int main()
{
    sieve(10000000);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}

