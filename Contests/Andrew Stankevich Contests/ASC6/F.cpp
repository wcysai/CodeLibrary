#include<bits/stdc++.h>
#define MAXN 35
#define MAXM 35
#define MAXV 3005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev;};
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
vector<P> ve,ans;
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
    ve.push_back(P(from,to));
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
int h,v,s,n,m;
char str[MAXN][MAXM];
bool vis[MAXV];
void dfs2(int v)
{
    vis[v]=true;
    for(auto e:G[v])
    {
        if(e.cap==0) continue;
        if(!vis[e.to]) dfs2(e.to);
    }
}
int tot;
struct node
{
    int id,l,r;
    bool operator<(const node& x) const
    {
        if(id!=x.id) return id<x.id;
        if(l!=x.l) return l<x.l;
        return r>x.r;
    }
};
map<node,int> row,col;
vector<node> vn;
void add_row_node(int id,int l,int r)
{
    row[(node){id,l,r}]=++tot;;
    vn.push_back((node){id,l,r});
}
void add_col_node(int id,int l,int r)
{
    col[(node){id,l,r}]=++tot;;
    vn.push_back((node){id,l,r});
}
bool intersect(node rown,node coln)
{
    return (rown.id>=coln.l&&rown.id<=coln.r&&coln.id>=rown.l&&coln.id<=rown.r);
}
int main()
{
    freopen("painter.in","r",stdin);
    freopen("painter.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&m,&h,&v,&s);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    vn.push_back((node){0,0,0});
    for(int i=0;i<n;i++)
    {
        int last=-1;
        for(int j=0;j<m;j++)
        {
            if(last==-1) last=j;
            if(str[i][last]!=str[i][j])
            {
                add_row_node(i,last,j-1);
                last=j;
            }
        }
        add_row_node(i,last,m-1);
    }
    for(int i=0;i<m;i++)
    {
        int last=-1;
        for(int j=0;j<n;j++)
        {
            if(last==-1) last=j;
            if(str[last][i]!=str[j][i])
            {
                add_col_node(i,last,j-1);
                last=j;
            }
        }
        add_col_node(i,last,n-1);
    }
    int source=tot+1,sink=tot+2;
    for(auto rown:row) add_edge(source,rown.S,h);
    for(auto coln:col) add_edge(coln.S,sink,v);
    for(auto rown:row)
        for(auto coln:col)
            if(intersect(rown.F,coln.F)) add_edge(rown.S,coln.S,s);
    printf("%d ",max_flow(source,sink));
    memset(vis,false,sizeof(vis));
    dfs2(source);
    for(auto e:ve) if(vis[e.F]&&!vis[e.S]) ans.push_back(e);
    printf("%d\n",(int)ans.size());
    for(auto e:ans)
    {
        if(e.F==source)
        {
            node nn=vn[e.S];
            printf("h %d %d %d %d %c\n",nn.id+1,nn.l+1,nn.id+1,nn.r+1,str[nn.id][nn.l]);
        }
        else if(e.S==sink)
        {
            node nn=vn[e.F];
            printf("v %d %d %d %d %c\n",nn.l+1,nn.id+1,nn.r+1,nn.id+1,str[nn.l][nn.id]);
        }
        else
        {
            node nl=vn[e.F],nr=vn[e.S];
            printf("s %d %d %c\n",nl.id+1,nr.id+1,str[nl.id][nr.id]);
        }
    }
    return 0;
}
