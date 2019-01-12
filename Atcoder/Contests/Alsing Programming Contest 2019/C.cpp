#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll H,W,ans,cnt0,cnt1;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
void dfs(ll x,ll y)
{
    if(str[x][y]=='#') cnt0++; else cnt1++;
    vis[x][y]=true;
    if(x>1&&!vis[x-1][y]&&str[x-1][y]!=str[x][y]) dfs(x-1,y);
    if(x<H&&!vis[x+1][y]&&str[x+1][y]!=str[x][y]) dfs(x+1,y);
    if(y>1&&!vis[x][y-1]&&str[x][y-1]!=str[x][y]) dfs(x,y-1);
    if(y<W&&!vis[x][y+1]&&str[x][y+1]!=str[x][y]) dfs(x,y+1);
}
int main()
{
    scanf("%lld%lld",&H,&W);
    for(ll i=1;i<=H;i++) scanf("%s",str[i]+1);
    memset(vis,false,sizeof(vis));
    ans=0;
    for(ll i=1;i<=H;i++)
    {
        for(ll j=1;j<=W;j++)
        {
            if(vis[i][j]) continue;
            cnt0=cnt1=0;dfs(i,j);
            ans+=cnt1*cnt0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

