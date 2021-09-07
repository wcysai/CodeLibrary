#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int inv(int x)
{
	return pow_mod(x,MOD-2);
}
int fact[MAXN],invf[MAXN];
int n,m;
int ans[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
	scanf("%d%d",&n,&m);
    int last=0;
    for(int k=1;k<=n;k++)
    {
        int rem=n%m;
        int num=n/m;
        //rem with num+1, m-rem with num
        if(rem&&num+1>k) {puts("0"); continue;}
        if(num>k) {puts("0"); continue;}
        ans[k]=1;
        if(rem)
        {
            int x=1LL*fact[k]*invf[k-(num+1)]%MOD;
            ans[k]=pow_mod(x,rem);
        }
        int x=1LL*fact[k]*invf[k-num]%MOD;
        ans[k]=1LL*ans[k]*pow_mod(x,m-rem)%MOD;
        for(int i=k-1;i>=1;i--)
           dec(ans[k],1LL*comb(k,i)*ans[i]%MOD*fact[i]%MOD);
        ans[k]=1LL*ans[k]*invf[k]%MOD;
        printf("%d\n",ans[k]);
    }
	return 0;
}