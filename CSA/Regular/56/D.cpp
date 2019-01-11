#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
vector<ll> a;
queue<ll> q;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        if(x>1) a.push_back(x);
    }
    sort(a.begin(),a.end());
    ll ans=0;
    while(q.size()||a.size())
    {
        ll now=INF;
        if(a.size()) now=a.back(); else now=q.front();
        if(q.size()&&q.front()>now) now=q.front(); 
        ans++;
        if(now/2>1) q.push(now/2);
        while(a.size()&&a.back()==now) a.pop_back();
        while(q.size()&&q.front()==now) q.pop();
    }
    printf("%lld\n",ans);
    return 0;
}

