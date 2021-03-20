#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define x1 dasokda
#define y1 dsodkaso
#define x2 dkaosdsd
#define y2 dkasodsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXN];
int dep[MAXN],sum[MAXN],sz[MAXN];
void dfs(int v,int p,int d)
{
    dep[p]=d;
    if(d&1) sum[v]=1; else sum[v]=0;
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
        sum[v]+=sum[to];
        sz[v]+=sz[to];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    if(m!=n-1) return 0;
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,0);
    if(sum[1]*2!=n)
    {
        puts("-1");
        return 0;
    }
    ll ans=0;
    for(int i=2;i<=n;i++)
        ans+=max(2*sum[i]-sz[i],sz[i]-2*sum[i]);
    printf("%lld\n",ans);
}