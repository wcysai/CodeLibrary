#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
int n;
string str[MAXN];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<P> v;
int tot,wtot,id[MAXN][MAXN];
int lib[MAXN*MAXN];
int cnt[MAXN*MAXN],need[MAXN*MAXN];
vector<P> pos[MAXN*MAXN];
vector<P> delta[MAXN*MAXN];
bool used[4*MAXN*MAXN];
int etot;
void bfs_black(int x,int y)
{
    tot++;
    queue<P> que;
    que.push(P(x,y));
    id[x][y]=tot;
    cnt[tot]=1;
    pos[tot].push_back(P(x,y));
    while(que.size())
    {
        P p=que.front(); que.pop();
        for(int k=0;k<4;k++)
        {
            int nx=p.F+dx[k],ny=p.S+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&str[nx][ny]=='O'&&id[nx][ny]==-1)
            {
                pos[tot].push_back(P(nx,ny));
                id[nx][ny]=tot; cnt[tot]++;
                que.push(P(nx,ny));
            }
        }
    }
}
vector<P> vv,tmp;
bool vis[MAXN][MAXN];
void bfs_white(int x,int y)
{
    wtot++;
    queue<P> que;
    que.push(P(x,y));
    vis[x][y]=true;
    while(que.size())
    {
        P p=que.front(); que.pop();
        vv.push_back(P(p.F,p.S));
        for(int k=0;k<4;k++)
        {
            int nx=p.F+dx[k],ny=p.S+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&str[nx][ny]=='X'&&!vis[nx][ny])
            {
                vis[nx][ny]=true; 
                que.push(P(nx,ny));
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>str[i];
    memset(id,-1,sizeof(id));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(str[i][j]=='O'&&id[i][j]==-1)
                bfs_black(i,j);
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=tot;i++)
    {
        tmp.clear();
        for(auto p:pos[i])
        {
            int x=p.F,y=p.S;
            for(int k=0;k<4;k++) 
                if(x+dx[k]>=0&&x+dx[k]<n&&y+dy[k]>=0&&y+dy[k]<n&&str[x+dx[k]][y+dy[k]]=='.')
                {
                    str[x+dx[k]][y+dy[k]]='X';
                    tmp.push_back(P(x+dx[k],y+dy[k]));
                }
        }
        for(auto p:pos[i])
        {
            int x=p.F,y=p.S;
            for(int k=0;k<4;k++) 
                if(x+dx[k]>=0&&x+dx[k]<n&&y+dy[k]>=0&&y+dy[k]<n&&str[x+dx[k]][y+dy[k]]=='X'&&!vis[x+dx[k]][y+dy[k]])
                {
                    bfs_white(x+dx[k],y+dy[k]);
                    int lib=0;
                    for(auto p:vv)
                    {
                        int xx=p.F,yy=p.S;
                        for(int kk=0;kk<4;kk++)
                        {
                            int nx=xx+dx[kk],ny=yy+dy[kk];
                            if(nx>=0&&nx<n&&ny>=0&&ny<n&&str[nx][ny]=='.') {lib++; break;}
                        }
                        if(lib) break;
                    }
                    if(!lib)
                    {
                        need[i]++;
                        set<int> s;
                        for(auto p:vv)
                        {
                            int xx=p.F,yy=p.S;
                            for(int kk=0;kk<4;kk++)
                            {
                                int nx=xx+dx[kk],ny=yy+dy[kk];
                                if(nx>=0&&nx<n&&ny>=0&&ny<n&&str[nx][ny]=='O'&&id[nx][ny]!=i) s.insert(id[nx][ny]);
                            }
                        }
                        etot++;
                        for(auto b:s) 
                        {
                            delta[b].push_back(P(etot,i));
                        }
                    }
                    vv.clear();
                }
        }
        for(auto p:tmp) 
        {
            vis[p.F][p.S]=false;
            str[p.F][p.S]='.';
        }
    }
    queue<int> que;
    for(int i=1;i<=tot;i++) 
    {
        if(need[i]<=1) que.push(i);
    }
    int ans=0;
    memset(used,false,sizeof(used));
    while(que.size())
    {
        int v=que.front(); que.pop();
        ans+=cnt[v];
        for(auto p:delta[v]) 
        {
            if(used[p.F]) continue;
            need[p.S]--;
            if(need[p.S]==1) que.push(p.S);
            used[p.F]=true;
        }
    }
    printf("%d\n",ans);
    return 0;
}
