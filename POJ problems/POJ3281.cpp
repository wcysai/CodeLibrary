#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#define MAX_V 405
#define MAX_N 100
#define MAX_F 100
#define MAX_D 100
#define INF 100000000
using namespace std;
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
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
    int flow=0;
    for(;;)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0) return flow;
        flow+=f;
    }
}
int N,F,D;
bool likeF[MAX_N][MAX_F];
bool likeD[MAX_N][MAX_D];
void solve()
{
    int s=2*N+F+D,t=s+1;
    for(int i=0;i<F;i++)
    {
        add_edge(s,N*2+i,1);
    }
    for(int i=0;i<D;i++)
    {
        add_edge(N*2+F+i,t,1);
    }
    for(int i=0;i<N;i++)
    {
        add_edge(i,N+i,1);
        for(int j=0;j<F;j++)
        {
            if(likeF[i][j]) add_edge(N*2+j,i,1);
        }
        for(int j=0;j<D;j++)
        {
            if(likeD[i][j]) add_edge(N+i,N*2+F+j,1);
        }
    }
    printf("%d\n",max_flow(s,t));
}
int main()
{
    scanf("%d%d%d",&N,&F,&D);
    memset(likeF,false,sizeof(likeF));
    memset(likeD,false,sizeof(likeD));
    int x,y,z;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&x,&y);
        for(int j=0;j<x;j++)
        {
            scanf("%d",&z);
            likeF[i][z-1]=true;
    }
    for(int j=0;j<y;j++)
        {
            scanf("%d",&z);
            likeD[i][z-1]=true;
    }
    }
    solve();
    return 0;
}
