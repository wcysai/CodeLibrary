#include<bits/stdc++.h>
#define MAXN 85
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll dp[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0]=1000;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
            {
                ll cnt=dp[j]/a[j];
                dp[i]=max(dp[i],dp[j]+cnt*(a[i]-a[j]));
            }
        }
    }
    printf("%lld\n",dp[n]);
}