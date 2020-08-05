#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int dp[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        a[0]=a[1];
        int ans=2*(a[n]-a[1]);
        dp[0]=0; dp[2]=-INF;
        for(int i=4;i<=n;i+=2)
        {
            dp[i]=dp[i-4]+2*(a[i-3]-a[i-4]);
            if(i>=6) dp[i]=max(dp[i],dp[i-6]+2*(a[i-5]-a[i-6]));
        }
        printf("%d\n",ans-dp[n]);
    }
    return 0;
}