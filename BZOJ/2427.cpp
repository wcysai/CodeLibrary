#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 505
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M,W[MAXN],V[MAXN],ww[MAXN],vv[MAXN],D[MAXN];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> GG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN],deg[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=N;v++) if(!used[v]) dfs(v);
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=(int)vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
int dp[MAXN][MAXM];
void dfs2(int v)
{
    for(int i=0;i<(int)GG[v].size();i++)
    {
        int to=GG[v][i];
        for(int j=0;j<=M;j++) dp[to][j]=dp[v][j];
        dfs2(to);
        for(int j=ww[to];j<=M;j++) dp[v][j]=max(dp[v][j],dp[to][j-ww[to]]+vv[to]);
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&W[i]);
    for(int i=1;i<=N;i++) scanf("%d",&V[i]);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&D[i]);
        if(D[i]!=0) add_edge(D[i],i);
    }
    int p=scc();
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++)
    {
        ww[cmp[i]+1]+=W[i]; vv[cmp[i]+1]+=V[i];
        if(D[i]!=0&&cmp[D[i]]!=cmp[i]) {GG[cmp[D[i]]+1].push_back(cmp[i]+1),deg[cmp[i]+1]++;} 
    }
    for(int i=1;i<=p;i++) if(deg[i]==0) GG[0].push_back(i); 
    dfs2(0);
    printf("%d\n",dp[0][M]);
    return 0;
}
