#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,m,deg[MAXN],a[MAXN],r[MAXN];
vector<int> G[MAXN];
vector<int> gr[MAXN];
bool cmp(int x,int y)
{
    return deg[x]<deg[y];
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=0;i<m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);G[v].push_back(u);
            deg[v]++;deg[u]++;
        }
        sort(a,a+n+1,cmp);
        for(int i=1;i<=n;i++) r[a[i]]=i;
        for(int i=1;i<=n;i++)
            for(auto to:G[i]) if(r[to]>r[i]) gr[i].push_back(to); 
        ll ans=0;
        for(int i=1;i<=n;i++)
            for(auto u:gr[i])
                for(auto to:gr[u])
                    if(r[to]>r[i]) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
