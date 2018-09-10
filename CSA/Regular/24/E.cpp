/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-10 11:20:48
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> P;
int n;
db sum,a[MAXN];
db dp[1<<20];
long double solve(int mask)
{
    if(mask==((1<<n)-1)) return 0;
    if(dp[mask]!=-1) return dp[mask];
    db cnt=0;
    for(int i=0;i<n;i++)
        if(!(mask&(1<<i))) cnt+=a[i];
    db ans=0;
    for(int i=0;i<n;i++)
        if(!(mask&(1<<i))) ans+=a[i]/sum*(1+solve(mask|(1<<i)));
    ans+=(sum-cnt)/sum;
    return dp[mask]=ans/cnt*sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%Lf",&a[i]);
        sum+=a[i];
    }
    for(int i=0;i<(1<<n);i++) dp[i]=-1;
    printf("%.10Lf\n",solve(0));
    return 0;
}

