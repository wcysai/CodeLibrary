#include<bits/stdc++.h>
#define MAXN 405
#define MAXM 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int dp[MAXN][MAXN];
int a[MAXM],b[MAXM];
vector<int> rb[MAXN];
int pow_mod(int a,int i)
{
    if(i==0) return 1;
    int s=1;
    while(i>0)
     {
         if(i&1) s=(1LL*s*a)%MOD;
         a=(1LL*a*a)%MOD;
         i>>=1;
     }
     return s;
}
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int solve(int l,int r)
{
    if((r-l)%2==0) return 0;
    if(l>r) return 1;
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=0;
    for(auto x:rb[l])
    {
        if((x-l)%2==0) continue;
        int a=(x-l+1)/2,b=(r-x)/2;
        add(dp[l][r],1LL*solve(l+1,x-1)%MOD*solve(x+1,r)%MOD*comb(a+b,a)%MOD);
    }
    return dp[l][r];
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=400;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[400]=pow_mod(fact[400],MOD-2);
    for(int i=399;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) 
    {
        scanf("%d%d",&a[i],&b[i]);
        rb[a[i]].push_back(b[i]);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,2*n));
}