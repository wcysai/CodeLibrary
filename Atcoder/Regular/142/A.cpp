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
ll n,k;
set<ll> s;
ll go(ll x)
{
    while(x%10==0) x/=10;
    ll ans=x;
    for(int i=0;i<2;i++)
    {
        vector<int> v;
        ll tmp=x;
        while(tmp) {v.push_back(tmp%10); tmp/=10;}
        ll now=0;
        for(int i=0;i<(int)v.size();i++) now=now*10+v[i];
        x=now;
        ans=min(ans,x);
    }
    return ans;
}
int main()
{
    scanf("%lld%lld",&n,&k);
    if(go(k)!=k)
    {
        puts("0");
        return 0;
    }
    vector<int> v;
    ll tmp=k;
    while(tmp) {v.push_back(tmp%10); tmp/=10;}
    ll now=0;
    for(int i=0;i<(int)v.size();i++) now=now*10+v[i];
    ll ans=0;
    if(k!=now)
    {
        while(now<=n) {if(go(now)==k) ans++; now*=10;}
    }
    ll tmp2=k;
    while(tmp2<=n) {if(go(tmp2)==k) ans++; tmp2*=10;}
    printf("%lld\n",ans);
    return 0;
}

