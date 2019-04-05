#include<bits/stdc++.h>
#define MAXN 805
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s,t;
int u[MAXM],v[MAXM],c[MAXM];
struct edge{int to,cap,rev;};
vector<edge> G[MAXN];
int level[MAXN];
int iter[MAXN];
bool vis[2][MAXN];
bool f=true;
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
        int v=que.front();que.pop();
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
void dfs2(int id,int v)
{
    vis[id][v]=true; 
    for(auto e:G[v])
    {
        if(e.cap==0) continue;
        if(!vis[id][e.to]) dfs2(id,e.to);
    }
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
        while((f=dfs(s,t,INF))>0) flow+=f;
    }
}
void clear_graph()
{
    for(int i=1;i<=n;i++) G[i].clear();
}
void construct_graph()
{
    for(int i=0;i<m;i++)
    {
        add_edge(u[i],v[i],c[i]);
        add_edge(v[i],u[i],c[i]);
    }
}
int main()
{
    freopen("attack.in","r",stdin);
    freopen("attack.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<m;i++) scanf("%d%d%d",&u[i],&v[i],&c[i]);
    construct_graph();
    max_flow(s,t);
    memset(vis,false,sizeof(vis));
    dfs2(0,s); 
    clear_graph();
    construct_graph();
    max_flow(t,s);
    dfs2(1,t);
    for(int i=1;i<=n;i++)
    {
        if(vis[0][i]==vis[1][i])
        {
            puts("AMBIGUOUS");
            return 0;
        }
    }
    puts("UNIQUE");
    return 0;
}
