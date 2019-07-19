#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y;
int tag[MAXN],sz[MAXN];
int cnt[MAXN];
int fact[MAXN],invf[MAXN];
int dp[MAXLOGN][MAXN],sum[MAXLOGN][MAXN];
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
int dfs(int v,int label)
{
    tag[v]=label;
    sz[v]=1;
    int l=0,r=0,ans=1;
    if(v*2<=n&&!tag[v*2])
    {
        ans=1LL*ans*dfs(v*2,label)%MOD; l=sz[v*2];
        sz[v]+=sz[v*2];
    }
    if(v*2+1<=n&&!tag[v*2+1])
    {
        ans=1LL*ans*dfs(v*2+1,label)%MOD; r=sz[v*2+1];
        sz[v]+=sz[v*2+1];
    }
    ans=1LL*ans*comb(l+r,l)%MOD;
    return ans;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&n,&x,&y);
    int d=32-__builtin_clz(x),tmp=d;
    int ans=1;
    while(x)
    {
        ans=1LL*ans*dfs(x,tmp)%MOD;
        cnt[tmp]=sz[x];
        x>>=1;
        tmp--;
    }
    dp[0][0]=1;
    int s=0;
    for(int i=0;i<=n;i++) sum[0][i]=1;
    for(int i=1;i<=d;i++)
    {
        for(int j=i;j<=s+1;j++) dp[i][j]=1LL*sum[i-1][j-1]*comb(s+1-j+cnt[i]-1,cnt[i]-1)%MOD;
        for(int j=1;j<=n;j++) {sum[i][j]=sum[i][j-1]; add(sum[i][j],dp[i][j]);}
        s+=cnt[i];
    }
    ans=1LL*ans*dp[d][y]%MOD;
    printf("%d\n",ans);
    return 0;
}
