#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN],t[MAXN];
int sz[MAXN],leaves[MAXN];
ll dp[MAXN][MAXN][2],tmp[2][MAXN][2];
vector<int> G[MAXN];
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
    leaves[v]=((G[v].size()==1)&&(v!=1))?1:0; 
    if(leaves[v]==1) {dp[v][1][0]=0; dp[v][0][0]=a[v]; dp[v][0][1]=0; return;} 
    dp[v][0][0]=0;
    tmp[0][0][0]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        for(int i=0;i<=leaves[v]+leaves[to];i++) tmp[1][i][0]=tmp[1][i][1]=INF;
        for(int i=0;i<=leaves[v];i++)
            for(int si=0;si<=1;si++)
                for(int j=0;j<=leaves[to];j++)
                    for(int sj=0;si+sj<=1;sj++)
                        tmp[1][i+j][si+sj]=min(tmp[1][i+j][si+sj],tmp[0][i][si]+dp[to][j][sj]);
        for(int i=0;i<=leaves[v]+leaves[to];i++) 
            for(int j=0;j<=1;j++)
                tmp[0][i][j]=tmp[1][i][j];
        leaves[v]+=leaves[to];
    }
    for(int i=0;i<=leaves[v];i++)
        for(int j=0;j<=1;j++)
            dp[v][i][j]=tmp[0][i][j];
    leaves[v]=0;
    tmp[0][0][0]=0; tmp[0][0][1]=INF;
    for(auto to:G[v])
    {
        if(to==p) continue;
        for(int i=0;i<=leaves[v]+leaves[to];i++) tmp[1][i][0]=tmp[1][i][1]=INF;
        for(int i=0;i<=leaves[v];i++)
            for(int si=0;si<=1;si++)
                for(int j=0;j<=leaves[to];j++)
                    for(int sj=0;sj<=1;sj++)
                        tmp[1][i+j][si]=min(tmp[1][i+j][si],tmp[0][i][si]+dp[to][j][sj]);
        for(int i=0;i<=leaves[v]+leaves[to];i++) 
            for(int j=0;j<=1;j++)
                tmp[0][i][j]=tmp[1][i][j];
        leaves[v]+=leaves[to];
    }
    for(int i=0;i<=leaves[v];i++)
        for(int j=0;j<=1;j++)
            dp[v][i][j]=min(dp[v][i][j],tmp[0][i][j]+a[v]);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&t[i]);
        if(n==1) {puts("0"); continue;}
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j][0]=dp[i][j][1]=INF;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(1,0);
        ll ans=INF;
        for(int i=0;i<=leaves[1]-1;i++) ans=min(ans,t[i]+min(dp[1][i][0],dp[1][i][1]));
        printf("%lld\n",ans);
    }
    return 0;
}
/*
1
8
4 2 5 2 4 2 3 2
5 5 6 7 8 9 10 13
1 2
2 3
1 4
1 5
4 6
3 7
5 8
*/