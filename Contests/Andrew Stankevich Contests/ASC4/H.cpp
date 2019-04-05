#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN*MAXN];
int n,m,x,y,d,dir;
//0: up 1: right 2: down 3: left
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int dis[MAXN*MAXN];
bool gr[MAXN*MAXN][4];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
int get_id(int x,int y)
{
    return (x-1)*m+y;
}
int get_dis(int x,int y)
{
    return dis[get_id(x,y)];
}
void bfs(int s)
{
    fill(dis+1,dis+n*m+1,INF);
    queue<int> que;
    que.push(s); dis[s]=0;
    while(!que.empty())
    {
        int v=que.front();que.pop();
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
bool go(int dir)
{
    int nx=x+dx[dir],ny=y+dy[dir];
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&gr[get_id(x,y)][dir]&&get_dis(nx,ny)==d-1) return true;
    return false;
}
string str;
int main()
{
    freopen("straight.in","r",stdin);
    freopen("straight.out","w",stdout);
    scanf("%d%d",&n,&m);
    memset(gr,false,sizeof(gr));
    getchar();
    for(int i=1;i<=2*n-1;i++)
    {
        getline(cin,str);
        if(i&1)
        {
            for(int j=1;j<2*m-1;j+=2)
            {
                int x=(i+1)/2,y=(j+1)/2;
                if(str[j]=='-') 
                {
                    add_edge(get_id(x,y),get_id(x,y+1));
                    gr[get_id(x,y)][1]=true;
                    gr[get_id(x,y+1)][3]=true;
                }
            }
        }
        else
        {
            for(int j=0;j<2*m-1;j+=2)
            {
                int x=(i+1)/2,y=j/2+1;
                if(str[j]=='|') 
                {
                    add_edge(get_id(x,y),get_id(x+1,y));
                    gr[get_id(x,y)][2]=true;
                    gr[get_id(x+1,y)][0]=true;
                }
            }
        }
    }
    bfs(m);
    x=n;y=1;d=get_dis(x,y);
    if(go(0)) {puts("N"); x--; dir=0;} else {puts("E"); y++; dir=1;}
    d--;
    while(d>0)
    {
        if(go(dir))
        {
            printf("F");
            x+=dx[dir]; y+=dy[dir];
        }
        else if(go((dir+1)%4))
        {
            printf("R");
            dir=(dir+1)%4;
            x+=dx[dir];y+=dy[dir];
        }
        else if(go((dir+3)%4))
        {
            printf("L");
            dir=(dir+3)%4;
            x+=dx[dir];y+=dy[dir];
        }
        else assert(0);
        d--;
    }
    return 0;
}
