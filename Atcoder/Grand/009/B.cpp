#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,fa[MAXN],dp[MAXN];
vector<int> G[MAXN];
void dfs(int v)
{
	dp[v]=0;
	vector<int> vv;
	for(auto to:G[v])
	{
		dfs(to);
		vv.push_back(dp[to]);
	}
	sort(vv.begin(),vv.end());
	for(int i=(int)vv.size()-1;i>=0;i--) dp[v]=max(dp[v],vv[i]+(int)vv.size()-i);
}
int main()
{
	int ans=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		G[x].push_back(i);
	}
	dfs(1);
	printf("%d\n",dp[1]);
	return 0;
}