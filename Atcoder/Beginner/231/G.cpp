#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int n,k,a[MAXN],dp[MAXN][MAXN];
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
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!dp[i][j]) continue;
            add(dp[i+1][j],1LL*dp[i][j]*a[i+1]%MOD);
            add(dp[i+1][j+1],1LL*dp[i][j]*(k-j)%MOD);
        }
    }
    int ans=0;
    for(int i=0;i<=min(n,k);i++) add(ans,1LL*dp[n][i]*pow_mod(n,k-i)%MOD);
    ans=1LL*ans*pow_mod(pow_mod(n,k),MOD-2)%MOD;
    printf("%d\n",ans);
    return 0;
}