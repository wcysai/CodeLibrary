#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000001
#define MOD 1000000007
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
int n,x,y,p,a[MAXN];
int dp[4],ndp[4];
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    p=1LL*x*pow_mod(y,MOD-2)%MOD;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=0;i<30;i++)
        for(int j=i+1;j<30;j++)
        {
            dp[1]=dp[2]=dp[3]=0;
            dp[0]=1;
            for(int k=1;k<=n;k++)
            {
                int x=(((a[k]>>i)&1)<<1)+((a[k]>>j)&1);
                for(int l=0;l<4;l++) ndp[l]=1LL*(1-p+MOD)*dp[l]%MOD;
                for(int l=0;l<4;l++) add(ndp[l^x],1LL*p*dp[l]%MOD);
                swap(dp,ndp);
            }
            add(ans,2LL*dp[3]*((1LL<<(i+j))%MOD)%MOD);
        }
    for(int i=0;i<30;i++)
    {
        dp[0]=1; dp[1]=0;
        for(int k=1;k<=n;k++)
        {
            int x=((a[k]>>i)&1);
            for(int l=0;l<2;l++) ndp[l]=1LL*(1-p+MOD)*dp[l]%MOD;
            for(int l=0;l<2;l++) add(ndp[l^x],1LL*p*dp[l]%MOD);
            swap(dp,ndp);
        }
        add(ans,1LL*dp[1]*((1LL<<(i+i))%MOD)%MOD);
    }
    printf("%d\n",ans);
    return 0;
}