#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<assert.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t;
vector<int> G[MAXN];
bool connected[MAXN][MAXN];
int color[MAXN];
bool dp[2*MAXN][2*MAXN];
int pre[2*MAXN][2*MAXN];
vector<int> res1[MAXN],res2[MAXN];
vector<int> ans1,ans2;
bool dfs(int v,int c)
{
	color[v]=c;
	if(c==1) res1[t].push_back(v); else res2[t].push_back(v);
	for(int i=0;i<G[v].size();i++)
	{
		if(color[G[v][i]]==c) return false;
		if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	int x;
	memset(connected,false,sizeof(connected));
	for(int i=0;i<n;i++)
	{
		while(scanf("%d",&x)==1)
		{
			if(x==0) break;
			connected[i][x-1]=true;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if((!connected[i][j])||(!connected[j][i]))
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
	memset(color,0,sizeof(color));
	t=0;
	for(int i=0;i<n;i++)
	{
		if(color[i]==0)
		{
			if(!dfs(i,1))
			{
				puts("No solution");
				return 0;
			}
			t++;
		}
	}
	memset(pre,-1,sizeof(pre));
	memset(dp,false,sizeof(dp));
	int a=100+res1[0].size()-res2[0].size();
	int b=100+res2[0].size()-res1[0].size();
	dp[0][a]=dp[0][b]=true;
	pre[0][a]=1;
	pre[0][b]=2;
	for(int i=0;i+1<t;i++)
	{
		for(int j=-100;j<=100;j++)
		{
			int num=j+100;
			if(!dp[i][num]) continue;
			a=res1[i+1].size()-res2[i+1].size();
			b=res2[i+1].size()-res1[i+1].size();
			dp[i+1][num+a]=true;
			pre[i+1][num+a]=1;
			dp[i+1][num+b]=true;
			pre[i+1][num+b]=2;
		}
	}
	int ans=100,now=-1;
	for(int i=-100;i<=100;i++)
		if(dp[t-1][i+100]&&(max(-i,i)<ans))
		{
			ans=max(-i,i);
			now=i+100;
		}
	for(int i=t-1;i>=0;i--)
	{
		if(pre[i][now]==1)
		{
			for(int j=0;j<res1[i].size();j++)
				ans1.push_back(res1[i][j]);
			for(int j=0;j<res2[i].size();j++)
				ans2.push_back(res2[i][j]);
			now=now-res1[i].size()+res2[i].size();
		}
		else
		{
			for(int j=0;j<res2[i].size();j++)
				ans1.push_back(res2[i][j]);
			for(int j=0;j<res1[i].size();j++)
				ans2.push_back(res1[i][j]);
			now=now-res2[i].size()+res1[i].size();
		}
	}
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	printf("%d ",ans1.size());
	for(int i=0;i<ans1.size();i++)
		printf("%d ",ans1[i]+1);
	puts("");
	printf("%d ",ans2.size());
	for(int i=0;i<ans2.size();i++)
		printf("%d ",ans2[i]+1);
	puts("");
	return 0;
}