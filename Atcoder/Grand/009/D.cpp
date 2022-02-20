#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
int dp[MAXN];
bool vis[MAXN];
void dfs(int v,int p)
{
	int once=0,twice=0;
	for(auto to:G[v])
	{
		if(to==p) continue;
		dfs(to,v);
		twice|=(once&dp[to]);
		once=(once|dp[to])&(~twice);
	}
	int msb=(twice==0?0:32-__builtin_clz(twice));
	while(once&(1<<msb)) msb++;
	dp[v]=((once>>msb)<<msb)|(1<<msb);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",31-__builtin_clz(dp[1]));
	return 0;
}