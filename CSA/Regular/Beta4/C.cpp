/*************************************************************************
    > File Name: Beta4C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-09 11:09:15
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
ll n,ans,a[MAXN];
ll bit[MAXN+1];
map<int,int> mp;
vector<P> v;
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        if(mp.find(x)==mp.end()) mp[x]=i;
        else v.push_back(P(mp[x],i));
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<(int)v.size();i++)
    {
        ll l=v[i].F,r=v[i].S;
        ans+=r-l-1;
        ans-=sum(r-1)-sum(l);
        //printf("%lld %lld %lld\n",l,r,ans);
        add(l,1);add(r,1);
    }
    printf("%lld\n",ans);
    return 0;
}

