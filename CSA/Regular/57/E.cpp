/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-10 10:17:50
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define MAXK 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,k,s;
int dp1[MAXN][MAXK],dp2[MAXN][MAXK];
int _mod(int x) {return x>=MOD?x-MOD:x;}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&s);
        for(int i=0;i<=k;i++)
            for(int j=0;j<=n;j++)
                dp1[i][j]=0;
        dp1[0][0]=1;
        for(int i=0;i<k;i++)
            for(int j=0;j<=n;j++)
            {
                if(!dp1[i][j]) continue;
                dp1[i+1][j+1]=_mod(dp1[i+1][j+1]+1LL*dp1[i][j]*(n-j)%MOD);
                dp1[i+1][j-1]=_mod(dp1[i+1][j-1]+1LL*dp1[i][j]*j%MOD);
            }
        for(int i=0;i<=k;i++)
            for(int j=0;j<=m;j++)
                dp2[i][j]=0;
        dp2[0][0]=1;
        for(int i=0;i<k;i++)
            for(int j=0;j<=m;j++)
            {
                if(!dp2[i][j]) continue;
                dp2[i+1][j+1]=_mod(dp2[i+1][j+1]+1LL*dp2[i][j]*(m-j)%MOD);
                dp2[i+1][j-1]=_mod(dp2[i+1][j-1]+1LL*dp2[i][j]*j%MOD);
            }
        int ans=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(i*(m-j)+j*(n-i)==s) ans=_mod(ans+1LL*dp1[k][i]*dp2[k][j]%MOD);
        printf("%d\n",ans);
    }
    return 0;
}

