/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-28 18:17:38
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 20000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN];
map<P,ll> mp;
ll find(ll x,ll left)
{
    if(mp.find(P(x,left))!=mp.end()) return mp[P(x,left)];
    if(left==0) 
    {
        printf("%lld %lld %lld\n",x,left,x);
        return mp[P(x,left)]=x;
    }
    if(x>10000)
    {
        return min(INF,find(10000LL,left)+x-10000LL);
    }
    ll cur;
    cur=x;
    for(ll i=1;i<=x;i++)
        cur=find(cur,left-1)+1;
    cur=find(cur,left-1);
    printf("%lld %lld %lld\n",x,left,cur);
    return mp[P(x,left)]=cur;
}
int main()
{
    printf("%lld\n",find(1,5));
    return 0;
}

