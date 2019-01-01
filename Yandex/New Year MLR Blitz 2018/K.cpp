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
int n,h,deg[MAXN],st[MAXN],tot;
vector<int> G[MAXN];
void dfs(int v,int p)
{
    st[v]=++tot;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
}
deque<int> ans;
bool cmp(int x,int y)
{
    return st[x]<st[y];
}
int main()
{
    scanf("%d%d",&n,&h);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    if(n==2)
    {
        printf("1\n0 1\n");
        return 0;
    }
    int root=-1;
    for(int i=0;i<n;i++) if(deg[i]==1) ans.push_back(i); else root=i;
    dfs(root,-1);
    sort(ans.begin(),ans.end(),cmp);
    int sz=(int)ans.size();
    printf("%d\n",(sz+1)/2);
    for(int i=sz/2;i<sz;i++) printf("%d %d\n",ans[i-sz/2],ans[i]);
    return 0;
}

