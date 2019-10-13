#include<bits/stdc++.h>
#define MAXV 3005
#define MAXE 50000
#define INF 1000000
using namespace std;
struct edge{int to,cap,rev,id;};
int n,m,s,t;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
int u[MAXV],v[MAXV],g[MAXV];
int f[MAXV],c[MAXV];
void add_edge(int from,int to,int cap,int id)
{
    G[from].push_back((edge){to,cap,(int)G[to].size(),id});
    G[to].push_back((edge){from,0,(int)G[from].size()-1,-1});
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
bool vis[MAXV];
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&g[i]);
        if(!g[i]) add_edge(u[i],v[i],INF,i);
        else
        {
            add_edge(u[i],v[i],1,i);
            add_edge(v[i],u[i],INF,-1);
        }
    }
    int ans=max_flow(s,t);
    printf("%d\n",ans);
    queue<int> que;
    que.push(s);
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(auto e:G[v])
        {
            if(!vis[e.to]&&e.cap>0)
            {
                vis[e.to]=true;
                que.push(e.to);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) continue;
        for(auto e:G[i])
        {
            if(e.id<0) continue;
            if(!vis[e.to])
            {
                assert(e.cap==0);
                c[e.id]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=0;i<m;i++)
    {
        if(g[i])
        {
            memset(vis,false,sizeof(vis));
        }
    }
    return 0;
}
