#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int dp[MAXN][MAXN];
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int i=a;i<=c;i++)
        for(int j=b;j<=d;j++)
        {
            if(i==a) dp[i][j]=pow_mod(a,j-b);
            else if(j==b) dp[i][j]=pow_mod(b,i-a);
            else 
            {
                dp[i][j]=1LL*dp[i-1][j]*j%MOD;
                add(dp[i][j],1LL*dp[i][j-1]*i%MOD);
                dec(dp[i][j],1LL*dp[i-1][j-1]*(i-1)%MOD*(j-1)%MOD);
            }
        }
    printf("%d\n",dp[c][d]);
    return 0;
}