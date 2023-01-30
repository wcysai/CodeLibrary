#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,s,k,a[MAXN];
int l[MAXN],r[MAXN];
ll dp[MAXN][2];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]<=2*s) {l[i]=max(0,a[i]-s); r[i]=min(a[i],s);}
            else {l[i]=s; r[i]=a[i]-s;}
        }
        dp[2][0]=1LL*a[1]*l[2];
        dp[2][1]=1LL*a[1]*r[2];
        for(int i=3;i<=n;i++){
            dp[i][0]=min(dp[i-1][0]+1LL*(i==n?a[i]:l[i])*(a[i-1]-l[i-1]),dp[i-1][1]+1LL*(i==n?a[i]:l[i])*(a[i-1]-r[i-1]));
            dp[i][1]=min(dp[i-1][0]+1LL*(i==n?a[i]:r[i])*(a[i-1]-l[i-1]),dp[i-1][1]+1LL*(i==n?a[i]:r[i])*(a[i-1]-r[i-1]));
            //printf("i=%d l=%d r=%d dp0=%lld dp1=%lld\n",i,l[i],r[i],dp[i][0],dp[i][1]);
        }
        printf("%lld\n",min(dp[n][0],dp[n][1]));
    }
    return 0;
}

