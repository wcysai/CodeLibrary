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
int n,k,a[MAXN],b[MAXN],st[MAXN],ed[MAXN],tot;
vector<int> G[MAXN];
vector<int> leaves;
set<int> H[MAXN];
vector<int> GG[MAXN];
bool vis[MAXN];
set<P> s;
void dfs(int v,int p){
    a[v]^=a[p];
    st[v]=tot;
    if((int)G[v].size()==1&&v!=1){
        leaves.push_back(v);
        tot++;
    }
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
    }
    ed[v]=tot;
    s.insert(P(st[v],ed[v]));
}
bool dfs2(int v,int p){
    vis[v]=true;
    for(auto to:GG[v]){
        if(to==p) continue;
        if(vis[to]) return false;
        dfs2(to,v);
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<tot;i++)
        b[i]=(i==0?0:a[leaves[i-1]])^a[leaves[i]];
    b[tot]=a[leaves[tot-1]];
    //for(int i=1;i<=tot;i++) b[i]=b[i-1]^(a[leaves[i-1]]);
    for(int i=0;i<=tot;i++) printf("%d ",b[i]);
    printf("\n");
    for(auto p:s) printf("%d %d\n",p.F,p.S);
    int ans=(int)s.size();
    for(auto p:s) if(b[p.F]^b[p.S]==0) ans--;
    printf("%d\n",ans);
    return 0;
}

