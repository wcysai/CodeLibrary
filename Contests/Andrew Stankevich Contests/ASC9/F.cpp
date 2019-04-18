#include<bits/stdc++.h>
#define MAXN 205
#define MAXM 40005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
int d[MAXN][MAXN];
int fa[MAXM];
int dis1[MAXM],dis2[MAXM];
vector<int> G[MAXM];
vector<P> ans;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void add_path(int u,int v,int du,int len,int id)
{
    fill(dis1,dis1+tot+1,INF);
    dis1[u]=0;
    queue<int> que; que.push(u);
    while(que.size())
    {
        int x=que.front(); que.pop();
        for(auto to:G[x])
        {
            if(dis1[to]==INF)
            {
                dis1[to]=dis1[x]+1;
                que.push(to);
            }
        }
    }
    fill(dis2,dis2+tot+1,INF);
    dis2[v]=0;
    que.push(v);
    while(que.size())
    {
        int x=que.front(); que.pop();
        for(auto to:G[x])
        {
            if(dis2[to]==INF)
            {
                dis2[to]=dis2[x]+1;
                que.push(to);
            }
        }
    }
    int dd=dis1[v];
    for(int i=1;i<=tot;i++)
    {
        if(dis1[i]==du&&dis2[i]+du==dd)
        {
            int now=i;
            for(int j=1;j<=len-1;j++)
            {
                add_edge(now,++tot);
                now=tot;
            }
            add_edge(now,id);
        }
    }
}
void solve(int now)
{
    if(now==n-1)
    {
        int len=d[now][n];
        int x=n-1;
        for(int i=1;i<=len-1;i++)
        {
            add_edge(x,++tot);
            x=tot;
        }
        add_edge(x,n);
        return;
    }
    solve(now+1);
    int uu=-1,vv=-1,dd=INF,deri=-1;
    for(int i=now+1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int ds=(d[now][i]+d[now][j]-d[i][j])/2;
            if(ds<dd)
            {
                dd=ds;
                uu=i; vv=j; deri=d[now][i]-dd;
            }
        }
    }
    assert(dd!=0);
    add_path(uu,vv,deri,dd,now);
}
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        ans.push_back(P(v,to));
        dfs(to,v);
    }
}
int main()
{
    freopen("restore.in","r",stdin);
    freopen("restore.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++)
            scanf("%d",&d[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
            {
                if((d[i][j]+d[j][k]+d[i][k])&1)
                {
                    puts("-1");
                    return 0;
                }
                if(d[i][j]+d[i][k]<=d[j][k]||d[i][j]+d[j][k]<=d[i][k]||d[i][k]+d[j][k]<=d[i][j])
                {
                    puts("-1");
                    return 0;
                }
            }
    tot=n;
    solve(1);
    dfs(1,0);
    printf("%d\n",tot);
    for(int i=0;i<(int)ans.size();i++) printf("%d %d\n",ans[i].F,ans[i].S);
    return 0;
}
