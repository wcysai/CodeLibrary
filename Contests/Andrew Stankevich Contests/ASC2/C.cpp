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
ll n;
priority_queue<ll,vector<ll>,greater<ll> > pque;
int main()
{
    freopen("huffman.in","r",stdin);
    freopen("huffman.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        pque.push(x);
    }
    ll ans=0;
    while(pque.size()>1)
    {
        ll p=pque.top(); pque.pop();
        ll q=pque.top(); pque.pop();
        ans+=(p+q); pque.push(p+q);
    }
    printf("%lld\n",ans);
    return 0;
}

