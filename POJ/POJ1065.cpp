#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 5020
using namespace std;
struct node
{
	int x,y;
};
bool cmp(node a,node b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int main()
{
   int n,p,ans,dp[MAXN];
   node wood[MAXN];
    scanf("%d",&p);
    for(int k=1;k<=p;k++)
    {
   scanf("%d",&n);
   fill(dp,dp+n,1);
   for(int i=0;i<n;i++)
     scanf("%d %d",&wood[i].x,&wood[i].y);
   sort(wood,wood+n,cmp);
   for(int i=1;i<n;i++)
     for(int j=0;j<i;j++)
       if(wood[i].y<wood[j].y&&wood[i].x!=wood[j].x) dp[i]=max(dp[i],dp[j]+1);
    ans=0;
    for(int i=0;i<n;i++)
     ans=max(ans,dp[i]);
     printf("%d\n",ans);
   }
    return 0;
} 