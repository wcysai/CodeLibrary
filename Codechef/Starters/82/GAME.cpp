#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a,b,p[MAXN];
vector<int> G[MAXN];
ll sum[2][MAXN];
int dp[MAXN][MAXN];
void dfs(int v,int fa,int id){
    for(auto to:G[v]){
        if(to==fa) continue;
        sum[id][to]=sum[id][v]+p[to];
        dfs(to,v,id);
    }
}
int solve(int u,int v,int fau,int fav,int turn){
    if(dp[u][v]!=-1) return dp[u][v];
    if((!turn)&&u!=a&&G[u].size()==1) return 0; //Alice at leaf
    if((!turn)&&v!=b&&G[v].size()==1) return 0; //Bob at leaf
    if(!turn){//Alice's turn
        int ret=-INF;
        for(auto to:G[u]){
            if(to==fau) continue;
            ret=max(ret,solve(to,v,u,fav,1));
        }
        return dp[u][v]=ret;
    }
    else{//Bob's turn
        int ret=INF;
        for(auto to:G[v]){
            if(to==fav) continue;
            ret=min(ret,solve(u,to,fau,v,0)+(sum[0][u]>sum[1][to]?1:0));
        }
        return dp[u][v]=ret;
    }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&a,&b);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=-1;
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        sum[0][a]=p[a]; sum[1][b]=p[b];
        for(int i=0;i<n-1;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(a,0,0); dfs(b,0,1);
        if(n==1){
            if(p[a]>p[b]) printf("1\n"); else printf("0\n");
            continue;
        }
        printf("%d\n",(p[a]>p[b]?1:0)+solve(a,b,0,0,0));
    }
    return 0;
}

