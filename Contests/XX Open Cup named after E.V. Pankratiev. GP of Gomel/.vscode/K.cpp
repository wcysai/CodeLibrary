#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
const int threshold=21;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int save[MAXN][MAXN];
int dp[2][MAXN][MAXN];
int sum[2][MAXN][MAXN];
int fact[10005],invf[10005];
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
    clock_t startTime,endTime;
    fact[0]=invf[0]=1;
    for(int i=1;i<=10000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[10000]=pow_mod(fact[10000],MOD-2);
    for(int i=9999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int h=2;h<=threshold;h++)
    {
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        dp[0][0][0]=dp[1][0][0]=sum[0][0][0]=sum[1][0][0]=1;
        for(int x=0;x<=2000;x++)
        {
            for(int y=0;y<=2000;y++)
            {
                if(x==0&&y==0) continue;
                int length=min(h-1,x);
                if(x) dp[0][x][y]=sum[1][x-1][y]; if(x>=length+1) dec(dp[0][x][y],sum[1][x-length-1][y]);
                length=min(h-1,y);
                if(y) dp[1][x][y]=sum[0][x][y-1]; if(y>=length+1) dec(dp[1][x][y],sum[0][x][y-length-1]);
                if(x) sum[1][x][y]=sum[1][x-1][y]; add(sum[1][x][y],dp[1][x][y]);
                if(y) sum[0][x][y]=sum[0][x][y-1]; add(sum[0][x][y],dp[0][x][y]);
                if((y+x)/(x+1)+1==h) 
                {
                    save[x][y]=dp[0][x][y];
                    add(save[x][y],dp[1][x][y]);
                }
            }
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        int h=(y+x)/(x+1)+1;
        if(h<=threshold) printf("%d\n",save[x][y]);
        else
        {
            int ans=0;
            for(int i=0;i*h<=y;i++)
            {
                if(i&1) dec(ans,1LL*comb(x+1,i)*comb(y-i*h+x,x)%MOD);
                else add(ans,1LL*comb(x+1,i)*comb(y-i*h+x,x)%MOD);
            }
            printf("%d\n",ans);
        }
    }
}