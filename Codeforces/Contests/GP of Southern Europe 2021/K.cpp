#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,tmp;
vector<int> G[MAXN];
int mini[MAXN],minleaf[MAXN],root;
vector<int> ans;
void dfs(int v,int p)
{
    if(G[v].size()==1&&p) minleaf[v]=v; else minleaf[v]=n+1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        minleaf[v]=min(minleaf[v],minleaf[to]);
    }
}
void solve(int v,int p)
{
    vector<P> tmp;
    for(auto to:G[v])
    {
        if(to==p) continue;
        tmp.push_back(P(minleaf[to],to));
    }
    sort(tmp.begin(),tmp.end());
    if(!tmp.size()||v>tmp.back().F) 
    {
        root=v;
        return;
    }
    solve(tmp.back().S,v);
}
void construct(int v,int p)
{
    vector<P> tmp;
    for(auto to:G[v])
    {
        if(to==p) continue;
        tmp.push_back(P(minleaf[to],to));
    }
    sort(tmp.begin(),tmp.end());
    for(auto p:tmp) construct(p.S,v);
    ans.push_back(v);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n); ans.clear();
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);G[v].push_back(u);
        }
        int mini=n+1;
        for(int i=1;i<=n;i++) if(G[i].size()==1) mini=min(mini,i);
        dfs(mini,0);
        solve(mini,0);
        dfs(root,0); construct(root,0);
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}