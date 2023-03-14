#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[MAXN][MAXN];
int fact[2*MAXN],invf[2*MAXN];
int dp[MAXN][MAXN][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=4000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[4000]=pow_mod(fact[4000],MOD-2);
    for(int i=3999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i>1){
                add(dp[i][j][0],dp[i-1][j][0]);
                add(dp[i][j][1],dp[i-1][j][1]);
                if(str[i][j]=='Y'&&str[i-1][j]=='Y') 
                {
                    add(dp[i][j][0],comb(i+j-3,i-2));
                    add(dp[i][j][1],comb(i+j-3,i-2));
                    add(dp[i][j][1],2LL*dp[i-1][j][0]%MOD);
                }
            }
            if(j>1){
                add(dp[i][j][0],dp[i][j-1][0]);
                add(dp[i][j][1],dp[i][j-1][1]);
                if(str[i][j]=='Y'&&str[i][j-1]=='Y') 
                {
                    add(dp[i][j][0],comb(i+j-3,j-2));
                    add(dp[i][j][1],comb(i+j-3,j-2));
                    add(dp[i][j][1],2LL*dp[i][j-1][0]%MOD);
                }
            }
        }
    printf("%d\n",dp[n][m][1]);
    return 0;
}

