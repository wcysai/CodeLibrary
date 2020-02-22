#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[MAXN][MAXN];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int dist[MAXN][MAXN];
char mp[4];
int x,y;
bool hswap,vswap;
void go(char ch)
{
    printf("%c\n",ch);
    fflush(stdout);
    int nx,ny;
    scanf("%d%d",&nx,&ny);
    x=nx; y=ny;
    if(str[x][y]=='F') exit(0);
}
char getpos(char ch)
{
    if(ch=='L') return hswap?'R':'L';
    else if(ch=='R') return hswap?'L':'R';
    else if(ch=='U') return vswap?'D':'U';
    else return vswap?'U':'D'; 
}
int main()
{
    mp[0]='U'; mp[1]='L'; mp[2]='D'; mp[3]='R';
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    x=1; y=1;
    if(str[x][y]=='F') exit(0);
    queue<P> que;
    int curx,cury;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='F') 
            {
                curx=i;
                cury=j;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dist[i][j]=INF;
    dist[curx][cury]=0;
    que.push(P(curx,cury));
    while(que.size())
    {
        P p=que.front(); que.pop();
        for(int k=0;k<4;k++)
        {
            int nx=p.F+dx[k];
            int ny=p.S+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&str[nx][ny]!='*'&&dist[nx][ny]==INF)
            {
                dist[nx][ny]=dist[p.F][p.S]+1;
                que.push(P(nx,ny));
            }
        }
    }
    hswap=false,vswap=false;
    if(m>1&&str[1][2]!='*')
    {
        go('R');
        if(y==1) hswap=true;
        else go('L');
        while(str[x+1][y]=='*') go(getpos('R'));
        go('D');
        if(x==1) vswap=true; else go('U');
        while(y!=1) go(getpos('L')); 
    }
    else if(n>1&&str[2][1]!='*')
    {
        go('D');
        if(x==1) vswap=true;
        else go('U');
        while(str[x][y+1]=='*') go(getpos('D'));
        go('R');
        if(y==1) hswap=true; else go('L');
        while(x!=1) go(getpos('U')); 
    }
    while(str[x][y]!='F')
    {
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&str[nx][ny]!='*'&&dist[nx][ny]==dist[x][y]-1)
            {
                go(getpos(mp[k]));
                break;
            }
        }
    }
    return 0;
}