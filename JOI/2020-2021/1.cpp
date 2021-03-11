#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],d[MAXN];
ll presum[MAXN],sufsum[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++) d[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++) presum[i]=presum[i-1]+max(0,1-d[i]);
    for(int i=n;i>=2;i--) sufsum[i]=sufsum[i+1]+max(0,d[i]+1);
    ll ans=INF;
    for(int i=1;i<=n;i++) ans=min(ans,max(presum[i],sufsum[i+1]));
    printf("%lld\n",ans);
}