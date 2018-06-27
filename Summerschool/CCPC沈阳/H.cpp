#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
using namespace std;
struct edge
{
    int to,cost;
};
vector<edge> G[MAXN];
vector<int> save[MAXN];
int p[MAXN],h[MAXN];
int n,t,query;
bool used[MAXN];
int dp[MAXN][2];
int dfs(int v,int x)
{
    used[v]=true;
    h[v]=x;
    save[x].push_back(v);
    if(G[v].size()==0) return x;
    int ans=0;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i].to])  ans=max(ans,dfs(G[v][i].to,x+1));
    return ans;
}
int main()
{
    scanf("%d",&query);
    while(query--)
    {
        int x,y,z;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&p[i]);
        memset(used,false,sizeof(used));
        for(int i=0;i<n;i++)
            G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            x--;
            y--;
            G[x].push_back((edge){y,z});
            G[y].push_back((edge){x,z});
        }
        int maxh=dfs(0,0);
        memset(dp,0,sizeof(dp));
        for(int i=maxh-1;i>=0;i--)
        {
            for(int j=0;j<save[i].size();j++)
            {
                int x=save[i][j];
                for(int k=0;k<G[x].size();k++)
                {
                    dp[x][0]=max(dp[x][0],dp[G[x][k]][0]+
                }
            }
        }
    }
    return 0;
}
