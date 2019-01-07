#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,h[MAXN];
int dp[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=INF;
        for(int j=1;j<=k;j++)
        {
            if(j>=i) break;
            dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}

