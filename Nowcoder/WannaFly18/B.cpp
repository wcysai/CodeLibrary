/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-22 19:08:00
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
ll a;
string str;
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll calc(ll x,ll t)
{
    ll s=1;
    for(ll i=1;i<=t;i++)
        s=1LL*s*x%MOD;
    return s;
}
int main()
{
    scanf("%lld",&a);
    ll res=1LL*a*mod_inverse(10000,MOD)%MOD;
    res=res*2LL%MOD;
    res=(MOD+1-res)%MOD;
    cin>>str;
    ll n=str.size(),base=res;
    res=1;
    for(ll i=n-1;i>=0;i--)
    {
        res=1LL*res*calc(base,str[i]-'0')%MOD;
        base=calc(base,10);
    }
    res=(MOD+1-res)%MOD;
    res=1LL*res*mod_inverse(2,MOD)%MOD;
    printf("%lld\n",res);
    return 0;
}

