#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,d;
int a[MAXN],fact[MAXN],invf[MAXN];
int ans[MAXN];
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
    if(k<0||n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int calc_line(int n,int k)//number of ways to choose k bottles out of n in a line 
{
    return comb(n-k+1,k);
}
int calc_cycle(int n,int k)//number of ways to choose k bottles out of n in a cycle
{
    return (calc_line(n-1,k)+calc_line(n-3,k-1))%MOD;
}
void add_weight(int l,int r,int w)
{
    add(ans[l],w); dec(ans[r+1],w);
}
void solve(int l,int r,int k)//interval [l,r], need to place k bottles
{
    if(l>r) return;
    if(k<=0) return;
    if(l==r&&k==1) {add_weight(l,l,1); return;}
    int n=r-l+1;
    int res=1LL*k*calc_cycle(n,k)%MOD*pow_mod(n,MOD-2)%MOD;
    add_weight(l,r,res);
    int ways=calc_line(n-4,k-2);//number of ways both l,r 
    add_weight(l,l,ways);  add_weight(r,r,ways);
    solve(l+2,r-2,k-2);
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300000]=pow_mod(fact[300000],MOD-2);
    for(int i=299999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(ans,0,sizeof(ans));
    solve(1,n,k);
    int res=0;
    for(int i=1;i<=n;i++) add(ans[i],ans[i-1]);
    for(int i=1;i<=n;i++) add(res,1LL*ans[i]*a[i]%MOD);
    printf("%d\n",res);
    return 0;
}
