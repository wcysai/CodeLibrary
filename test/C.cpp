#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev;};
int V;
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
int n,m;
vector<string> mp;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int get_id(int x,int y)
{
    return x*m+y;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        mp.push_back(str);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int id=get_id(i,j);
            if(mp[i][j]=='#') continue;
            for(int k=0;k<4;k++)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0&&ni<n&&nj>=0&&nj<m&&mp[ni][nj]=='.')
                {
                    int nid=get_id(ni,nj);
                    add_edge(n*m+id,nid,1);
                }
            }
        }
    for(int i=0;i<n*m;i++) add_edge(i,n*m+i,1);
    printf("%d\n",max_flow(n*m,n*m-1));
    return 0;
}