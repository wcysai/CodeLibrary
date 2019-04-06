#include<bits/stdc++.h>
#define MAXN 105
#define MAXS 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,s;
int trans[MAXN][MAXS];
int type[MAXN][MAXS];
int ch[MAXN][MAXS];
vector<int> G[MAXN*MAXS];
bool bad[MAXN*MAXS];
int dis[MAXN*MAXS];
void add_edge(int u,int v)
{
    G[u].push_back(v);
}
void bfs(int st)
{
    fill(dis+1,dis+n*(s+1)+1,INF);
    dis[st]=0;
    queue<int> que; que.push(st);
    while(que.size())
    {
        int v=que.front(); que.pop();
        for(auto to:G[v])
        {
            if(dis[to]==INF)
            {
                dis[to]=dis[v]+1;
                que.push(to);
            }
        }
    }
}
void clear_graph()
{
    memset(bad,false,sizeof(bad));
    for(int i=1;i<=n*(s+1);i++) G[i].clear();
}
void solve_nonempty_input()
{
    clear_graph();
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(type[i][j]==-1) bad[(i-1)*(s+1)+1+j]=true;
            else if(trans[i][j]==n) continue;
            else if(type[i][j]==0) add_edge((i-1)*(s+1)+1+j,(trans[i][j]-1)*(s+1)+1+ch[i][j]);
            else add_edge((i-1)*(s+1)+1+j,(trans[i][j]-1)*(s+1)+1);
        }
    }
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=s-1;j++)
            add_edge((i-1)*(s+1)+1,(i-1)*(s+1)+1+j);
    bfs(1);
    for(int i=1;i<=n*(s+1);i++) if(dis[i]!=INF&&bad[i]) {puts("NO"); exit(0);}
}
void solve_empty_input()
{
    clear_graph();
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(type[i][j]==-1) bad[(i-1)*(s+1)+1+j]=true;
            else if(trans[i][j]==n) continue;
            else if(type[i][j]==0) add_edge((i-1)*(s+1)+1+j,(trans[i][j]-1)*(s+1)+1+ch[i][j]);
            else add_edge((i-1)*(s+1)+1+j,(trans[i][j]-1)*(s+1)+1+s);
        }
    }
    bfs(s+1);
    for(int i=1;i<=n*(s+1);i++) if(dis[i]!=INF&&bad[i]) {puts("NO"); exit(0);}
}
int main()
{
    freopen("left.in","r",stdin);
    freopen("left.out","w",stdout);
    memset(bad,false,sizeof(bad));
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=s;j++)
            scanf("%d%d%d",&trans[i][j],&ch[i][j],&type[i][j]);
    solve_nonempty_input();
    solve_empty_input();
    puts("YES");
    return 0;
}
