#include<bits/stdc++.h>
#define MAXV 505
#define MAXN 55
#define MAXM 8
#define INF 1000000000000000000LL
#define INF2 1000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to; ll cap; int rev;};
int n,m,V,a[MAXN][MAXM];
ll c[MAXN][MAXM];
int w[MAXN][MAXN];
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
void add_edge(int from,int to,ll cap)
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

ll dfs(int v,int t,ll f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            ll d=dfs(e.to,t,min(f,e.cap));
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
ll max_flow(int s,int t)
{
    ll flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        ll f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
int get_id(int x,int y)
{
    return (x-1)*(m+1)+y;
}
void add_edges(int x,int y,int w)
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
        {
            int l=max(a[x][i-1],a[y][j]),r=min(a[x][i],a[y][j+1]);
            if(l<r) add_edge(get_id(x,i),get_id(y,j+1),1LL*(r-l)*w);
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d%lld",&a[i][j],&c[i][j]);
        a[i][m+1]=1000000;
    }
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            scanf("%d",&w[i][j]);
    V=n*(m+1)+2;
    int s=V-1,t=V;
    for(int i=1;i<=n;i++) add_edge(s,get_id(i,1),INF),add_edge(get_id(i,m+1),t,INF);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            add_edge(get_id(i,j),get_id(i,j+1),c[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            add_edges(i,j,w[i][j]);
            add_edges(j,i,w[i][j]);
        }
    printf("%lld\n",max_flow(s,t));
    return 0;
}
