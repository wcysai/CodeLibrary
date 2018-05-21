#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 2005
#define INF 1000000005
using namespace std;
bool cmp1(int x,int y)
{
    return x<y;
}
bool cmp2(int x,int y)
{
    return x>y;
}
int dp[MAXN],a[MAXN],b[MAXN],n,t,ans;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n,cmp1);
    memset(dp,0,sizeof(dp));
    ans=INF;
    for(int i=0;i<n;i++)
    {
        t=INF;
        for(int j=0;j<n;j++)
        {
          t=min(t,dp[j]);
          dp[j]=max(b[j]-a[i],a[i]-b[j])+t;
        }
    }
    for(int i=0;i<n;i++)
        ans=min(ans,dp[i]);
     sort(b,b+n,cmp2);
     memset(dp,0,sizeof(dp));
     for(int i=0;i<n;i++)
    {
        t=INF;
        for(int j=0;j<n;j++)
        {
          t=min(t,dp[j]);
          dp[j]=max(b[j]-a[i],a[i]-b[j])+t;
        }
    }
    for(int i=0;i<n;i++)
        ans=min(ans,dp[i]);
    printf("%d",ans);
    return 0;
}