#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 15
#define INF 100000000
using namespace std;
int dp[1<<MAXN];
pair<int,int> coord[MAXN];
pair<int,int> rect[MAXN*(MAXN-1)];
int n;
int abs(int x)
{
    return x>0?x:-x;
}
int main()
{
    scanf("%d",&n);
    while(n!=0)
    {
        memset(coord,0,sizeof(coord));
        memset(rect,0,sizeof(rect));
    for(int i=0;i<n;i++)
        scanf("%d %d",&coord[i].first,&coord[i].second);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            rect[cnt].second=0;
            int length=coord[i].first==coord[j].first?1:abs(coord[i].first-coord[j].first);
            int width=coord[i].second==coord[j].second?1:abs(coord[i].second-coord[j].second);
            rect[cnt].first=length*width;
            for(int k=0;k<n;k++)
            {
                if(coord[k].first<=max(coord[i].first,coord[j].first)&&coord[k].first>=min(coord[i].first,coord[j].first)&&coord[k].second<=max(coord[i].second,coord[j].second)&&coord[k].second>=min(coord[i].second,coord[j].second))
                {
                    rect[cnt].second|=(1<<k);
                }
            }
            cnt++;
        }
    }
    fill(dp,dp+(1<<n),INF);
    dp[0]=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(dp[i]!=INF)
           for(int j=0;j<cnt;j++)
          {
              int news=i|rect[j].second;
            if(news!=i) dp[news]=min(dp[news],dp[i]+rect[j].first);
          }
    }
        printf("%d\n",dp[(1<<n)-1]);
        scanf("%d",&n);
    }
    return 0;
}

