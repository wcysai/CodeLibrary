#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN][MAXN];
int color[MAXN];
int d[MAXN][MAXN];
bool dfs(int v,int c)
{
    color[v]=c;
    for(int i=1;i<=n;i++)
    {
        if(str[v][i]!='1') continue;
        if(color[i]==c) return false;
        if(!color[i]&&!dfs(i,-c)) return false;
    }
    return true;
}
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    memset(color,0,sizeof(color));
    bool f=true;
    for(int i=1;i<=n;i++) if(color[i]==0&&!dfs(i,1)) f=false;
    if(!f)
    {
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) d[i][j]=0;
            else d[i][j]=(str[i][j]=='1'?1:INF);
        }
    floyd_warshall();
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(d[i][j]!=INF) ans=max(ans,d[i][j]+1);
    printf("%d\n",ans);
    return 0;
}
