#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n,k;
pair<ll,ll> a[MAXN];
ll l[MAXN],r[MAXN];
int main()
{
    scanf("%lld",&n);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    for(ll i=0;i<n;i++)
        scanf("%lld%lld",&a[i].F,&a[i].S);
    sort(a,a+n);
    r[0]=0;
    for(ll i=1;i<n;i++)
        r[i]=r[i-1]+(a[i].F-a[i-1].S)*i;
    l[n-1]=0;
    for(ll i=n-2;i>=0;i--)
        l[i]=l[i+1]+(a[i+1].F-a[i].S)*(n-1-i);
    ll ans=INF;
    for(ll i=0;i<n-1;i++)
        ans=min(ans,l[i]+r[i]);
    printf("%lld\n",ans);
    return 0;
}

