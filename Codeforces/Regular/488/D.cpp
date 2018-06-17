/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 02:46:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,double> P;
int n,k,a[MAXN],b[MAXN];
double dp[MAXN][MAXN][MAXN];
P v[MAXN];
bool cmp(P p,P q)
{
    if(p.F!=q.F) return p.F>q.F;
    return p.S>q.S;
}
bool C(double x)
{
    for(int i=1;i<=n;i++)
        v[i]=P(a[i],x*b[i]-a[i]);
    sort(v+1,v+n+1,cmp);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k]=-INF;
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i==1||v[i].F!=v[i-1].F)
        {
            for(int j=0;j<=i-1;j++)
                for(int k=0;j+k<=i-1;k++)
                {
                    dp[i][j][k]=dp[]
                }
        }
    }
    for(int i=0;i<=n;i++)
        if(dp[n][i]>=0) return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    double l=0,r=2e8;
    if(C(1)) puts("Yes");
    for(int i=0;i<500;i++)
    {
        double mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%lld\n",(ll)(r*1000+0.999));
    return 0;
}

