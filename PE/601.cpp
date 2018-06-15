/*************************************************************************
    > File Name: 601.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-15 10:22:20
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
ll check(ll x,ll y)
{
    ll s=1;
    for(ll i=1;i<=x;i++) 
        s=lcm(i,s);
    return (y-2)/s-(y-2)/lcm(s,x+1);
}
int main()
{
    printf("%llu\n",check(3,14));
    printf("%llu\n",check(6,1000000));
    ll ans=0,s=1;
    for(ll i=1;i<=31;i++)
    {
        s=s*4;
        printf("%llu\n",ans);
        ans+=check(i,s);
    }
    printf("%llu\n",ans);
    return 0;
}

