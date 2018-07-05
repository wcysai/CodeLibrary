/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-05 14:29:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<assert.h>
#define MAXN 1005
#define MAXK 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t;
int dp[MAXN][MAXK][2];//0:not chosen 1:chosen
int now[MAXK];
int m,s;
int w[MAXN],c[MAXN];
bool f;
int main()
{
    scanf("%d%d",&n,&t);
    f=true;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&m,&s);
        for(int j=1;j<=m;j++)
            scanf("%d%d",&w[j],&c[j]);
        if(s==0)
        {
            for(int k=0;k<=t;k++)
                dp[0][k][0]=now[k],dp[0][k][1]=-INF;
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<=t;k++)
                {
                    dp[j][k][1]=dp[j-1][k][1];
                    if(k>=w[j]) dp[j][k][1]=max(dp[j][k][1],max(dp[j-1][k-w[j]][1]+c[j],dp[j-1][k-w[j]][0]+c[j]));
                    dp[j][k][0]=dp[j-1][k][0];
                }
            }
            for(int k=0;k<=t;k++)
                now[k]=dp[m][k][1];
            if(now[t]==-INF) f=false;
        }
        else if(s==1)
        {
            for(int k=0;k<=t;k++)
                dp[0][k][0]=now[k],dp[0][k][1]=-INF;
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<=t;k++)
                {
                    dp[j][k][1]=dp[j-1][k][1];
                    if(k>=w[j]) dp[j][k][1]=max(dp[j][k][1],dp[j-1][k-w[j]][0]+c[j]);
                    dp[j][k][0]=dp[j-1][k][0];
                }
            }
            for(int k=0;k<=t;k++)
                now[k]=max(dp[m][k][0],dp[m][k][1]);
        }
        else
        {
            for(int k=0;k<=t;k++)
                dp[0][k][0]=now[k],dp[0][k][1]=-INF;
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<=t;k++)
                {
                    dp[j][k][0]=dp[j-1][k][0];
                    if(k>=w[j]) dp[j][k][0]=max(dp[j][k][0],dp[j-1][k-w[j]][0]+c[j]);
                }
            }
            for(int k=0;k<=t;k++)
                now[k]=dp[m][k][0];
        }
        /*for(int k=0;k<=t;k++)
            printf("%d ",now[k]);
        puts("");*/
    }
    if(!f) puts("-1"); else printf("%d\n",now[t]);
    return 0;
}

