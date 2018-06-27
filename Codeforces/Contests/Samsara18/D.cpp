#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],pre[MAXN][MAXN],match[MAXN];
vector<int> G[MAXN];
bool now[MAXN],used[MAXN];
vector<P> ans;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void bfs(int x)
{
	queue<int> que;
	memset(used,false,sizeof(used));
	while(que.size()) que.pop();
	que.push(x);
	used[x]=true;
	while(que.size())
	{
		int v=que.front(); que.pop();
		for(int i=0;i<(int)G[v].size();i++)
			if(!used[G[v][i]])
			{
				used[G[v][i]]=true;
				pre[x][G[v][i]]=v;
				que.push(G[v][i]);
			}
	}
	return;
}
void solve(int x,int y)
{
	if(x==y) return;
	if(now[pre[x][y]])
	{
		ans.push_back(P(pre[x][y]+1,y+1));
		now[pre[x][y]]=false;
		now[y]=true;
		solve(x,pre[x][y]);
	}
	else
	{
		solve(x,pre[x][y]);
		ans.push_back(P(pre[x][y]+1,y+1));
		now[pre[x][y]]=false;
		now[y]=true;
	}
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<k;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v)) res++;
        }
    }
    return res;
}
int main()
{
	scanf("%d%d",&n,&k);
	memset(now,false,sizeof(now));
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
		a[i]--;now[a[i]]=true;
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",&b[i]);
		b[i]--;
	}
	getchar();
	for(int i=0;i<n;i++)
		G[i].clear();
	char ch;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%c",&ch);
			if(ch=='1') G[i].push_back(j);
		}
		getchar();
	}
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
		bfs(i);
	for(int i=0;i<n;i++)
		G[i].clear();
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			if(a[i]==b[j]||pre[a[i]][b[j]]!=-1)
				add_edge(i,k+j);
	if(bipartite_matching()!=k) {puts("NO"); return 0;}
	puts("YES");
	memset(used,false,sizeof(used));
	ans.clear();
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(used[j]) continue;
			if(now[b[match[j]-k]]) continue;
			used[j]=true;
			solve(a[j],b[match[j]-k]);
			break;
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].F,ans[i].S);
	return 0;
}