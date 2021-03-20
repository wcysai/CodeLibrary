#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
ll pre[MAXN],suf[MAXN],sum[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) pre[i]=max(0,a[i])+pre[i-1];
    for(int i=n;i>=1;i--) suf[i]=max(0,a[i])+suf[i+1];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll ans=-INF;
    for(int i=1;i<=n-k+1;i++)
    {
        int l=i,r=i+k-1;
        ans=max(ans,max(0LL,sum[r]-sum[l-1])+pre[l-1]+suf[r+1]);
    }
    printf("%lld\n",ans);
    return 0;
}