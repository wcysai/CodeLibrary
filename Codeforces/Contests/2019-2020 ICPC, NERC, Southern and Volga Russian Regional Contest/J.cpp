#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll k,c[MAXN];
bool check(ll x)
{
    ll ans=0; ll mod=0;
    for(int i=1;i<=n;i++)
    {
        if(mod+c[i]<x)
        {
            ans-=mod; ans+=c[i];
            mod=c[i];
            continue;
        }
        ans+=c[i];
        mod=(mod+c[i])%x;
        if(!c[i]&&mod)
        {
            ans-=mod;
            mod=0;
        }
    }
    if(mod) ans-=mod;
    assert(ans%x==0);
    return ans/x>=k;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&k);
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&c[i]);
            sum+=c[i];
        }
        ll l=0,r=sum/k+1;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%lld\n",l*k);
    }
    return 0;
}
