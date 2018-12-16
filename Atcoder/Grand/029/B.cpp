/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-15 20:03:59
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll tot,n,ans,a[MAXN];
bool vis[MAXN];
map<ll,ll> mp;
multiset<ll> s;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) 
    {
        ll x;
        scanf("%lld",&x);
        s.insert(x);
    }
    while(s.size())
    {
        auto it=s.end();it--;
        ll v=*it;
        s.erase(it);
        ll x=1;while(x<=v) x*=2;
        if(s.count(x-v))
        {
            s.erase(s.find(x-v));
            ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

