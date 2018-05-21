#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,a[MAXN],dp[MAXN];
int nt(int x)
{
    return (1<<20)-1-x;
}
int main()
{
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        dp[x]=nt(x);
    }
    dp[0]=nt(0);
    for(int i=MAXN-1;i>=0;i--)
    {
        if(dp[i]!=0)
            for(int j=0;j<20;j++)
                if((i>>j)&1) dp[i-(1<<j)]|=dp[i];
    }
    int cnt=0;
    for(int i=0;i<MAXN;i++)
        if((dp[i]&nt(i))==nt(i)) cnt++;
    printf("%d\n",cnt);
    return 0;
}
