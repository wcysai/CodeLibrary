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
ll n,q,x,a[MAXN],sum[MAXN],even[MAXN];
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    a[0]=-INF;
    for(ll i=1;i<=n;i++) 
    {
        sum[i]=sum[i-1]+a[i];
        even[i]=even[i-1]+a[i]*(i&1?0:1);
    }
    for(ll i=0;i<q;i++)
    {
        scanf("%lld",&x);
        if(x>=a[n]) 
        {
            if(n&1) printf("%lld\n",sum[n]-even[n]);
            else printf("%lld\n",even[n]);
            continue;
        }
        ll pos=lower_bound(a+1,a+n+1,x)-a;
        ll l=pos-1,r=n;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            ll numr=n-mid+1;
            ll numl=mid-(lower_bound(a,a+n+1,2*x-a[mid])-a);
            if(numr-numl<=1) r=mid; else l=mid;  
        }
        ll ans=sum[n]-sum[r-1];
        ll pp=n-2*(n-r+1);
        if(pp&1) ans+=sum[pp]-even[pp]; else ans+=even[pp];
        printf("%lld\n",ans);
    }
    return 0;
}

