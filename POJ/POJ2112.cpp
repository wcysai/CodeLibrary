#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define MAX_V 1000
#define INF 1000000
using namespace std;
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
int d[MAX_V][MAX_V];
int k,c,m,s,n,t;
void add_edge(int from,int to,int cap)
{
   G[from].push_back((edge){to,cap,G[to].size()});
   G[to].push_back((edge){from,0,G[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();que.pop();
        for(int i=0;i<G[v].size();i++)
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
    for(int &i=iter[v];i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to])
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
        {
            flow+=f;
        }
    }
}
bool C(int x)
{
 s=n;t=n+1;
    for(int i=0;i<n+2;i++)
        G[i].clear();
    for(int i=0;i<k;i++)
        add_edge(i,t,m);
    for(int i=k;i<n;i++)
        add_edge(s,i,1);
    for(int i=0;i<k;i++)
        for(int j=k;j<n;j++)
          if(d[i][j]<=x) add_edge(j,i,1);
    return max_flow(s,t)==c;
}
int main()
{
    scanf("%d%d%d",&k,&c,&m);
    n=k+c;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
          scanf("%d",&d[i][j]);
          if(i!=j&&d[i][j]==0) d[i][j]=INF;
        }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
   int lb=0,ub=200*n;
   while(ub-lb>1)
   {
       int mid=(lb+ub)/2;
       if(C(mid)) ub=mid; else lb=mid;
   }
printf("%d\n",ub);
}
