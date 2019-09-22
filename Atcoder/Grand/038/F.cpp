#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000
using namespace std;
struct edge{int to,cap,rev;};
int n,a[MAXN],b[MAXN];
vector<edge> G[MAXN];
int level[MAXN];
int iter[MAXN];
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
int ida[MAXN],idb[MAXN],tot=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    memset(ida,-1,sizeof(ida));
    memset(idb,-1,sizeof(idb));
    for(int i=0;i<n;i++)
    {
        if(ida[i]==-1)
        {
            tot++;
            int now=i;
            while(ida[now]==-1)
            {
                ida[now]=tot;
                now=a[now];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(idb[i]==-1)
        {
            tot++;
            int now=i;
            while(idb[now]==-1)
            {
                idb[now]=tot;
                now=b[now];
            }
        }
    }
    int ans=n,s=tot+1,t=tot+2;
    for(int i=0;i<n;i++)
    {
        if(a[i]==i&&b[i]==i) ans--;
        else if(a[i]==i) add_edge(idb[i],t,1);
        else if(b[i]==i) add_edge(s,ida[i],1);
        else if(a[i]!=b[i]) add_edge(idb[i],ida[i],1);
        else
        {
            add_edge(idb[i],ida[i],1);
            add_edge(ida[i],idb[i],1);
        }
    }
    printf("%d\n",ans-max_flow(s,t));
    return 0;
}

