#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,h[MAXN],dp[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    dp[1]=0;dp[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+abs(h[i]-h[i-1]);
        dp[i]=min(dp[i],dp[i-2]+abs(h[i]-h[i-2]));
    }
    printf("%d\n",dp[n]);
    return 0;
}

