#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXX 200005
#define MAXN 105
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,X,M;
int fact[MAXX],invf[MAXX];
int dp[2][MAXN][12005];
//dp[i][j][k]: inserted i elements j interval closed their sum equal to k
void add(int &a,int b) {a+=b; if(a>=M) a-=M;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%M;
        a=1LL*a*a%M;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%M*invf[n-k]%M;
}
int main()
{
    scanf("%d%d%d",&N,&X,&M);
    fact[0]=invf[0]=1;
    for(int i=1;i<=X+N;i++) fact[i]=1LL*fact[i-1]*i%M;
    invf[X+N]=pow_mod(fact[X+N],M-2);
    for(int i=X+N-1;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%M;
    memset(dp,0,sizeof(dp));
    dp[1][0][0]=1;
    for(int i=1;i<N;i++)
    {
        int now=i&1,nxt=1-now;
        memset(dp[nxt],0,sizeof(dp[nxt]));
        for(int j=0;j<=i-1;j++)
        {
            for(int k=0;k<=i*(i+1);k++)
            {
                if(!dp[now][j][k]) continue;
                add(dp[nxt][j+1][k],1LL*(j+2)*dp[now][j][k]%M);
                add(dp[nxt][j][k+(i+1)],1LL*dp[now][j][k]*(2*j+2)%M);
                if(j) add(dp[nxt][j-1][k+2*(i+1)],1LL*dp[now][j][k]*(j)%M);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=10100;i++) add(ans,1LL*dp[N&1][0][i]*comb(X+N-i-1,N)%M);
    printf("%d\n",ans);
    return 0;
}
