#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int fact[MAXN],invf[MAXN],qm;
int cnt[10];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int dp[5][1005][11];
int main()
{
    freopen("can.in","r",stdin);
    freopen("can.out","w",stdout);
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]!='?') cnt[(int)str[i]-'0']++;
        else qm++;
    }
    assert(qm<=1000);
    dp[0][qm][0]=1;
    for(int i=0;i<4;i++)
    {
        //i: i and 9-i
        for(int j=0;j<=qm;j++)
        {
            for(int k=0;k<=10;k++)
            {
                if(!dp[i][j][k]) continue;
                int x=i+1,y=9-x;
                if(cnt[x]>cnt[y]) swap(x,y);
                int need=cnt[y]-cnt[x];
                for(int tmp=0;tmp+need<=j;tmp+=2) add(dp[i+1][j-tmp-need][k],1LL*dp[i][j][k]*comb(j,tmp+need)%MOD*comb(tmp+need,tmp/2)%MOD);
                if(!k)
                {
                     if(x==5) for(int tmp=0;tmp+need+2<=j;tmp+=2) add(dp[i+1][j-tmp-need-2][10],1LL*dp[i][j][k]*comb(j,tmp+need+2)%MOD*comb(tmp+need+2,tmp/2)%MOD);
                     else for(int tmp=0;tmp+need+1<=j;tmp+=2) add(dp[i+1][j-tmp-need-1][x],1LL*dp[i][j][k]*comb(j,tmp+need+1)%MOD*comb(tmp+need+1,tmp/2)%MOD);
                     if(y==5)
                     {
                         for(int dy=0;;dy++)
                         {
                             int dx=cnt[y]+dy-2-cnt[x];
                             if(dx<0) continue;
                             if(dx+dy>j) break;
                             add(dp[i+1][j-dx-dy][10],1LL*dp[i][j][k]*comb(j,dx+dy)%MOD*comb(dx+dy,dx)%MOD);
                         }
                     }
                     else if(y!=0)
                     {
                         for(int dy=0;;dy++)
                         {
                             int dx=cnt[y]+dy-1-cnt[x];
                             if(dx<0) continue;
                             if(dx+dy>j) break;
                             add(dp[i+1][j-dx-dy][y],1LL*dp[i][j][k]*comb(j,dx+dy)%MOD*comb(dx+dy,dx)%MOD);
                         }
                     }
                }
                else if(k+x==10)
                {
                    for(int tmp=0;tmp+need+1<=j;tmp+=2) add(dp[i+1][j-tmp-need-1][10],1LL*dp[i][j][k]*comb(j,tmp+need+1)%MOD*comb(tmp+need+1,tmp/2)%MOD);
                }
                else if(k+y==10)
                {
                    for(int dy=0;;dy++)
                    {
                        int dx=cnt[y]+dy-1-cnt[x];
                        if(dx<0) continue;
                        if(dx+dy>j) break;
                        add(dp[i+1][j-dx-dy][10],1LL*dp[i][j][k]*comb(j,dx+dy)%MOD*comb(dx+dy,dx)%MOD);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=qm;i++)
    {
        if(dp[4][i][10])
        {
            //printf("10! %d %d\n",i,dp[4][i][10]);
            if((i+cnt[0]+cnt[9])&1) continue;
            for(int zeroes=0;zeroes<=i;zeroes++)
            {
                int nines=i-zeroes;
                if(zeroes+cnt[0]<nines+cnt[9]) continue;
                add(ans,1LL*dp[4][i][10]*comb(i,zeroes)%MOD);
            }
        }
        if(dp[4][i][1])
        {
            //printf("1! %d %d\n",i,dp[4][i][1]);
            if((i+cnt[0]+cnt[9]+1)&1) continue;
            for(int zeroes=0;zeroes<=i;zeroes++)
            {
                int nines=i-zeroes;
                if(nines+cnt[9]<1) continue;
                if(zeroes+cnt[0]<nines+cnt[9]-1) continue;
                add(ans,1LL*dp[4][i][1]*comb(i,zeroes)%MOD);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
