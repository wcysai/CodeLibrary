#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define fixed daskldopsa
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
vector<P> G[MAXN];
bool vis[MAXN];
bool fixed[MAXN];
int cnt,ans;
void dfs(int v){
    vis[v]=true; if((int)G[v].size()&1) cnt++;
    for(auto p:G[v]){
        if(fixed[p.S]||vis[p.F]) continue;
        dfs(p.F);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v); G[u].push_back(P(v,i)); G[v].push_back(P(u,i));
    }
    memset(fixed,false,sizeof(fixed));
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int x;
        scanf("%d",&x); fixed[x]=true;
    }
    for(int i=1;i<=n;i++) vis[i]=false;
    ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            cnt=0; dfs(i);
            if(cnt&1) ans++;
        }
    }
    if(ans>=4) puts("No"); else puts("Yes");
    return 0;
}

