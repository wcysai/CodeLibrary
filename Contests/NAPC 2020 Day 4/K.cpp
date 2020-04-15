#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k;
char mp[MAXN][MAXN],tmp[MAXN][MAXN];
int dp[14][(1<<12)][75],ndp[14][(1<<12)][75];
int mask[150];
int fact[305],invf[305];
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
    for(int i=1;i<=300;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300]=pow_mod(fact[300],MOD-2);
    for(int i=299;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        memset(mask,0,sizeof(mask));
        memset(mp,0,sizeof(mp));
        scanf("%d%d%d",&n,&m,&k);
        int cnt=n*m;
        for(int i=0;i<n;i++) scanf("%s",mp[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mp[i][j]=='X') cnt--;
        if(n>m)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    tmp[j][i]=mp[i][j];
            swap(n,m);
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    mp[i][j]=tmp[i][j];
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mp[j][i]=='X') mask[i]|=(1<<j);
        memset(dp,0,sizeof(dp));
        dp[0][mask[0]][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int mask=0;mask<(1<<n);mask++)
                {
                    for(int num=0;num<=k;num++)
                    {
                        if(!dp[j][mask][num]) continue;
                        int nmask=mask&(~((1<<j)));
                        if(mp[j][i+1]=='X') nmask|=(1<<j);
                        add(dp[j+1][nmask][num],dp[j][mask][num]);
                        if(!(mask&(1<<j)))
                        {
                            if(mp[j][i+1]!='X'&&num<k) add(dp[j+1][nmask|(1<<j)][num+1],dp[j][mask][num]);
                            if(j!=n-1&&(!(mask&(1<<(j+1))))&&num<k) add(dp[j+1][nmask|(1<<(j+1))][num+1],dp[j][mask][num]);
                        }
                    }
                }
            }
            memset(ndp,0,sizeof(ndp));
            for(int mask=0;mask<(1<<n);mask++)
                for(int num=0;num<=k;num++)
                    ndp[0][mask][num]=dp[n][mask][num];
            swap(dp,ndp);
        }
        int ans=0;
        for(int num=0;num<=k;num++)
        {
            int res=dp[0][0][num];
            res=1LL*res*comb(k,num)%MOD*fact[num]%MOD*pow_mod(2,num)%MOD*fact[2*(k-num)]%MOD*comb(cnt-2*num,2*(k-num))%MOD;
            if(num%2==0) add(ans,res); else dec(ans,res); 
        }
        printf("%d\n",ans);
    }
    return 0;
}