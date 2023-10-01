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
int t,n,k,a[MAXN];
vector<int> G[MAXN];
ll f[MAXN],g[MAXN];
int sz[MAXN];
void dfs(int v,int p){
    sz[v]=1; f[v]=0;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
        f[v]+=f[to];
        f[v]+=1LL*sz[to]*(a[v]^a[to]);
    }
}
void dfs2(int v,int p){
    for(auto to:G[v]){
        if(to==p) continue;
        g[to]=g[v]+1LL*(a[v]^a[to])*(n-2*sz[to]);
        dfs2(to,v);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(1,0); 
        g[1]=f[1];
        dfs2(1,0);
        for(int i=1;i<=n;i++) printf("%lld%c",g[i],i==n?'\n':' ');
    }
    return 0;
}

