#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,c,deg[MAXN];
vector<int> G[MAXN];
int cnt[MAXN];
bool vis[MAXN];
void dfs(int u){
    vis[u]=true; c++;
    for(auto to:G[u]) if(!vis[to]) dfs(to);
}
int main()
{
    scanf("%d%d",&n,&m);
    bool f=true;
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++; deg[v]++;
        G[u].push_back(v); G[v].push_back(u);
        if(u==v) f=false;
    }
    for(int i=1;i<=n;i++) cnt[deg[i]]++;
    if(!f||cnt[1]+cnt[2]!=n||cnt[1]!=2) puts("No");
    else {c=0; dfs(1); if(c==n) puts("Yes"); else puts("No");}
    return 0;
}

