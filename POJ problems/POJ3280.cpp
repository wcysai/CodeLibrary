#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 2015
#define MAXER 50000
#define INF 100000000
using namespace std;
char pal[MAXN];
int mem1[MAXN],mem2[MAXN];
char a;
int dp[MAXN][MAXN];
int ans,sum;
int n,m,x,y,p;
struct pro
{
    char name;
    int cost;
};
pro table[26];
int conv(char x)
{
    int p;
    p=(int)(x-97);
    return p;
}
int findv(int x)
{
    return table[conv(pal[x])].cost;
}
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",&pal);
    memset(dp,0,sizeof(dp));
    memset(mem1,0,sizeof(mem1));
    memset(mem2,0,sizeof(mem2));
    for(int i=0;i<n;i++)
    {
        cin>>a>>x>>y;
        table[conv(a)].name=a;
        table[conv(a)].cost=min(x,y);
    }
    for(int i=0;i<m;i++)
        if(i==0) mem1[i]=findv(i);
           else mem1[i]=mem1[i-1]+findv(i);
    mem2[0]=mem1[m-1];
     for(int i=1;i<m;i++)
        mem2[i]=mem2[i-1]-findv(i-1);
    if(pal[0]!=pal[m-1]) dp[0][m-1]=findv(0)+findv(m-1);
    for(int i=m-2;i>=0;i--)
    {
        if(pal[i]==pal[0]) dp[0][i]=min(mem2[i+1],findv(i)+dp[0][i+1]);
        else dp[0][i]=findv(i)+dp[0][i+1];
    }
    for(int i=1;i<=m-1;i++)
    {
        if(pal[i]==pal[m-1]) dp[i][m-1]=min(mem1[i-1],findv(i)+dp[i-1][m-1]);
        else dp[i][m-1]=findv(i)+dp[i-1][m-1];
    }
    for(int i=1;i<m;i++)
        for(int j=m-2;j>=i;j--)
        {
          if (pal[i]==pal[j]) dp[i][j]=min(dp[i][j+1]+findv(j),min(dp[i-1][j+1],dp[i-1][j]+findv(i)));
          else dp[i][j]=min(dp[i][j+1]+findv(j),dp[i-1][j]+findv(i));
        }
        int ans=INF;
    for(int i=0;i<m;i++)
       ans=min(ans,dp[i][i]);
    for(int i=0;i<m-1;i++)
        ans=min(ans,dp[i][i+1]);
    printf("%d",ans);
    return 0;
}