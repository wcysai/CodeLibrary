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
vector<P> G[MAXN];
int ans,tot[MAXN];
void dfs(int v,int p){
    ans=max(ans,tot[v]);
    for(auto e:G[v]){
        int to=e.F,id=e.S;
        if(tot[to]) continue;
        tot[to]=(id>p?tot[v]:tot[v]+1);
        dfs(to,id);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(P(v,i)); G[v].push_back(P(u,i));
        }
        for(int i=1;i<=n;i++) tot[i]=0;
        ans=0; tot[1]=1;
        dfs(1,-1);
        printf("%d\n",ans);
    }
    return 0;
}

