/*************************************************************************
    > File Name: 351.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-14 13:17:47
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
int prime[MAXN],phi[MAXN];
bool is_prime[MAXN];
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void genphi(int n)
{
    int p=0;
    memset(phi,0,sizeof(phi));
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    genphi(100000000);
    while(scanf("%lld",&n)==1)
    {
        ll sum=n*(n+1)*3;
        ll cnt=0;
        for(ll i=1;i<=n;i++)
            cnt+=phi[i];
        printf("%lld\n",cnt);
        printf("%lld\n",sum-6*cnt);
    }
    return 0;
}

