/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 18:53:27
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int a[MAXN],dp[MAXN];
bool block[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(block,false,sizeof(block));
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        block[x]=true;
    }
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    for(int i=k-1;i>=1;i--)
        a[i]=min(a[i],a[i+1]);
    fill(dp,dp+n,INF);
    dp[0]=0;
    for(int i=0;i<n-1;i++)
    {
        if(block[i]) continue;
        for(int j=1;j<=k;j++)
            dp[i+j]=min(dp[i+j],dp[i]+a[j]);
    }
    return 0;
}

