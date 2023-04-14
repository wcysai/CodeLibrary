#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int sz[MAXN],fa[MAXN];
ll sum[MAXN];
set<P> son[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p){
    sz[v]=1; sum[v]=a[v]; fa[v]=p;
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        son[v].insert(P(-sz[to],to));
        sz[v]+=sz[to]; sum[v]+=sum[to];
    }
}
void solve(int v){
    P p=*son[v].begin();
    assert(fa[v]);
    son[fa[v]].erase(son[fa[v]].find(P(-sz[v],v)));
    int s=p.S; son[v].erase(son[v].begin());
    sum[v]-=sum[s]; sz[v]-=sz[s];
    sum[s]+=sum[v]; sz[s]+=sz[v];
    fa[s]=fa[v]; fa[v]=s;
    son[s].insert(P(-sz[v],v));
    son[fa[s]].insert(P(-sz[s],s));
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<m;i++){
        int t,x;
        scanf("%d%d",&t,&x);
        if(t==1) printf("%lld\n",sum[x]);
        else{
            if(sz[x]>1) solve(x);
        }
    }
    return 0;
}

