#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100005
using namespace std;
int main()
{
    int dp[MAXN],a[MAXN],c[MAXN],n,m;
    bool judge[MAXN];
    scanf("%d %d",&n,&m);
    while(n!=0&&m!=0)
    {
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
      scanf("%d",&c[i]);
    memset(dp,-1,sizeof(dp));
    memset(judge,false,sizeof(judge));
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if (dp[j]>=0)
            {
                dp[j]=c[i];
            }
            else if(j<a[i]||dp[j-a[i]]<=0)
            {
                dp[j]=-1;
            }
            else
            {
                dp[j]=dp[j-a[i]]-1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(dp[i]>=0) cnt++;
    printf("%d\n",cnt);
    scanf("%d %d",&n,&m);
    }
    return 0;
}