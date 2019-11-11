#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define MAXK 505
#define MAXH 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,h[MAXN];
int st[MAXN],t;
int fa[MAXN],ls[MAXN],rs[MAXN],sz[MAXN],root;
int dp[MAXN][MAXK];
int fact[MAXH],invf[MAXH];
int tmp[MAXK];
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
void dfs(int v)
{
    sz[v]=1;
    if(ls[v]) {dfs(ls[v]); sz[v]+=sz[ls[v]];}
    if(rs[v]) {dfs(rs[v]); sz[v]+=sz[rs[v]];}
    for(int i=0;i<=sz[v];i++) tmp[i]=0;
    for(int i=0;i<=sz[ls[v]];i++)
        for(int j=0;j<=sz[rs[v]];j++)
            add(tmp[i+j],1LL*dp[ls[v]][i]*dp[rs[v]][j]%MOD);
    int len=h[v]-h[fa[v]];
    for(int choose=0;choose<=min(sz[v],min(len,k));choose++)
        for(int i=0;i+choose<=k;i++)
        {
            int pos=sz[v]-i;
            add(dp[v][i+choose],1LL*tmp[i]*comb(len,choose)%MOD*comb(pos,choose)%MOD*fact[choose]%MOD);
        }
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    for(int i=1;i<=n;i++)
    {
        while(t&&h[st[t-1]]>h[i]) ls[i]=st[--t];
        if(t) rs[st[t-1]]=i;
        st[t++]=i;
    }
    for(int i=1;i<=n;i++) fa[ls[i]]=fa[rs[i]]=i;
    for(int i=1;i<=n;i++) if(!fa[i]) root=i;
    dp[0][0]=1;
    dfs(root);
    //for(int i=1;i<=n;i++) printf("%d %d %d %d %d %d %d\n",i,fa[i],ls[i],rs[i],dp[i][0],dp[i][1],dp[i][2]);
    printf("%d\n",dp[root][k]);
    return 0;
}

