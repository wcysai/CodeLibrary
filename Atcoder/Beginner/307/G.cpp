#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
ll sum[MAXN];
ll dp[MAXN],ndp[MAXN];
void upd(ll &a,ll b) {a=min(a,b);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    ll x=sum[n]/n;
    while(x*n>sum[n]) x--;
    while(x*n+n<=sum[n]) x++;
    ll num=sum[n]-1LL*x*n;
    assert(num>=0&&num<n);
    for(int i=0;i<=n;i++) dp[i]=INF;
    dp[0]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=n;j++) ndp[j]=INF;
        for(int j=0;j<=n;j++){
            if(dp[j]==INF) continue;
            ll s=sum[i];
            //choose 0
            upd(ndp[j],dp[j]+max(sum[i]-1LL*i*x-j,1LL*i*x+j-sum[i]));
            //choose 1
            upd(ndp[j+1],dp[j]+max(sum[i]-1LL*i*x-j-1,1LL*i*x+j+1-sum[i]));
        }
        swap(dp,ndp);
    }
    ll ans=dp[num];
    if(num) ans=min(ans,dp[num-1]);
    printf("%lld\n",ans);
    return 0;
}

