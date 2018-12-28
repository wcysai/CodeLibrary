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
int n,ans[MAXN],m[MAXN];
vector<int> G[MAXN];
map<int,int> mp[MAXN];
int find(int v,int p,int val)
{
    if(mp[v].find(val)!=mp[v].end()) return mp[v][val];
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(to>=val) continue;
        mp[v][val]+=1+find(to,v,val);
    }
    return mp[v][val];
}
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        ans[to]=ans[v];
        m[to]=max(m[v],v);
        if(to>m[v]) ans[to]+=find(to,v,m[to])+1; 
        else ans[to]+=find(to,v,m[to])-find(to,v,m[v]);
        dfs(to,v);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    ans[1]=0;m[1]=-1;
    dfs(1,0);
    for(int i=2;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}

