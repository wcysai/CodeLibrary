#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 20
#define MAXM 20
using namespace std;
int bull[MAXN][MAXM];
int dp[2][1<<MAXM];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    memset(bull,0,sizeof(bull));
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int y;
            scanf("%d",&y);
            bull[i][y-1]=1;
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
        if(bull[0][i]) dp[0][(1<<i)]=1;
    for(int i=1;i<n;i++)
    {
        int comb=(1<<(i+1))-1;
        fill(dp[i%2],dp[i%2]+(1<<m),0);
        while(comb<(1<<m))
        {
            for(int j=0;j<m;j++)
                if((comb&(1<<j))&&(bull[i][j])) dp[i%2][comb]+=dp[(i-1)%2][comb&~(1<<j)];
            int x=comb&-comb,y=comb+x;
            comb=((comb&~y)/x>>1)|y;
        }
    }

    int s=0;
    for(int i=1;i<(1<<m);i++)
        s+=dp[(n-1)%2][i];
    printf("%d",s);
    return 0;
}
