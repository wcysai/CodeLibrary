#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n;
vector<int> G[MAXN];
int dep[MAXN];
int ans;
void dfs(int v,int p,int d)
{
    ans=max(ans,d);
    dep[v]=d;
    for(auto to:G[v]) 
    {
        if(to==p) continue;
        dfs(to,v,d+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,0);
    int root=1;
    for(int i=1;i<=n;i++) if(dep[i]>dep[root]) root=i;
    dfs(root,0,0);
    if(ans%3==1) puts("Second"); else puts("First");
}
