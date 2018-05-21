#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 40005
#define INF 100000000
using namespace std;
struct block
{
    int height;
    int limit;
    int num;
};
bool cmp(block m,block n)
{
    return m.limit<n.limit;
}
int main()
{
   int k,maxi,t;
   block a[MAXN];
   int dp[MAXN];
   maxi=-INF;
   scanf("%d",&k);
   for(int i=0;i<k;i++)
   {
       scanf("%d %d %d",&a[i].height,&a[i].limit,&a[i].num);
       maxi=max(maxi,a[i].limit);
   }
   sort(a,a+k,cmp);
   memset(dp,-1,sizeof(dp));
   dp[0]=0;
   t=-INF;
   for(int i=0;i<k;i++)
   {
     for(int j=0;j<=maxi;j++)
   {
       if(dp[j]>=0) dp[j]=a[i].num;
       else
       {
           if(j<a[i].height||dp[j-a[i].height]<=0||j>a[i].limit)
              dp[j]=-1;
           else dp[j]=dp[j-a[i].height]-1;
       }
       if(dp[j]>=0) t=max(t,j);
   }
   }
   printf("%d",t);
   return 0;
}