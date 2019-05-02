#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,r;
int x[2*MAXN],y[2*MAXN],cost[2*MAXN];
int dist[MAXN][MAXN];
int belong[MAXN][MAXN];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
vector<pair<int,P> > v;
int p[2*MAXN],rk[2*MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        rk[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y) return;
    if(rk[x]<rk[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(rk[x]==rk[y]) rk[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
vector<P> res;
int main()
{
    freopen("police.in","r",stdin);
    freopen("police.out","w",stdout);
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dist[i][j]=INF;
    queue<pair<P,int> > que;
    for(int i=1;i<=r;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&cost[i]);
        belong[x[i]][y[i]]=i;
        dist[x[i]][y[i]]=0;
        que.push(make_pair(P(x[i],y[i]),i));
    }
    while(que.size())
    {
        auto p=que.front(); que.pop();
        int x=p.F.F,y=p.F.S;
        int region=p.S;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||belong[nx][ny]==-1||dist[nx][ny]<=dist[x][y]) continue;
            if(dist[nx][ny]==INF)
            {
                dist[nx][ny]=dist[x][y]+1;
                belong[nx][ny]=region;
                que.push(make_pair(P(nx,ny),region));
            }
            else if(dist[nx][ny]==dist[x][y]+1&&belong[nx][ny]!=belong[x][y])
            {
                belong[nx][ny]=-1;
                que.push(make_pair(P(nx,ny),region));
                continue;
            }
        }
    } 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(belong[i][j]==-1) continue;
            v.push_back(make_pair(cost[belong[i][j]],P(i,j)));
        }
    sort(v.begin(),v.end());
    init(n+m);
    int ans=0;
    for(int i=0;i<(int)v.size();i++)
    {
        int x=v[i].S.F,y=n+v[i].S.S,cost=v[i].F;
        if(same(x,y)) continue;
        ans+=cost; unite(x,y);
        res.push_back(v[i].S);
    }
    if((int)res.size()!=n+m-1) {puts("-1"); return 0;}
    printf("%d %d\n",n+m-1,ans);
    for(auto p:res) printf("%d %d\n",p.F,p.S);
    return 0;
}
