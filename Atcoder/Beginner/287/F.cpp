#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
int sz[MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
int tmp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v,int p){
    f[v][0]=g[v][0]=1; sz[v]=1;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        for(int i=0;i<=sz[v]+sz[to];i++) tmp[i]=0;
        for(int i=0;i<sz[v];i++)
            for(int j=0;j<sz[to];j++)
            {
                add(tmp[i+j],1LL*f[v][i]*f[to][j]%MOD);
                add(tmp[i+j],1LL*f[v][i]*g[to][j]%MOD);
            }
        for(int i=0;i<=sz[v]+sz[to];i++) f[v][i]=tmp[i];
        for(int i=0;i<=sz[v]+sz[to];i++) tmp[i]=0;
        for(int i=0;i<sz[v];i++)
            for(int j=0;j<sz[to];j++)
            {
                add(tmp[i+j+1],1LL*g[v][i]*f[to][j]%MOD);
                add(tmp[i+j],1LL*g[v][i]*g[to][j]%MOD);
            }
        for(int i=0;i<=sz[v]+sz[to];i++) g[v][i]=tmp[i];
        sz[v]+=sz[to];
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
    dfs(1,0);
    for(int i=1;i<=n;i++){
        int ans=f[1][i-1]; add(ans,g[1][i]);
        printf("%d\n",ans);
    }
    return 0;
}

