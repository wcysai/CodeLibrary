#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans[MAXN];
vector<int> G[MAXN];
int sz[MAXN],pr[MAXN],f[MAXN];
P tmp[MAXN];
P dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs(int v,int p)
{
    sz[v]=1;
    dp[v][1]=P(pr[v],f[v]);
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
    for(auto to:G[v])
    {
        if(to==p) continue;
        for(int i=0;i<=sz[v]+sz[to];i++) tmp[i]=P(0,0);
        for(int i=1;i<=sz[v];i++)
            for(int j=0;j<=sz[to];j++)
            {
                add(tmp[i+j].F,1LL*dp[v][i].F*dp[to][j].F%MOD);
                add(tmp[i+j].S,1LL*dp[v][i].F*dp[to][j].S%MOD);
                add(tmp[i+j].S,1LL*dp[v][i].S*dp[to][j].F%MOD);
            }
        for(int i=0;i<=sz[v]+sz[to];i++) dp[v][i]=tmp[i];
        sz[v]+=sz[to];
    }
    dp[v][0]=P(MOD+1-pr[v],0);
    for(int i=1;i<=sz[v];i++) add(ans[i],1LL*dp[v][i].S*(p==0?1:(MOD+1-pr[p]))%MOD);
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
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        f[i]=a; add(s,a);
        pr[i]=1LL*b*pow_mod(c,MOD-2)%MOD;
    }
    for(int i=1;i<=n;i++) f[i]=1LL*f[i]*pow_mod(s,MOD-2)%MOD;
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}