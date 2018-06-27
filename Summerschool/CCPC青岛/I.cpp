#include<bits/stdc++.h>
#define MAXV 205
#define MAXE 1005
#define INF 10000000
using namespace std;
struct edge{int to,cap,rev;};
int E,V,s,t;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
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
        int v=que.front(); que.pop();
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
    int query;
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d %d %d %d",&V,&E,&s,&t);
        for(int i=1;i<=V;i++)
            G[i].clear();
        for(int i=0;i<E;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            add_edge(x,y,z*(E+1)+1);
        }
        printf("%d\n",max_flow(s,t)%(E+1));
    }
    return 0;
}
