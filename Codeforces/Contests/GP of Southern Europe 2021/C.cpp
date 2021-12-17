#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
	#define debug(...) 42
#endif
int n,MOD;
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
int fact[2*MAXN],invf[2*MAXN],ans[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    if(k==1) return n;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
void solve(int now,int sz,int prod,int sum,int ways)
{
    //debug(now,sz,prod,sum,ways);
    if(sz+prod-sum>n) return;
    add(ans[sz+prod-sum],1LL*ways*comb(sz+prod-sum,prod-sum)%MOD);
    for(int nxt=now;1LL*prod*nxt<=2*n;nxt++)
    {
        int nprod=prod*nxt,nsum=sum+nxt,nsz=sz+1;
        do
        {
            solve(nxt+1,nsz,nprod,nsum,1LL*ways*comb(nsz,sz)%MOD);
            if(2*n/nprod<nxt) break;
            nprod=nprod*nxt; nsum=nsum+nxt; nsz++;
        } while (nprod<=2*n);
    }
}
int main()
{
    scanf("%d%d",&n,&MOD);
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    memset(ans,0,sizeof(ans));
    solve(2,0,1,0,1);
    for(int i=2;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}