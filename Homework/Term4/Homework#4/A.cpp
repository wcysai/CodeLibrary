#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G;
int n,m;
bool valid[10];
int digit[MAXN],pre[MAXN];
int save[50];
void solve(int x)
{
	if(pre[x]!=-1) solve(pre[x]);
	printf("%d",digit[x]);
}
int main()
{
	int cnt=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		cnt++;
		memset(valid,true,sizeof(valid));
		G.clear();
		for(int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			valid[x]=false;
		}
		for(int i=0;i<10;i++) if(valid[i]) G.push_back(i);
		memset(digit,-1,sizeof(digit));
		memset(pre,-1,sizeof(pre));
		queue<int> que;
		while(que.size()) que.pop();
		printf("Case %d: ",cnt);
		bool f=true;
		for(int i=0;i<G.size();i++)
		{
			if(G[i]==0) continue;
			if(G[i]%n==0)
			{
				printf("%d\n",G[i]);
				f=false;
				break;
			}
			que.push(G[i]);
			if(digit[G[i]%n]==-1) digit[G[i]%n]=G[i];
		}
		if(!f) continue;
		f=true;
		while(que.size())
		{
			int p=que.front();
			que.pop();
			for(int i=0;i<G.size();i++)
			{
				int to=(p*10+G[i])%n;
				if(digit[to]==-1) 
				{
					digit[to]=G[i];
					pre[to]=p;
					que.push(to);
					if(to==0) {f=false; break;}
				}
			}
			if(!f) break;
		}
		if(f) {puts("-1"); continue;}
		solve(0);
		puts("");
	}
	return 0;
}