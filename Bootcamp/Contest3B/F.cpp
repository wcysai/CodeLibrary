/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-03 20:44:03
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXV];
struct edge{int to,cap,rev;};
int V;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front(); que.pop();
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v,int t,int f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
int main()
{
    scanf("%d",&n);
    int source=n+1,sink=n+2;
    int s=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]>=0) s+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        if(a[i]>=0) add_edge(source,i,a[i]); else add_edge(i,sink,-a[i]);
        for(int j=0;j<k;j++)
        {
            int x;
            scanf("%d",&x);
            add_edge(i,x,INF);
        }
    }
    s-=max_flow(source,sink);
    printf("%d\n",s);
    return 0;
}

