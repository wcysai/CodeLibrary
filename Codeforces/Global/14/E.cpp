#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,M;
void add(int &a,int b) {a+=b; if(a>=M) a-=M;}
//fix set of automatically on computers(must be nonadjacent)
//the number is \prod 2^(seglength-1)*(sum of segment length)!*\prod (segment length)!^(-1)
int dp[MAXN][MAXN],ndp[MAXN][MAXN];
int fact[MAXN],invf[MAXN],inv[MAXN];
/*
dp[i][j][k]: considering up to i,
length of last segment is j,
sum of lengths of all segments is k,
*/
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
int main()
{
    scanf("%d%d",&n,&M);
    fact[0]=invf[0]=1;
    for(int i=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%M;
    invf[n]=pow_mod(fact[n],M-2);
    for(int i=n-1;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%M;
    for(int i=1;i<=n;i++) inv[i]=1LL*invf[i]*fact[i-1]%M;
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<=i;k++)
            {
                if(!dp[j][k]) continue;
                if(i!=0&&i!=n-1&&j!=0) add(ndp[0][k],dp[j][k]);
                if(j==0) add(ndp[j+1][k+1],dp[j][k]);
                else add(ndp[j+1][k+1],2LL*dp[j][k]*inv[j+1]%M);
            }
        }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            add(ans,1LL*dp[i][j]*fact[j]%M);
    printf("%d\n",ans);
    return 0;
}