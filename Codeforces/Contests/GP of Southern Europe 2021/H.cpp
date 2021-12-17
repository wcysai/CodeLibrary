#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
	#define debug(...) 42
#endif
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN],ans;
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN][2*MAXN],ndp[2*MAXN],cnt[MAXN],sz[MAXN],cur;
void dfssz(int v,int p)
{
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfssz(to,v); sz[v]+=sz[to];
    }
}
void dfs(int v,int p)
{
    for(int i=0;i<=2*cnt[cur];i++) dp[v][i]=0;
    int s=1;
    if(c[v]==cur) dp[v][cnt[cur]+1]=1; else dp[v][cnt[cur]-1]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        for(int i=max(-cnt[cur]+1,-(s+sz[to]));i<=min(cnt[cur],s+sz[to]);i++) ndp[i+cnt[cur]]=0;
        for(int i=max(-cnt[cur]+1,-s);i<=min(cnt[cur],s);i++)
            for(int j=max(-cnt[cur]+1,-sz[to]);j<=min(cnt[cur],sz[to]);j++)
                if(i+j>-cnt[cur]&&i+j<=cnt[cur]) add(ndp[i+j+cnt[cur]],1LL*dp[v][i+cnt[cur]]*dp[to][j+cnt[cur]]%MOD);
        for(int i=max(-cnt[cur]+1,-(s+sz[to]));i<=min(cnt[cur],s+sz[to]);i++) dp[v][i+cnt[cur]]=ndp[i+cnt[cur]];
        s+=sz[to];
    }
    //for(int i=-cnt[cur];i<=cnt[cur];i++) debug(cur,v,i,dp[v][i+cnt[cur]]);
    add(dp[v][cnt[cur]],1);
    for(int i=1;i<=min(sz[v],cnt[cur]);i++) add(ans,dp[v][i+cnt[cur]]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&c[i]); cnt[c[i]]++;}
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfssz(1,0);
    for(cur=1;cur<=n;cur++) if(cnt[cur]) dfs(1,0);
    printf("%d\n",ans);
    return 0;
}