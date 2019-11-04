#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,fact[MAXN],invf[MAXN],p2[MAXN];
int res[MAXN],sum[MAXN];
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
int main()
{
    fact[0]=invf[0]=p2[0]=1;
    for(int i=1;i<=10000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[10000000]=pow_mod(fact[10000000],MOD-2);
    for(int i=9999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=10000000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&n);
    int ans=pow_mod(3,n);
    for(int i=0;i<=n/2;i++) res[i]=1LL*comb(n/2,i)*p2[n/2-i]%MOD;
    sum[n/2]=res[n/2];
    for(int i=n/2-1;i>=0;i--)
    {
        sum[i]=sum[i+1];
        add(sum[i],res[i]);
    }
    for(int i=1;i<=n/2;i++)
    {
        int j=n/2+1-i;
        dec(ans,2LL*res[i]*sum[j]%MOD);
    }
    printf("%d\n",ans);
}
