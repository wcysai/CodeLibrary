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
int n,k,a[MAXN],b[MAXN],c[MAXN],dp[MAXN][3];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                int res;
                if(k==0) res=a[i+1]; else if(k==1) res=b[i+1]; else res=c[i+1];
                if(j==k) continue;
                dp[i+1][k]=max(dp[i+1][k],dp[i][j]+res);
            }
        }
    }
    int ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
    printf("%d\n",ans);
    return 0;
}

