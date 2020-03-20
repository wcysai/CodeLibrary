#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,ans;
vector<int> G[MAXN];
int color[MAXN],dep[MAXN];
bool f=false;
void dfs(int v,int p,int d)
{
    color[v]=1;
    dep[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!color[to]) dfs(to,v,d+1);
        else if(color[to]==1)
        {
            if((dep[v]-dep[to])&1) ans=5LL*ans%MOD;
            else 
            {
                if(!f) f=true;
                else ans=5LL*ans%MOD;
            }
        } 
    }
    color[v]=2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans=1;
        for(int i=1;i<=n;i++) color[i]=0;
        for(int i=1;i<=n;i++) if(!color[i]) {f=false; dfs(i,0,0);}
        printf("%d\n",ans);
    }
    return 0;
}