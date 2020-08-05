#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000009
#define SQRT5 616991993
#define INV2 500000005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN],invf[MAXN];
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
int t,k;
ll n,c;
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int p=1LL*(SQRT5+1)*INV2%MOD,q=1LL*(1-SQRT5+MOD)*INV2%MOD;
    int inv=pow_mod(SQRT5,MOD-2);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%d",&n,&c,&k);
        c%=(MOD-1);
        int ans=0;
        for(int i=0;i<=k;i++)
        {
            int tmp=1LL*pow_mod(p,1LL*i*c%(MOD-1))*pow_mod(q,1LL*(k-i)*c%(MOD-1))%MOD,res=0;
            if(tmp==1) res=(n+1)%MOD; else res=1LL*(pow_mod(tmp,n%(MOD-1)+1)-1)*pow_mod(tmp-1,MOD-2)%MOD;
            if((k-i)&1) dec(ans,1LL*res*comb(k,i)%MOD); else add(ans,1LL*res*comb(k,i)%MOD);
        }
        ans=1LL*ans*pow_mod(inv,k)%MOD;
        printf("%d\n", ans);
    }
    return 0;
}