/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 17:30:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,L;
int dp[MAXN];
P a[MAXN];
multiset<int> ms;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&L);L++;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) 
        {
            scanf("%d%d",&a[i].F,&a[i].S);
            for(int j=L;j-a[i].S>=a[i].F;j--)
                dp[j]=max(dp[j],dp[j-a[i].S]+1);
        }
        printf("%d\n",dp[L]);
    }
    return 0;
}

