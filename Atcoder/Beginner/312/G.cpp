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
int n,k,a[MAXN];
vector<int> G[MAXN];
int sz[MAXN];
void dfs(int v,int p){
    sz[v]=1;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    ll ans=1LL*n*(n-1)*(n-2)/6;
    ans+=1LL*n*(n-1)/2;
    for(int i=2;i<=n;i++){
        ans-=1LL*sz[i]*(n-sz[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

