#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1505
#define MAXM 50000
#define INF 1000000
using namespace std;
struct edge{int to,cap,rev;};
int V;
vector<edge> G[MAXN];
int n,m,a,b,c,d;
int x[MAXN],y[MAXN];
int nx[MAXN],ny[MAXN];
bool used[MAXN];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
int dfs(int v,int t,int f)
{
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
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
    memset(used,0,sizeof(used));
    int f=dfs(s,t,INF);
    return f;
}
int main()
{
    scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=m;i++) scanf("%d%d",&nx[i],&ny[i]);
    V=2*n+m+2;
    int s=V-1,t=V;
    for(int i=1;i<=n;i++) add_edge(s,i,c);
    for(int i=1;i<=n;i++) add_edge(i,n+i,d);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if((x[i]-nx[j])*(x[i]-nx[j])+(y[i]-ny[j])*(y[i]-ny[j])<=a*a) add_edge(i,2*n+j,1);
            if((x[i]-nx[j])*(x[i]-nx[j])+(y[i]-ny[j])*(y[i]-ny[j])<=b*b) add_edge(n+i,2*n+j,1);
        }
    for(int i=1;i<=m;i++)
    {
        add_edge(2*n+i,t,1);
        if(max_flow(s,t)!=1) {printf("%d\n",i); return 0;}
    }
    puts("-1");
    return 0;
}
