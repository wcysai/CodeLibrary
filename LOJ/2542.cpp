#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 18
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,Q,rt;
vector<int> G[MAXN];
int a[MAXN],b[MAXN],ans[(1<<MAXN)],dp[(1<<MAXN)],d[MAXN];
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
    int suma=0,sumb=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        add(suma,a[to]); add(sumb,b[to]);
    }
    if(a[v]==0) return;
    suma=(d[v]-suma); if(suma<0) suma+=MOD;
    a[v]=pow_mod(suma,MOD-2);
    b[v]=1LL*(sumb+d[v])*a[v]%MOD;
}
int main()
{
    scanf("%d%d%d",&n,&Q,&rt); rt--;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);u--;v--;
        G[u].push_back(v);G[v].push_back(u);
        d[u]++;d[v]++;
    }
    for(int mask=1;mask<(1<<n);mask++)
    {
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        for(int i=0;i<n;i++) if(mask&(1<<i)) a[i]=b[i]=0;
        dfs(rt,-1);
        dp[mask]=ans[mask]=b[rt];
    }
    ans[0]=0;
    for(int i=0;i<n;i++)
        for(int mask=1;mask<(1<<n);mask++)
            if(mask&(1<<i)) dec(ans[mask],ans[mask^(1<<i)]);
    for(int mask=1;mask<(1<<n);mask++) if(__builtin_popcount(mask)%2==0) ans[mask]=0?0:MOD-ans[mask];
    for(int i=0;i<Q;i++)
    {
        int mask=0,k,x;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&x);
            mask|=(1<<(x-1));
        }
        printf("%d\n",ans[mask]);
    }
    return 0;
}

