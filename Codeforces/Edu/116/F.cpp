#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
vector<int> G[MAXN];
const int b=500;
int ch[MAXN],dp[MAXN][505],sz[MAXN],res[MAXN];
int tmp[405];
int delta=0;
vector<pair<P,int> > save[2];
int ans[MAXN];
void pre_dfs(int v,int p){
    for(auto to:G[v]){
        if(to==p) continue;
        pre_dfs(to,v);
        ch[v]++;
    }
}
void dfs(int v,int p){
    for(int i=0;i<=501;i++) dp[v][i]=ch[v]-i-1;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        for(int i=0;i<=501;i++){
            dp[v][i]+=max(dp[to][i],0);
        }
    }
}
void solve(int val){
    delta=val;
    dfs(1,0);
    //printf("val=%d\n",val);
}
void dfs2(int v,int p){
    sz[v]=1;
    dp[v][1]=ch[v]-1;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs2(to,v);
        for(int j=0;j<=min(401,sz[v]+sz[to]);j++) tmp[j]=0;
        for(int i=1;i<=sz[v];i++){
            for(int j=0;j<=sz[to]&&i+j<=401;j++){
                tmp[i+j]=max(tmp[i+j],dp[v][i]+dp[to][j]);
            }
        }
        sz[v]+=sz[to];
        for(int j=0;j<=min(401,sz[v]);j++) dp[v][j]=tmp[j];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    pre_dfs(1,0);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int v,k; scanf("%d%d",&v,&k);
        if(k<=501) save[0].push_back(make_pair(P(v,i),k)); else save[1].push_back(make_pair(P(v,i),k));
    }
    clock_t st,ed; 
    st=clock();
    dfs(1,0);
    for(auto p:save[0]) 
        ans[p.F.S]=dp[p.F.F][p.S]+p.S+1;
    memset(dp,0,sizeof(dp));
    ed=clock();
   // cout<<(double)(ed-st)/CLOCKS_PER_SEC<<"s"<<endl;
    dfs2(1,0);
    ed=clock();
   // cout<<(double)(ed-st)/CLOCKS_PER_SEC<<"s"<<endl;
    for(auto p:save[1]){
        for(int j=1;j<=401;j++) ans[p.F.S]=max(ans[p.F.S],dp[p.F.F][j]-p.S*(j-1)+1);
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}

