/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-02 19:50:11
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
void relax(ll &a,ll b) {a=min(a,b);}
struct box
{
    ll h,p;
};
bool cmp(box x,box y)
{
    return min(x.h,y.h-x.p)>min(y.h,x.h-y.p);
}
box a[MAXN];
ll dp[MAXN][MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld%lld",&a[i].h,&a[i].p);
    sort(a+1,a+n+1,cmp);
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=i;j++)
        {
            if(dp[i][j]==INF) continue;
            ll &cur=dp[i][j];
            relax(dp[i+1][j],cur);
            if(cur<=a[i+1].h) relax(dp[i+1][j+1],cur+a[i+1].p);
        }
    }
    for(ll i=n;i>=0;i--)
    {
        if(dp[n][i]!=INF) 
        {
            printf("%lld\n",i);
            break;
        }
    }
    return 0;
}

