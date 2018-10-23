/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-23 18:26:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P a[MAXN];
int dp[MAXN][MAXN];
void add(int &a,int b)
{
    a+=b;
    if(a>=MOD) a-=MOD;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].F,&a[i].S);
    sort(a,a+n);
    vector<int> eve[MAXN];
    for(int i=0;i<n;i++) eve[a[i].F].push_back(i);
    for(int i=n-1;i>=0;i--)
    {
        dp[i][a[i].S-a[i].F+1]=1;
        for(int len=a[i].S-a[i].F;len>=0;--len)
        {
            dp[i][len]=dp[i][len+1];
            for(int j:eve[a[i].F+len])
            {
                if(i==j) continue;
                if(a[j].S<=a[i].S) add(dp[i][len],dp[i][a[j].S-a[i].F+1]);
                else if(len) add(dp[i][len],dp[j][a[i].S-a[j].F+1]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) add(ans,dp[i][0]);
    printf("%d\n",ans);
    return 0;
}

