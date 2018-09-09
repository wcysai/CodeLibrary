/*************************************************************************
    > File Name: E2.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-09 18:52:43
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
int n,k;
int dp[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<(1<<20);i++) dp[i]=(1<<20)-1;
    for(int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);
        dp[x]=x;
    }
    for(int i=0;i<20;i++)
        for(int j=0;j<(1<<20);j++)
            if(!(j&(1<<i))) dp[j]&=dp[j^(1<<i)];
    int ans=0;
    for(int i=1;i<=1000000;i++)
        if(dp[i]==i) ans++;
    printf("%d\n",ans+1);
    return 0;
}

