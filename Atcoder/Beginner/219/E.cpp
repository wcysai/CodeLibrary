#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int a[4][4],mask;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool vis[6][6];
int b[4][4];
bool check(int mask)
{
    int x=-1,y=-1;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(mask&(1<<(4*i+j))) {b[i][j]=1; x=i; y=j;}
            else b[i][j]=0;
        }
    memset(vis,false,sizeof(vis));
    queue<P> que;
    que.push(P(x,y));
    vis[x][y]=true;
    while(que.size())
    {
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if(nx>=0&&nx<4&&ny>=0&&ny<4&&!vis[nx][ny]&&b[nx][ny]==1)
            {
                vis[nx][ny]=true;
                que.push(P(nx,ny));
            }
        }
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(b[i][j]&&!vis[i][j]) return false;
    if(mask==((1<<16)-1)) return true;
    memset(vis,false,sizeof(vis));
    x=-1,y=-1;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(!b[i][j]) {x=i; y=j;}
    que.push(P(x,y));
    vis[x+1][y+1]=true;
    while(que.size())
    {
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if(nx>=-1&&nx<5&&ny>=-1&&ny<5&&!vis[nx+1][ny+1]&&(nx==-1||nx==4||ny==-1||ny==4||b[nx][ny]==0))
            {
                vis[nx+1][ny+1]=true;
                que.push(P(nx,ny));
            }
        }
    }
    for(int i=-1;i<5;i++)
        for(int j=-1;j<5;j++)
            if((i==-1||j==-1||i==4||j==4||!b[i][j])&&!vis[i+1][j+1]) return false;
    return true;
}
int main()
{
    mask=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]) mask|=(1<<(4*i+j));
        }
    int ans=0;
    for(int i=0;i<(1<<16);i++)
    {
        if((i&mask)!=mask) continue;
        if(check(i)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}