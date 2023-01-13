#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int dp[MAXN][MAXN];
int main()
{
    scanf("%d",&k);
    dp[1][1]=dp[1][0]=1;
    for(int i=2;i<=k;i++){
        for(int l=0;l<=k;l++)
            for(int r=0;l+r<=k;r++){
                //no root
                add(dp[i][l+r],1LL*dp[i-1][l]*dp[i-1][r]%MOD);
                //root as single path
                add(dp[i][l+r+1],1LL*dp[i-1][l]*dp[i-1][r]%MOD);
                //connect to left
                add(dp[i][l+r],2LL*dp[i-1][l]*dp[i-1][r]%MOD*l%MOD);
                //connect to right
                add(dp[i][l+r],2LL*dp[i-1][l]*dp[i-1][r]%MOD*r%MOD);
                //combine
                if(l+r>=2) add(dp[i][l+r-1],2LL*dp[i-1][l]*dp[i-1][r]%MOD*(1LL*(l+r)*(l+r-1)/2)%MOD);
            }
    }
    printf("%d\n",dp[k][1]);
    return 0;
}

