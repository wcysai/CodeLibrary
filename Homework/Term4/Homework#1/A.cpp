#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<assert.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,dp[MAXN][MAXN],pre[MAXN][MAXN];
char str[MAXN];
void solve(int l,int r)
{
	if(l==r) return;
	if(r-l==1)
	{
		if(str[l]=='('||str[l]==')') printf("()"); else printf("[]");
		return;
	}
	if(pre[l][r]==-1)
	{
		printf("%c",str[l]);
		solve(l+1,r-1);
		printf("%c",str[r-1]);
		return;
	}
	int k=pre[l][r];
	solve(l,k);
	solve(k,r);
}
int main()
{
	gets(str);
	n=strlen(str);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i][i+1]=1;
	for(int len=2;len<=n;len++)
	{
		for(int i=0;i+len<=n;i++)
		{
			int j=i+len;
			dp[i][j]=INF;
			if((str[i]=='('&&str[j-1]==')')||(str[i]=='['&&str[j-1]==']')) {dp[i][j]=dp[i+1][j-1]; pre[i][j]=-1;}
			for(int k=i+1;k<j;k++)
			{
				if(dp[i][k]+dp[k][j]<dp[i][j])
				{
					pre[i][j]=k;
					dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
	solve(0,n);
	printf("\n");
	return 0;
}
