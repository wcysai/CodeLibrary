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
ll n,a[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a,a+n);
    ll g=0;
    for(ll i=1;i<n;i++) g=__gcd(g,a[i]-a[i-1]);
    ll ans=0;
    for(ll i=1;i<n;i++) ans+=(a[i]-a[i-1])/g-1;
    printf("%lld\n",ans);
    return 0;
}

