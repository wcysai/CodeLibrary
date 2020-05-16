#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int MOD[3]={998244353,1000000007,1000000009};
mt19937 wcy(time(NULL));
vector<int> G[MAXN];
int n,f[3][MAXN],g[3][MAXN],sz[MAXN];
int rng[3][MAXN];
void add(int &a,int b,int mod) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b,int mod) {a-=b; if(a<0) a+=mod;}
void dfs1(int id,int v,int p)
{
    sz[v]=1; f[id][v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs1(id,to,v);
        sz[v]+=sz[to];
        add(f[id][v],1LL*f[id][to]*rng[id][sz[to]]%MOD[id],MOD[id]);
    }
}
void dfs2(int id,int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        g[id][to]=g[id][v];
        dec(g[id][to],1LL*f[id][to]*rng[id][sz[to]]%MOD[id],MOD[id]);
        g[id][to]=1LL*g[id][to]*rng[id][n-sz[to]]%MOD[id];
        add(g[id][to],f[id][to],MOD[id]);
        dfs2(id,to,v);
    }
}
map<tuple<int,int,int>,int> mp;
int main()
{
    scanf("%d",&n);
    for(int t=0;t<3;t++)
        for(int i=1;i<=n;i++)
            rng[t][i]=wcy()%MOD[t]; 
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int t=0;t<3;t++)
    {
        dfs1(t,1,0);
        g[t][1]=f[t][1];
        //for(int i=1;i<=n;i++) printf("%d %d %d\n",t,i,f[t][i]);
        dfs2(t,1,0);
    }
    for(int i=1;i<=n;i++) mp[make_tuple(g[0][i],g[1][i],g[2][i])]++;
    printf("%d\n",(int)mp.size());
    return 0;
}