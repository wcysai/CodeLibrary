#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,K;
int dp[25][MAXN][MAXN],sum[25][MAXN][MAXN];
int fact[2*MAXN],invf[2*MAXN];
//dp[i][j][k]: i steps sum j largest k
//dp[i][j][k]= \sum dp[i-1][j-k][0..k-1]
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
    fact[0]=invf[0]=1;
    for(int i=1;i<=200;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200]=pow_mod(fact[200],MOD-2);
    for(int i=199;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD; 
    scanf("%d%d%d",&T,&N,&K);
    T/=2;
    if(!T)
    {
        printf("%d\n",comb(2*N,K));
        return 0;
    }
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    dp[0][0][0]=1;
    for(int i=0;i<=100;i++) sum[0][0][i]=1;
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=100;j++)
        {
            for(int k=1;k<=j;k++) dp[i][j][k]=sum[i-1][j-k][k-1];
            sum[i][j][0]=dp[i][j][0];
            for(int k=1;k<=100;k++) 
            {
                sum[i][j][k]=sum[i][j][k-1];
                add(sum[i][j][k],dp[i][j][k]);
            }
        }
    }
    int ans=0;
    for(int r=1;r<=20;r++)
    {
        for(int l=r-1;l<=r;l++)
        {
            if(l+r<=K&&r*(r+1)/2+l*(l+1)/2<=T) 
            {
                for(int rsum=r*(r+1)/2;rsum<=T;rsum++)
                {
                    int lsum=T-rsum;
                    for(int rmax=r;rmax<=N;rmax++)
                    {
                        if(!dp[r][rsum][rmax]) continue;
                        for(int lmax=0;lmax<=min(N,lsum);lmax++)
                        {
                            if(!dp[l][lsum][lmax]) continue;
                            int res=1LL*dp[r][rsum][rmax]*dp[l][lsum][lmax]%MOD;
                            add(ans,1LL*res*comb(2*N-lmax-rmax,K-l-r)%MOD);
                        }
                    }
                }
            }
        }
    }
    for(int r=1;r<=20;r++)
    {
        for(int rsum=r*(r+1)/2;rsum<=T;rsum++)
        {
            for(int rmax=r;rmax<=N;rmax++)
            {
                for(int l=0;l<r;l++)
                {
                    int lsum=T-rsum-(r-l-1)*(N+1);
                    if(lsum>=0&&l!=r-1)
                    {
                        int res=1LL*dp[r][rsum][rmax]*sum[l][lsum][N]%MOD;
                        add(ans,1LL*res*comb(N-rmax,K-l-r)%MOD);
                    }
                    lsum-=N+1;
                    if(lsum>=0)
                    {
                        int res=1LL*dp[r][rsum][rmax]*sum[l][lsum][N]%MOD;
                        add(ans,1LL*res*comb(N-rmax,K-l-r)%MOD);
                    }
                }
            }
        }
    }
    for(int l=0;l<=20;l++)
    {
        for(int lsum=l*(l+1)/2;lsum<=T;lsum++)
        {
            for(int lmax=l;lmax<=N;lmax++)
            {
                for(int r=0;r<=l;r++)
                {
                    int rsum=T-lsum-(l-r)*(N+1);
                    if(rsum>=0&&l!=r)
                    {
                        int res=1LL*dp[l][lsum][lmax]*sum[r][rsum][N]%MOD;
                        add(ans,1LL*res*comb(N-lmax,K-l-r)%MOD);
                    }
                    rsum-=N+1;
                    if(rsum>=0)
                    {
                        int res=1LL*dp[l][lsum][lmax]*sum[r][rsum][N]%MOD;
                        add(ans,1LL*res*comb(N-lmax,K-l-r)%MOD);
                    }
                }
            }
        }
    }
    for(int r=0;r<=20;r++)
    {
        for(int rsum=r*(r+1)/2;rsum<=T;rsum++)
        {
            for(int cnt=2;rsum+cnt*(N+1)<=T;cnt++)
            {
                int l=K-r,lsum=T-rsum-cnt*(N+1);
                if(l<r-1) lsum-=(r-l-1)*(N+1);
                if(l>r) lsum-=(l-r)*(N+1);
                if(lsum>=0) add(ans,1LL*sum[lsum][l][N]*dp[rsum][r][N]%MOD);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
