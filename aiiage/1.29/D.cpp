#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int t,n;
vector<int> G[MAXN];
int find_res(int x,int p,int state)
{
	if(p!=-1&&G[x].size()==1) return 1;
	int res=INF,cnt=0;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]==p) continue;
		if(state==0) res=min(res,find_res(G[x][i],x,1-state));
		else if(state==1) cnt+=find_res(G[x][i],x,1-state);
	}
	if(state==0) return res; else return cnt;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("1\n");
			return 0;
		}
		for(int i=0;i<n;i++)
			G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		printf("%d\n",find_res(0,-1,0));
	}
	return 0;
}