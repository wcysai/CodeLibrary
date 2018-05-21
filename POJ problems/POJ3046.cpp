#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN_B 100005
using namespace std;
int main()
{
    int t,a,s,b,x,mem;
    int num[1000];
    int dp[2][MAXN_B];
    memset(num,0,sizeof(num));
    scanf("%d %d %d %d",&t,&a,&s,&b);
    for(int i=1;i<=a;i++)
    {
        scanf("%d",&x);
        num[x-1]++;
    }
    mem=0;
    dp[0][0]=1;
    dp[1][0]=1;
    for(int i=0;i<t;i++)
    {
      for(int j=1;j<=b;j++)
        {
            if(j-1-num[i]>=0)
            {
                dp[(i+1)%2][j]=(dp[(i+1)%2][j-1]+dp[i%2][j]-dp[i%2][j-1-num[i]]+1000000)%1000000;
            }
            else
            {
                dp[(i+1)%2][j]=(dp[(i+1)%2][j-1]+dp[i%2][j])%1000000;
            }
        }
    }
    for(int i=s;i<=b;i++)
       mem=(mem+dp[t%2][i])%1000000;
    printf("%d",mem);
    return 0;
}
        