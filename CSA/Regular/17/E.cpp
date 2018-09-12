#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
vector<int> G[MAXN];
int dp[MAXN],dp2[MAXN];
vector<int> vec;
int solve(int v)
{
	if(dp[v]!=-1) return dp[v];
	dp[v]=0;dp2[v]=0;
	for(int i=0;i<(int)G[v].size();i++)
	{
		int to=G[v][i];
		if(!solve(to)) dp[v]=1; 
	}
	if(dp[v])
	{
		dp2[v]=INF;
		for(int i=0;i<(int)G[v].size();i++)
		{
			int to=G[v][i];
			if(!dp[to]) dp2[v]=min(dp2[v],dp2[to]+1);
		}
	}
	else
	{
		for(int i=0;i<(int)G[v].size();i++)
		{
			int to=G[v][i];
			dp2[v]=max(dp2[v],dp2[to]+1);
		}
	}
	return dp[v];
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		int x;scanf("%d",&x);
		vec.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++) if(dp[i]==-1) solve(i);
	//for(int i=1;i<=n;i++) printf("%d %d\n",i,dp2[i]);
	int lose=INF,win=INF;
	for(int i=0;i<(int)vec.size();i++)
		if(dp[vec[i]]) win=min(win,dp2[vec[i]]); else lose=min(lose,dp2[vec[i]]);
	if(win!=INF)assert(win&1);
	if(lose!=INF)assert(!(lose&1));
	//printf("%d %d\n",win,lose);
	if(win<lose) puts("A"); else puts("B");
	return 0;
}
