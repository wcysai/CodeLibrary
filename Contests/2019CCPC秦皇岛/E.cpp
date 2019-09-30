#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 50005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev;};
vector<edge> G[MAXM];
int level[MAXM];
int iter[MAXM];
int T,n,m,a,b;
int p[MAXN],e[MAXN];
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
/*
4i-3: vert in
4i-2 vert out
4i-1 hori in
4i hori out
*/
char str[MAXN][MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&a,&b);
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        for(int i=1;i<=a;i++) scanf("%d",&p[i]);
        for(int i=1;i<=b;i++) scanf("%d",&e[i]);
        int V=4*(n+2)*m,S=V+1,T=V+2;
        for(int i=1;i<=T;i++) G[i].clear();
        for(int i=1;i<=(n+2)*m;i++)
        {
            add_edge(4*i-3,4*i-2,1);
            add_edge(4*i-1,4*i,1);
            add_edge(4*i-3,4*i-1,1);
            add_edge(4*i-1,4*i-3,1);
        }
        for(int i=1;i<=a;i++)
        {
            int x=p[i];
            add_edge(S,4*x-3,1);
            add_edge(4*x-2,4*(x+m)-3,1);
        }
        for(int i=1;i<=b;i++)
        {
            int x=(n+1)*m+e[i];
            add_edge(4*x-2,T,1);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(str[i][j]=='1') continue;
                int x=i*m+j;
                add_edge(4*x-2,4*(x+m)-3,1);
                add_edge(4*x-2,4*(x-m)-3,1);
                if(j!=1) add_edge(4*x,4*(x-1)-1,1);
                if(j!=m) add_edge(4*x,4*(x+1)-1,1);
            }
        if(max_flow(S,T)==a) puts("Yes"); else puts("No");
    }
    return 0;
}
