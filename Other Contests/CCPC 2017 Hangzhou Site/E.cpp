#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,m;
int dp[MAXN][MAXN];
int pow_mod(int a,int i,int m)
{
    if(i==0) return 1;
    int s=1;
    while(i>0)
     {
         if(i&1) s=(1LL*s*a)%m;
         a=(1LL*a*a)%m;
         i>>=1;
     }
     return s;
}
int fact[MAXN],invf[MAXN],p2[MAXN*MAXN];
int cnk(int i,int j)
{
	return 1LL*fact[i]*invf[j]%m*invf[i-j]%m;
}
int main()
{
	scanf("%d%d",&n,&m);
	fact[0]=1;invf[0]=1;p2[0]=1;
	for(int i=1;i<=n;i++)
	{
		fact[i]=1LL*fact[i-1]*i%m;
		invf[i]=pow_mod(fact[i],m-2,m);
	}
	for(int i=1;i<=n*n;i++) p2[i]=1LL*p2[i-1]*2%m;
	int ans=0;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			dp[i][j]=(1LL*j*dp[i-1][j]+dp[i-1][j-1])%m;
	}
	int sum=0;
	for(int i=0;i<=n;i++)
	{
		sum=0;
		for(int j=0;j<=i;j++)
			sum=(sum+(1LL*dp[i][j]+1LL*dp[i][j+1]*(j+1))%m*p2[(n-i)*j]%m*pow_mod(2,pow_mod(2,n-i,m-1),m))%m;
		if(i&1) ans=(ans+m-1LL*cnk(n,i)*sum%m)%m;
		else ans=(ans+1LL*cnk(n,i)*sum)%m;
	}
	printf("%d\n",ans);
	return 0;
}