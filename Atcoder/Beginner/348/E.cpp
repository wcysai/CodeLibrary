#include<bits/stdc++.h>
#define MAXN 100005
#define INF 8000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int c[MAXN];
vector<int> G[MAXN];
ll sum[MAXN];
ll f[MAXN],g[MAXN];
void dfs(int v,int p){
    sum[v]=c[v];
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        f[v]+=f[to]; f[v]+=sum[to];
        sum[v]+=sum[to];
    }
}
void dfs2(int v,int p){
    ll s=sum[1]-sum[v]+c[v];
    for(auto to:G[v]){
        if(to==p) continue;
        s+=2*sum[to]+f[to];
    }
    for(auto to:G[v]){
        if(to==p) continue;
        g[to]=g[v]+s-2*sum[to]-f[to];
        dfs2(to,v);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    dfs(1,0);
    g[1]=0;
    dfs2(1,0);
    //for(int i=1;i<=n;i++) printf("%lld %lld\n",f[i],g[i]);
    ll ans=INF;
    for(int i=1;i<=n;i++) ans=min(ans,f[i]+g[i]);
    printf("%lld\n",ans);
    return 0;
}

