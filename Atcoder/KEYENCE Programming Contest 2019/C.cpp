#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN],b[MAXN],c[MAXN],sum;
int main()
{
    scanf("%lld",&n);
    sum=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
        sum-=b[i];
    }
    if(sum<0)
    {
        puts("-1");
        return 0;
    }
    sum=0;
    vector<P> v;
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(a[i]<b[i])
        {
            sum+=b[i]-a[i];
            ans++;
        }
        else
        {
            v.push_back(P(a[i]-b[i],i));
        }
    }
    sort(v.begin(),v.end(),greater<P>());
    for(ll i=0;i<(int)v.size();i++)
    {
        if(sum==0) break;
        ll cc=min(sum,v[i].F);
        sum-=cc; ans++;
    }
    assert(sum==0);
    printf("%lld\n",ans);
    return 0;
}

