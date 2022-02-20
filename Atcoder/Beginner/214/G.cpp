#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],q[MAXN],r[MAXN];
vector<int> cyc;
bool vis[MAXN];
int dp[MAXN],ndp[MAXN];
int fact[2*MAXN],invf[2*MAXN];
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
    if(n<k||k<0||n<0) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=6000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[6000]=pow_mod(fact[6000],MOD-2);
    for(int i=5999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&q[i]);
    for(int i=1;i<=n;i++) r[p[i]]=q[i];
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            int cnt=0,now=i;
            do
            {
                vis[now]=true;
                now=r[now];
                cnt++;
            } while (now!=i);
            cyc.push_back(cnt);
        }
    }
    dp[0]=1;
    for(auto x:cyc)
    {
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=x&&j+k<=n;k++)
            {
                if(k==0||(k==x&&x==1))
                {
                    add(ndp[j+k],dp[j]);
                }
                else
                {
                    add(ndp[j+k],1LL*dp[j]*comb(2*x-k,k)%MOD);
                    add(ndp[j+k],1LL*dp[j]*comb(2*x-k-1,k-1)%MOD);
                }
            }
        }   
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<=n;i++) if(i&1) dec(ans,1LL*dp[i]*fact[n-i]%MOD); else add(ans,1LL*dp[i]*fact[n-i]%MOD);
    printf("%d\n",ans);
    return 0;
}