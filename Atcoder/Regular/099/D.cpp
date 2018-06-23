/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-23 20:08:16
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],d[MAXN];
ll digit_sum(ll x)
{
    if(x==0) return 0;
    return x%10+digit_sum(x/10);
}
set<ll> s;
int main()
{
    scanf("%lld",&k);
    for(ll i=0;i<=200;i++) d[i]=digit_sum(i);
    for(ll i=1;i<=8;i++) s.insert(i);
    ll mult=1;
    for(ll i=1;i<=15;i++)
    {
        mult*=10;
        for(ll j=0;j<=200;j++)
        {
            if(j%10==9) continue;
            if(d[j]+i*9>j)
            {
                if(j>=INF/mult) continue;
                if(j*mult+mult-1<=INF) s.insert(j*mult+mult-1);
            }
        }
    }
    ll cnt=0;
    for(auto it=s.begin();it!=s.end();it++)
    {
        cnt++;
        if(cnt<=k) printf("%lld\n",*it);
        else break;
    }
    return 0;
}

