#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 40002
#define INF 100000000
using namespace std;
int dp[MAXN],a[MAXN];
int main()
{
    int n,p;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
    scanf("%d",&p);
    fill(dp,dp+p,INF);
    fill(a,a+MAXN,0);
    for(int i=0;i<p;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<p;i++)
        *lower_bound(dp,dp+p,a[i])=a[i];
    printf("%d\n",lower_bound(dp,dp+p,INF)-dp);
    }
    return 0;
}