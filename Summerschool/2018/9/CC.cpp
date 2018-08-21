/*************************************************************************
    > File Name: CC.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-20 15:51:17
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXD 4005
#define INF 10000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll k,a[MAXN];
ll d[MAXD][MAXD];
ll prime[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(4000);
    for(ll n=1;n<=100;n++)
    {
        for(ll i=1;i<=n;i++) d[i][i]=INF;
        for(ll i=1;i<=n;i++)
            for(ll j=i+1;j<=n;j++)
            {
                ll t1=i,t2=j,cnt=0,res=1;
                for(ll k=0;prime[k]<=n;k++)
                {
                    cnt=0;
                    while(t1%prime[k]==0) {t1/=prime[k]; cnt++;}
                    while(t2%prime[k]==0) {t2/=prime[k]; cnt++;}
                    if(cnt&1) res=res*prime[k];
                }
                d[i][j]=d[j][i]=res;
            }
        //assert(0);
            //puts("1");
            for(ll k=1;k<=n;k++)
            {
                for(ll i=1;i<=n;i++)
                    for(ll j=1;j<=n;j++) 
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        ll ans=0;
        for(ll i=1;i<=n;i++)
            for(ll j=i+1;j<=n;j++)
                ans=(ans+d[i][j])%MOD;
        printf("%lld %lld\n",n,ans);
    }
    return 0;
}

