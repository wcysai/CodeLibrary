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
int n,val[MAXN],tot;
vector<int> G[MAXN];
int st[MAXN],ed[MAXN];
void dfs(int v,int p)
{
    st[v]=++tot;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);

    }
    ed[v]=tot;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y); G[y].push_back(x);
    }
    dfs(1,0);
    return 0;
}

