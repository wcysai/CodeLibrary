#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],c[MAXN],ans;
int dp[MAXN];
int calc()
{
    fill(dp,dp+n,INF);
    for(int i=0;i<n;i++) *lower_bound(dp,dp+n,c[i+1])=c[i+1];
    return lower_bound(dp,dp+n,INF)-dp;
}
int main()
{
    vector<P> v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) c[a[i]]=b[i];
    ans=max(ans,n+calc());
    for(int i=1;i<=n;i++) c[b[i]]=a[i];
    ans=max(ans,n+calc());
    printf("%d\n",ans);
    return 0;
}

