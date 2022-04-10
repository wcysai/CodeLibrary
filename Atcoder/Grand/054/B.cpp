#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,w[MAXN];
int fact[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int dp[MAXN][MAXN*MAXN],ndp[MAXN][MAXN*MAXN];
int main()
{
	fact[0]=1;
	for(int i=1;i<=100;i++) fact[i]=1LL*i*fact[i-1]%MOD;
	scanf("%d",&n);
	int s=0;
	for(int i=1;i<=n;i++) {scanf("%d",&w[i]); s+=w[i];}
	if(s&1) {puts("0"); return 0;}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=0;j<=i-1;j++)
			for(int k=0;k<=min(s,i*100);k++)
			{
				if(!dp[j][k]) continue;
				add(ndp[j][k],dp[j][k]);
				add(ndp[j+1][k+w[i]],dp[j][k]);
			}
		swap(dp,ndp);
	}
	int ans=0;
	for(int i=1;i<=n-1;i++) add(ans,1LL*fact[i]*fact[n-i]%MOD*dp[i][s/2]%MOD);
	printf("%d\n",ans);
	return 0;
}