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
#define MAXN 20
#define MAXS 20000
using namespace std;
int n,m;
int a[MAXN];
bool dp[MAXS][MAXN];
int main()
{
    scanf("%d",&n);
    while(n)
    {
        n*=2;
        scanf("%d",&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[0][i]=true;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int next=j+1>=n?0:j+1;
                bool f=false;
                for(int k=1;k<=a[j];k++)
                {
                    if(i-k<0) break;
                    if(!dp[i-k][next]) {f=true; break;}
                }
                dp[i][j]=f;
            }
        }
        printf("%d\n",dp[m][0]?1:0);
        scanf("%d",&n);
    }
    return 0;
}
