#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int h[MAXN],s[MAXN],w[MAXN];
ll dp[305][605],ndp[305][605];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&h[i],&s[i],&w[i]);
    for(int i=0;i<=a;i++)
        for(int j=0;j<=a+b;j++)
            dp[i][j]=(i==0&&j==0?0:-INF);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=a;j++)
            for(int k=0;k<=a+b;k++)
                ndp[j][k]=-INF;
        for(int j=0;j<a;j++)
            for(int k=0;k<a+b;k++)
            {
                if(dp[j][k]==-INF) continue;
                ndp[j][k]=max(ndp[j][k],dp[j][k]);
                if(j+h[i]<a&&k+h[i]+s[i]<a+b) ndp[j+h[i]][k+h[i]+s[i]]=max(ndp[j+h[i]][k+h[i]+s[i]],dp[j][k]+w[i]);
            }
        swap(dp,ndp);
    }
    ll ans=-INF;
    for(int j=0;j<a;j++)
        for(int k=0;k<a+b;k++)
            ans=max(ans,dp[j][k]);
    printf("%lld\n",ans);
    return 0;
}