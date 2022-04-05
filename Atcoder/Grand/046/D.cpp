#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN+1];
int n,dp[MAXN][MAXN][MAXN];
int sum[2][MAXN];
int comb[MAXN][MAXN];
bool valid[MAXN][MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		sum[0][i]=sum[0][i-1];
		sum[1][i]=sum[1][i-1];
		if(str[i]=='0') sum[0][i]++; else sum[1][i]++;
	}
	comb[0][0]=1;
	for(int i=1;i<=300;i++)
	{
		comb[i][0]=comb[i][i]=1;
		for(int j=1;j<i;j++)
		{
			comb[i][j]=comb[i-1][j-1];
			add(comb[i][j],comb[i-1][j]);
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;i+j<=n;j++)
			for(int k=0;k<=n;k++)
			{
				if(i==0&&j==0) dp[i][j][k]=1;
				else if(k==0) dp[i][j][k]=comb[i+j][j];
				else
				{
					dp[i][j][k]=dp[i][j][k-1];
					if(str[n-k+1]=='0'&&j) add(dp[i][j][k],dp[i][j-1][k]);
					if(str[n-k+1]=='1'&&i) add(dp[i][j][k],dp[i-1][j][k]);					
				}
			}
	}
	memset(valid,false,sizeof(valid));
	valid[0][0][0]=true;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i/2;j++)
			for(int k=0;j+k<=i/2;k++)
			{
				if(!valid[i][j][k]) continue;
				if(i+2<=n&&(str[i+1]=='0'||str[i+2]=='0')) valid[i+2][j+1][k]=true;
				if(i+2<=n&&(str[i+1]=='1'||str[i+2]=='1')) valid[i+2][j][k+1]=true;
				if(j+k>=2&&j) valid[i][j-1][k]=true;
				if(j+k>=2&&k) valid[i][j][k-1]=true;
				if(i+1<=n&&j+k>=1) valid[i+1][j][k]=true;
				if(i+1<=n&&j&&str[i+1]=='1') valid[i+1][j-1][k+1]=true;
				if(i+1<=n&&k&&str[i+1]=='0') valid[i+1][j+1][k-1]=true;
			}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i/2;j++)
			for(int k=0;j+k<=i/2;k++)
			{
				if(!valid[i][j][k]) continue;
				add(ans,dp[j][k][n-i]);
				if(str[i]=='0'&&j&&valid[i-1][j-1][k]) dec(ans,dp[j-1][k][n-(i-1)]);
				if(str[i]=='1'&&k&&valid[i-1][j][k-1]) dec(ans,dp[j][k-1][n-(i-1)]);
			}
	}
	printf("%d\n",ans);
	return 0;
}