#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 101
#define MAXV 205
#define INF 1000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev;};
int n,m,a[MAXN][MAXN];
ll rs[MAXN],cs[MAXN];
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
signed main()
{
    scanf("%lld%lld",&n,&m);
    int s=n+m+1,t=n+m+2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&a[i][j]);
            rs[i]+=a[i][j]; cs[j]+=a[i][j];
            if(a[i][j]<0) add_edge(i,n+j,INF);
            else add_edge(i,n+j,a[i][j]);
        }
    ll ans=0;
    for(int i=1;i<=n;i++) 
    {
        if(rs[i]>=0)
        {
            ans+=rs[i];
            add_edge(s,i,rs[i]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(cs[i]>=0)
        {
            ans+=cs[i];
            add_edge(n+i,t,cs[i]);
        }
    }
    ans-=max_flow(s,t);
    printf("%lld\n",ans);
    return 0;
}

