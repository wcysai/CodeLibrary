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
int n,m,a[MAXN],c[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];
bool f=false;
int tot,num[MAXN],col[MAXN];
void dfs(int v,int p,int id){
    num[v]=id; col[v]=1;
    for(auto to:G[v]){
        if(to==p) continue;
        if(!col[to]&&c[to]!=c[v]) dfs(to,v,id);
    }
    col[v]=2;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) if(!col[i]) dfs(i,0,++tot);
    for(int i=1;i<=n;i++){
        for(auto to:G[i]) if(c[i]==c[to]&&num[i]==num[to]) f=true;
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}

