#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXN 10005
#define MAXM 100005
using namespace std;
int n,m;
int a[MAXN];
bool dp[MAXM][2];
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m) break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        memset(dp,false,sizeof(dp));
        dp[a[0]][1]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=m;j>a[i];j--)
            {
                dp[j][1]|=dp[j-a[i]][0];
                dp[j][0]|=dp[j-a[i]][1];
            }
            dp[a[i]][1]=true;
        }
        int cnt=0;
        for(int i=0;i<=m;i++)
            if(dp[i][1]&&!dp[i][0]) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
