#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#define MAXN 1005
#define INF 100000000
using namespace std;
struct milk
{
    int start;
    int ending;
    int effcy;
};
bool cmp(milk m,milk n)
{
    return m.start<n.start;
}
int main()
{
    int n,m,r;
    milk a[MAXN];
    int dp[MAXN];
    scanf("%d %d %d",&n,&m,&r);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",&a[i].start,&a[i].ending,&a[i].effcy);
    sort(a,a+m,cmp);
    memset(dp,0,sizeof(dp));
    dp[0]=a[0].effcy;
    for(int i=1;i<m;i++)
    {
        dp[i]=a[i].effcy;
       for(int j=i-1;j>=0;j--)
        if(a[j].ending+r<=a[i].start)
          dp[i]=max(dp[i],dp[j]+a[i].effcy);
    }
    int x=-INF;
    for(int i=0;i<m;i++)
      x=max(x,dp[i]);
    printf("%d",x);
    return 0;
}