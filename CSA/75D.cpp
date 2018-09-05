/*************************************************************************
    > File Name: 75D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-04 14:20:35
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
typedef pair<ll,ll> P;
ll n;
struct Query
{
    ll t,c,id;
}a[MAXN];
ll ans[MAXN];
bool cmp(Query p,Query q)
{
    if(p.t!=q.t) return p.t<q.t;
    return p.id<q.id;
}
set<P> s;
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
    {
        a[i].id=i+1;
        scanf("%lld%lld",&a[i].c,&a[i].t);
    }
    sort(a,a+n,cmp);
    ll cur=0;
    for(ll i=0;i<n;i++)
    {
        ll elapse=a[i].t-cur;
        while(s.size()&&elapse)
        {
            auto it=*s.begin();
            s.erase(s.begin());
            if(it.S<=elapse) {ans[it.F]=cur+it.S; cur+=it.S; elapse-=it.S;}
            else
            {
                it.S-=elapse;cur+=elapse;elapse=0;
                s.insert(it);
            }
        }
        cur+=elapse;
        s.insert(P(a[i].id,a[i].c));
    }
    while(s.size())
    {
        auto it=*s.begin();
        ans[it.F]=cur+it.S;
        cur+=it.S;
        s.erase(s.begin());
    }
    for(ll i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}

