#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,x,a[MAXN],cnt[MAXN];
int fact[MAXN],invf[MAXN],inv[MAXN];
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
    for(int i=1;i<=2000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[2000]=pow_mod(fact[2000],MOD-2);
    for(int i=1999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=2000;i++) inv[i]=1LL*invf[i]*fact[i-1]%MOD;
    scanf("%d%d%d%d",&n,&m,&k,&x); x=n+2-x;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=m-1;i>=1;i--) cnt[i]+=cnt[i+1];
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int p=1LL*(m-i+1)*inv[m]%MOD;
        int res=0;
        for(int j=0;j<=k;j++)
        {
            int num;
            if(cnt[i]+j-k>=x) num=cnt[i]+j-k;
            else num=min(x-1,cnt[i]+j);
            add(res,1LL*comb(k,j)*pow_mod(p,j)%MOD*pow_mod(MOD+1-p,k-j)%MOD*num%MOD);
        }
        add(ans,res);
    }
    ans=1LL*ans*pow_mod(m,k)%MOD;
    printf("%d\n",ans);
    return 0;
}

