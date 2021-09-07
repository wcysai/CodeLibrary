#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 998244353
#define INV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,x[MAXN],dp[(1<<10)][2*MAXN];
int fact[2*MAXN],invf[2*MAXN];
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int calc(int x,int y)
{
    if(x>y||x+n<y) return 0;
    return comb(n,y-x);
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=2000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[2000]=pow_mod(fact[2000],MOD-2);
    for(int i=1999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++) 
    {
        scanf("%d",&x[i]); 
        x[i]++;
    }
    dp[0][0]=1;
    for(int i=1;i<=x[k-1]+n;i++)
    {
        for(int mask=0;mask<(1<<k);mask++)
        {
            //last position isn't i
            dp[mask][i]=dp[mask][i-1];
            int num=__builtin_popcount(mask)&1;
            for(int j=0;j<k;j++)
            {
                if(mask&(1<<j))
                {
                    num^=1;
                    if(num&1) dec(dp[mask][i],1LL*calc(x[j],i)*dp[mask^(1<<j)][i-1]%MOD);
                    else add(dp[mask][i],1LL*calc(x[j],i)*dp[mask^(1<<j)][i-1]%MOD);
                }
            }
        }
    }
    //ans=1LL*ans*pow_mod(INV,n*k)%MOD;
    printf("%d\n",1LL*dp[(1<<k)-1][x[k-1]+n]*pow_mod(INV,n*k)%MOD);
    return 0;
}