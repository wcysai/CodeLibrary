#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],dep[MAXN],mx[MAXN],deg[MAXN];
vector<int> G[MAXN];
vector<pair<int,P> > v;
void dfs(int v,int p,int d)
{
    dep[v]=d; mx[v]=max(mx[p],dep[v]+a[v]);
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        deg[v]++; deg[u]++;
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++) v.push_back(make_pair(mx[i],P(dep[i],i)));
    sort(v.begin(),v.end(),greater<>());
    int ans=INT_MIN;
    for(int i=0;i<n;i++) ans=max(ans,i+v[i].F);
    printf("%d\n",ans);
    return 0;
}
