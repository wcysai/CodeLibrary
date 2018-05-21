#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int a[MAXN],dp[MAXN];
int n,k,t;
int solve()
{
    fill(dp,dp+n,INF);
    for(int i=0;i<n;i++)
        *upper_bound(dp,dp+n,a[i])=a[i];
    return lower_bound(dp,dp+n,INF)-dp;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(solve()>=n-k) {printf("A is a magic array.\n"); continue;}
        for(int i=0;i<(n+1)/2;i++)
            swap(a[i],a[n-1-i]);
         if(solve()>=n-k) {printf("A is a magic array.\n"); continue;}
         printf("A is not a magic array.\n");
    }
    return 0;
}
