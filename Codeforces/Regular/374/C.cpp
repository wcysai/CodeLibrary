#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXN 5003
#define INF 1000000000
using namespace std;
struct edge{int to,time;};
vector<edge> G[MAXN];
void add_edge(int u,int v,int t)
{
    G[v].push_back((edge){u,t});
    G[u].push_back((edge){v,t});
}
int n,m,t,level[MAXN],cost[MAXN],save[MAXN];
queue<int> que;
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	memset(cost,0,sizeof(cost));
	while(!que.empty()) que.pop();
	level[s] = 1;
	que.push(s);
	while (!que.empty())
	{
		int v = que.front();
		que.pop();
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge &e = G[v][i];
			if (e.time > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				cost[e.to]=cost[v]+e.time;
				que.push(e.to);
			}
		}
	}
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++) G[i].clear();
    int x,y,z;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        x--;y--;
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    bfs(0);
    int ans=-INF;
    int rec=0,lev;
    for(int i=0;i<G[n-1].size();i++)
    {
        edge &e=G[n-1][i];
        if(cost[e.to]+e.time<=t)
        {
            ans=max(ans,level[e.to]+1);
            rec=e.to;
            lev=ans;
        }
    }
    memset(save,0,sizeof(save));
    save[0]=n-1;
    save[1]=rec;
    int cnt=2;
    lev-=2;
    while(rec!=0)
    {
        for(int i=0;i<G[rec].size();i++)
        {
             edge &e=G[rec][i];
             if(level[e.to]==lev)
             {
                 rec=e.to;
                 save[cnt]=rec;
                 break;
             }
        }
        lev--;
        cnt++;
    }
    printf("%d\n",ans);
    for(int i=cnt-1;i>=0;i--)
        printf("%d ",save[i]+1);
    return 0;
}
