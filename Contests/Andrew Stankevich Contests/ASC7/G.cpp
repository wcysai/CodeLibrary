#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,m;
struct edge{int to;db cap; int rev;};
struct E{int from,to,cap,id;};
vector<edge> G[MAXN];
int level[MAXN],iter[MAXN];
bool vis[MAXN];
set<int> ans;
vector<E> edges;
const db eps=1e-8;
void add_edge(int from,int to,db cap)
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
            if(e.cap>eps&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
db dfs(int v,int t,db f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            db d=dfs(e.to,t,min(f,e.cap));
            if(d>eps)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
db max_flow(int s,int t)
{
    db flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        db f;
        while((f=dfs(s,t,INF))>0) flow+=f;
    }
}
void clear_graph()
{
    for(int i=1;i<=n;i++) G[i].clear();
}
db build_graph(db p,bool negative=false)
{
    clear_graph(); db ret=0.0;
    for(int i=0;i<(int)edges.size();i++)
    {
        E e=edges[i];
        if(e.cap-p<-eps) {ret+=p-e.cap; if(negative) ans.insert(e.id); continue;}
        add_edge(e.from,e.to,(db)e.cap-p);
        add_edge(e.to,e.from,(db)e.cap-p);
    }
    return ret;
}
void dfs2(int v)
{
    vis[v]=true;
    for(auto e:G[v])
    {
        if(e.cap<eps) continue;
        if(vis[e.to]) continue;
        dfs2(e.to);
    }
}
int main()
{
    freopen("network.in","r",stdin);
    freopen("network.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        edges.push_back((E){u,v,c,i});
    }
    db l=0,r=1e7;
    for(int i=0;i<30;i++)
    {
        db mid=(l+r)/2; clear_graph();
        db ret=build_graph(mid);
        db res=max_flow(1,n);
        if(res-ret<eps) r=mid; else l=mid;
    }
    clear_graph();
    build_graph(r,true); db res=max_flow(1,n);
    memset(vis,false,sizeof(vis));
    dfs2(1);
    for(int i=0;i<m;i++)
    {
        E e=edges[i];
        if(vis[e.from]^vis[e.to]) ans.insert(e.id);
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    return 0;
}
