#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],k,ans;
vector<int> G[MAXN];
int dep[MAXN],fa[MAXN];
void dfs(int v)
{
    for(auto to:G[v])
    {
        dfs(to);
        dep[v]=max(dep[v],dep[to]+1);
    }
    if(v!=1&&fa[v]!=1&&dep[v]==k-1)
    {
        ans++;
        dep[v]=-1;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ans=0;
    if(a[1]!=1) ans++;
    for(int i=2;i<=n;i++)
    {
        G[a[i]].push_back(i);
        fa[i]=a[i];
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}