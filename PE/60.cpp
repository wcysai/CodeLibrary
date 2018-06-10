/*************************************************************************
    > File Name: 60.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 09:09:46
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXM 40000005
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll prime[MAXM],pow10[MAXN];
bool is_prime[MAXM];
vector<int> coexist[MAXN];
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
bool _prime(ll x)
{
    if(x<=40000000) return is_prime[x];
    for(ll i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
ll digit(ll x)
{
    if(x==0) return 0;
    return digit(x/10)+1;
}
bool check(ll x,ll y)
{
    ll dx=digit(x),dy=digit(y);
    ll p=x*pow10[dy]+y;
    if(!_prime(p)) return false;
    p=y*pow10[dx]+x;
    if(!_prime(p)) return false;
    return true;
}
int main()
{
    ll p=sieve(40000000);
    p=sieve(50000);
    puts("Done sieve!");
    pow10[0]=1;
    for(ll i=1;i<=9;i++) pow10[i]=10*pow10[i-1];
    ll ans=INF;
    for(ll i=0;i<p;i++)
    {
        printf("%lld\n",prime[i]);
        for(ll j=i+1;j<p;j++)
            if(check(prime[i],prime[j])) coexist[i].push_back(j);
    }
    puts("Done!");
    for(ll i=0;i<p;i++)
    {
        ll a=i;
        for(ll j=0;j<(int)coexist[i].size();j++)
        {
            ll b=coexist[i][j];
            printf("%lld %lld\n",prime[a],prime[b]);
            for(ll k=0;k<(int)coexist[b].size();k++)
            {
                ll c=coexist[b][k];
                if(!check(prime[a],prime[c])) continue;
                for(ll l=0;l<(int)coexist[c].size();l++)
                {
                    ll d=coexist[c][l];
                    if(!check(prime[a],prime[d])||!check(prime[b],prime[d])) continue;
                    for(ll m=0;m<(int)coexist[d].size();m++)
                    {
                        ll e=coexist[d][m];
                        if(!check(prime[a],prime[e])||!check(prime[b],prime[e])||!check(prime[c],prime[e])) continue;
                        ll sum=prime[a]+prime[b]+prime[c]+prime[d]+prime[e];
                        if(sum<ans)
                        {
                            printf("%lld %lld %lld %lld %lld %lld\n",prime[a],prime[b],prime[c],prime[d],prime[e],sum);
                            ans=sum;
                        }
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

