#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],sum[MAXN];
ll preodd[MAXN],preeven[MAXN],sufodd[MAXN],sufeven[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll i=1;i<=n;i++)
    {
        preodd[i]=min(preeven[i-1]+(1-(a[i]&1)),min(preodd[i-1]+(1-(a[i]&1)),sum[i]));
        preeven[i]=min(preeven[i-1]+(a[i]<2?2-a[i]:a[i]&1),sum[i]);
    }
    for(ll i=n;i>=1;i--)
    {
        sufodd[i]=min(sufeven[i+1]+(1-(a[i]&1)),min(sufodd[i+1]+(1-(a[i]&1)),sum[n]-sum[i-1]));
        sufeven[i]=min(sufeven[i+1]+(a[i]<2?2-a[i]:a[i]&1),sum[n]-sum[i-1]);
    }
    ll ans=INF;
    for(ll i=0;i<=n;i++) 
    {
        ans=min(ans,preodd[i]+sufeven[i+1]);
        ans=min(ans,preeven[i]+sufodd[i+1]);
        ans=min(ans,preeven[i]+sufeven[i+1]);
    }
    printf("%lld\n",ans);
    return 0;
}

