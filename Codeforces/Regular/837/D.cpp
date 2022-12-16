#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char s[MAXN];
vector<int> G[MAXN];
int d[MAXN][MAXN],nxt[MAXN][MAXN];
int dp[MAXN][MAXN];
int solve(int x,int y)
{
    if(x==y) return dp[x][y]=1;
    if(dp[x][y]!=-1) return dp[x][y];
    int res=max(solve(x,nxt[y][x]),solve(nxt[x][y],y));
    if(s[x]==s[y]) 
    {
        if(d[x][y]==1) res=max(res,2);
        else res=max(res,2+solve(nxt[x][y],nxt[y][x]));
    }
    return dp[x][y]=res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) d[i][j]=INF;
            d[i][i]=0;
            queue<int> que; que.push(i);
            while(que.size())
            {
                int v=que.front(); que.pop();
                for(auto to:G[v]) if(d[i][to]==INF) {d[i][to]=d[i][v]+1; nxt[to][i]=v; que.push(to);}
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=-1;
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ans=max(ans,solve(i,j));
        printf("%d\n",ans);
    }
    return 0;
}

