#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
using namespace std;
typedef pair<int,int> P;
int n,m,k;
char pz[MAXN][MAXN];
int a,b,c,d;
int dis[MAXN][MAXN];
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%s",pz[i]);
        getchar();
    }
    queue<P> que;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    que.push(P(a-1,b-1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dis[i][j]=INF;
    dis[a-1][b-1]=0;
    while(!que.empty())
    {
        P p=que.front(); que.pop();
        int x=p.first,y=p.second;
        if(x==c-1&&y==d-1)
        {
            printf("%d\n",dis[x][y]);
            return 0;
        }
        for(int dx=1;dx<=k;dx++)
        {
            if(x+dx==n) break;
            if(pz[x+dx][y]=='#'||dis[x+dx][y]!=INF) break;
            dis[x+dx][y]=dis[x][y]+1;
            if(dx==k||(y>0&&pz[x+dx][y-1]=='.')||(y<m-1&&pz[x+dx][y+1]=='.')) que.push(P(x+dx,y));
            if(x+dx==c-1&&y==d-1)
            {
                printf("%d\n",dis[x+dx][y]);
                return 0;
            }
        }
        for(int dx=-1;dx>=-k;dx--)
        {
            if(x+dx<0) break;
            if(pz[x+dx][y]=='#'||dis[x+dx][y]!=INF) break;
            dis[x+dx][y]=dis[x][y]+1;
            if(dx==-k||(y>0&&pz[x+dx][y-1]=='.')||(y<m-1&&pz[x+dx][y+1]=='.')) que.push(P(x+dx,y));
            if(x+dx==c-1&&y==d-1)
            {
                printf("%d\n",dis[x+dx][y]);
                return 0;
            }
        }
        for(int dy=1;dy<=k;dy++)
        {
            if(y+dy==m) break;
            if(pz[x][y+dy]=='#'||dis[x][y+dy]!=INF) break;
            dis[x][y+dy]=dis[x][y]+1;
            if(dy==k||(x>0&&pz[x-1][y+dy]=='.')||(y<n-1&&pz[x+1][y+dy]=='.')) que.push(P(x,y+dy));
            if(x==c-1&&y+dy==d-1)
            {
                printf("%d\n",dis[x][y+dy]);
                return 0;
            }
        }
        for(int dy=-1;dy>=-k;dy--)
        {
            if(y+dy<0) break;
            if(pz[x][y+dy]=='#'||dis[x][y+dy]!=INF) break;
            dis[x][y+dy]=dis[x][y]+1;
            if(dy==-k||(x>0&&pz[x-1][y+dy]=='.')||(y<n-1&&pz[x+1][y+dy]=='.')) que.push(P(x,y+dy));
            if(x==c-1&&y+dy==d-1)
            {
                printf("%d\n",dis[x][y+dy]);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}

