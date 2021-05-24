#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],dp[MAXN];
//intersecting intervals
//can prove in an optimal setting, no interval have length>=5
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[0]=a[1]; a[n+1]=a[n];
    for(int i=2;i<=n;i++)
    {
        dp[i]=a[i+1]-a[0];
        for(int j=i-2;j>=max(i-5,0);j--) dp[i]=min(dp[i],max(dp[j],a[i+1]-a[j]));
    }
    printf("%d\n",dp[n]/2);
    return 0;
}