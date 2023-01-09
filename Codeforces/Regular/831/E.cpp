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
int n,k,p[MAXN];
vector<int> G[MAXN];
int f[MAXN],g[MAXN];//f: has a ancestor g: doesn't
void dfs(int v)
{
    f[v]=g[v]=1;
    int sum=0;
    for(auto to:G[v])
    {
        dfs(to);
        f[v]=max(f[v],f[to]+1);
        g[v]=max(g[v],f[to]+1);
        sum+=g[to];
    }
    g[v]=max(g[v],sum);
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);
        G[p[i]].push_back(i);
    }
    int ans=0;
    dfs(1);
    printf("%d\n",g[1]);
    return 0;
}

