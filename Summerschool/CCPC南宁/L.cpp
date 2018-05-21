#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
using namespace std;
int a[MAXN*5],dp[MAXN*5];
int main()
{
    int k=0,x;
    while(scanf("%d",&x)==1)
    {
        if(x<0) continue;
        if(x>=10000)
            for(int j=0;j<5;j++)
                a[k]=x-10000,k++;
        else a[k]=x,k++;
    }
    fill(dp,dp+k,INF);
    for(int i=0;i<k;i++)
        *upper_bound(dp,dp+k,a[i])=a[i];
    printf("%d\n",lower_bound(dp,dp+k,INF)-dp);
    return 0;
}
