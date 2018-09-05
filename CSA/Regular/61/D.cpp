#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,k;
int a[MAXN],dp[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]-=i;
    }
    fill(dp,dp+n,INF);
    for(int i=0;i<n;i++)
        *upper_bound(dp,dp+n,a[i])=a[i];
    printf("%d\n",n-(lower_bound(dp,dp+n,INF)-dp));
    return 0;
}

