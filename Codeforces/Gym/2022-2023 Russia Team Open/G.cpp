#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w,tot;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int dx8[8]={-1,-1,-1,0,0,1,1,1},dy8[8]={-1,0,1,-1,1,-1,0,1};
char str[MAXN][MAXN];
int cmp[MAXN][MAXN];
bool inside[MAXN];
void dfs(int x,int y,int t)
{
    cmp[x][y]=t;
    //printf("x=%d y=%d k=%d\n",x,y,t);
    for(int k=0;k<4;k++)
    {
        int nx=x+dx[k],ny=y+dy[k];
        if(nx<1||nx>h||ny<1||ny>w) inside[t]=false;
        else if(str[nx][ny]!='#'&&!cmp[nx][ny]) dfs(nx,ny,t);
    }
}
bool canremove(int x,int y)
{
    if(str[x][y]!='#') return false;
    int cnt=0;
    for(int k=0;k<4;k++)
    {
        int nx=x+dx[k],ny=y+dy[k];
        if(nx<1||nx>h||ny<1||ny>w) return false;
        else if(str[nx][ny]=='.'&&!inside[cmp[nx][ny]]) return false;
        else if(str[nx][ny]=='.') cnt++;
    }
    for(int k=0;k<8;k++)
    {
        int nx=x+dx8[k],ny=y+dy8[k];
        if(nx<1||nx>h||ny<1||ny>w) return false;
        else if(str[nx][ny]=='.'&&!inside[cmp[nx][ny]]) return false;
    }
    if(cnt<=2) return false;
    return true;
}
int main()
{
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++) scanf("%s",str[i]+1);
    memset(inside,false,sizeof(inside));
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(str[i][j]=='.'&&(!cmp[i][j]))
            {
                inside[++tot]=true;
                dfs(i,j,tot);
            }
    int l=INF,r=-INF,u=INF,d=-INF;
    int id=-1;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(inside[cmp[i][j]])
            {
                id=cmp[i][j];
                l=min(l,j); r=max(r,j); u=min(u,i); d=max(d,i);
            }
        }
    assert(id!=-1);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(str[i][j]=='#'&&(i<u-1||i>d+1||j<l-1||j>r+1)) 
                str[i][j]='.';
    //for(int i=1;i<=h;i++) printf("%s\n",str[i]+1);
    queue<P> que;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(canremove(i,j)) que.push(P(i,j));
    while(que.size())
    {
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        if(str[x][y]!='#') continue;
        str[x][y]='.'; cmp[x][y]=id;
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if(nx>=1&&ny<=h&&canremove(nx,ny)) que.push(P(nx,ny)); 
        }
    }
    for(int i=1;i<=h;i++) printf("%s\n",str[i]+1);
    return 0;
}

