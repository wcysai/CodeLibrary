#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
 
typedef long long LL;
#define MAX_V 5000 + 16
struct edge
{
	int to, rev;
	LL cap;
	edge(int to, LL cap, int rev) :to(to), cap(cap), rev(rev){}
};
 
vector<edge> G[MAX_V];	// 图的邻接表表示
int level[MAX_V];		// 顶点到源点的距离标号
int iter[MAX_V];		// 当前弧，在其之前的边已经没有用了
 
// 向图中加入一条从from到to的容量为cap的边
void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge(to, cap, G[to].size() ));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}
 
// 通过BFS计算从源点出发的距离标号
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty())
	{
		int v = que.front(); que.pop();
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge& e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}
 
// 通过DFS寻找增广路
LL dfs(int v, int t, LL f)
{
	if (v == t)
	{
		return f;
	}
	for (int& i = iter[v]; i < G[v].size(); ++i)
	{
		edge& e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to])
		{
			LL d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
 
	return 0;
}
 
// 求解从s到t的最大流
LL max_flow(int s, int t)
{
	LL flow = 0;
	for (;;)
	{
		bfs(s);
		if (level[t] < 0) 
		{
			return flow;
		}
		memset(iter, 0, sizeof(iter));
		LL f;
		while ((f = dfs(s, t, 0x3f3f3f3f3f3f3f3f)) > 0)
		{
			flow += f;
		}
	}
}
 
int vertex_count, visited[MAX_V];
// 遍历残余网络
void solve(int v)
{
	++vertex_count;
	visited[v] = true;
	for (int i = 0; i < int(G[v].size()); ++i) 
	{
		const edge &e = G[v][i];
		if (e.cap > 0 && !visited[e.to]) 
		{
			solve(e.to);
		}
	}
}
int main(int argc, char *argv[])
{
	int n, m, w;
	LL W = 0;
	scanf("%d%d", &n, &m);
	const int s = 0, t = n + 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w);
		if (w > 0)
		{
			W += w;
			add_edge(s, i, w);
		}
		if (w < 0)
		{
			add_edge(i, t, -w);
		}
	}
 
	int u, v;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &u, &v);
		add_edge(u, v, 0x3f3f3f3f3f3f3f3f);
	}
 
	LL max_profit = W - max_flow(s, t);
	solve(s);
	printf("%d %I64d\n", --vertex_count, max_profit);
	return 0;
}