#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d[MAXN][MAXN];
int p[MAXN*MAXN];
bool has[MAXN][MAXN];
int ans=0;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void update(int x,int y)
{
    has[x][y]=false;
    queue<P> que;
    que.push(P(x,y));
    while(que.size())
    {
        P p=que.front(); que.pop();
        for(int k=0;k<4;k++)
        {
            int target=d[p.F][p.S]+(has[p.F][p.S]);
            int nx=p.F+dx[k],ny=p.S+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&d[nx][ny]>target)
            {
                d[nx][ny]=target;
                que.push(P(nx,ny));
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            d[i][j]=min(min(i-1,n-i),min(j-1,n-j));
            has[i][j]=true;
        }
    for(int i=1;i<=n*n;i++)
    {
        int x=(p[i]-1)/n+1,y=(p[i]-1)%n+1;
        ans+=d[x][y];
        update(x,y);
    }
    printf("%d\n",ans);
}