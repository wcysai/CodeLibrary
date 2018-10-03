/*************************************************************************
    > File Name: I.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 01:08:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 55005
#define MAXE 25005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int n,m;
P E[MAXE];
int ans[MAXE];
bool C(int d)
{
    for(int i=1;i<=V;i++) G[i].clear();
    for(int i=1;i<=m;i++)
    {
        add_edge(V-1,i,1);
        add_edge(i,E[i].F+m,1);
        add_edge(i,E[i].S+m,1);
    }
    for(int i=1;i<=n;i++) add_edge(m+i,V,d);
    int cur=max_flow(V-1,V);
    //printf("%d %d\n",d,cur);
    return cur==m;
}
int main()
{
    scanf("%d%d",&n,&m);
    V=n+m+2;
    for(int i=1;i<=m;i++) scanf("%d%d",&E[i].F,&E[i].S);
    int l=-1,r=m;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%d\n",r);
    C(r);
    for(int i=1;i<=m;i++)
    {
        for(auto e:G[i])
        {
            if(e.cap!=0) continue;
            if(e.to<m+1||e.to>m+n) continue;
            if(e.to-m==E[i].F) ans[i]=0; else ans[i]=1;
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}

