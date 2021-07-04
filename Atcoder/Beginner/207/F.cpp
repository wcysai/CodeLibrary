#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
int f[MAXN][3][MAXN],sz[MAXN];
//0: root not guarded
//1: guarded but not chosen
//2: both guarded and chosen
int tmpf[MAXN][3][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v,int p)
{
    sz[v]=1;
    f[v][0][0]=1; f[v][2][1]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        for(int i=0;i<=sz[v]+sz[to];i++) tmpf[v][0][i]=tmpf[v][1][i]=tmpf[v][2][i]=0;
        for(int i=0;i<=sz[v];i++)
            for(int j=0;j<=sz[to];j++)
            {
                add(tmpf[v][0][i+j],1LL*f[v][0][i]*(f[to][0][j]+f[to][1][j])%MOD);
                add(tmpf[v][1][i+j+1],1LL*f[v][0][i]*f[to][2][j]%MOD);
                add(tmpf[v][1][i+j],1LL*f[v][1][i]*(f[to][0][j]+f[to][1][j])%MOD);
                add(tmpf[v][1][i+j],1LL*f[v][1][i]*f[to][2][j]%MOD);
                add(tmpf[v][2][i+j+1],1LL*f[v][2][i]*f[to][0][j]%MOD);
                add(tmpf[v][2][i+j],1LL*f[v][2][i]*(f[to][1][j]+f[to][2][j])%MOD);
            }
        swap(tmpf[v],f[v]);
        sz[v]+=sz[to];
    }
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
    dfs(1,0);
    for(int i=0;i<=n;i++) 
    {
        int ans=0;
        add(ans,f[1][0][i]); add(ans,f[1][1][i]); add(ans,f[1][2][i]);
        printf("%d\n",ans);
    }
    return 0;
}