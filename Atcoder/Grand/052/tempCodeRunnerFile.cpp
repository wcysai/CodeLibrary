#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int fact[2*MAXN],invf[2*MAXN];
int dp[MAXN][2*MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int n,p;
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=10000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[10000]=pow_mod(fact[10000],MOD-2);
    for(int i=9999;i>=1;i--) invf[i]=1LL*invf[i]*(i+1)%MOD;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=2*n;j++)
        {
            dp[i][j]=comb(j-1,i-1);
            if(j>=p) add(dp[i][j],dp[i][j-p]);
        }
    int ans=pow_mod(p-1,n);
    int last=1,tmp=1;
    for(int i=1;i<=n;i++)
    {
        last=(tmp-last+MOD)%MOD;
        tmp=1LL*tmp*(p-1)%MOD;
    }
    int bd=last,res=0;
    if(n>=p&&n%p!=0) res++;
    for(int i=1;i<=n;i++)
    {
        int sum=n-i-p;
        if(sum==0) continue;
        for(int j=0;j*(p-2)<=sum;j++)
        {
            int nsum=sum-j*(p-2);
            if(j&1) dec(res,1LL*comb(n,i)*comb(i,j)%MOD*dp[i][nsum]%MOD); else add(res,1LL*comb(n,i)*comb(i,j)%MOD*dp[i][nsum]%MOD);
        }
    }
    res=1LL*res*(p-1)%MOD;
    dec(ans,bd); dec(ans,res);
    printf("%d\n",ans);
    return 0;
}