#include<bits/stdc++.h>
#define MAXN 5005
#define MAXM 105
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m;
vec a,b,cnta,cntb;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
mat lasta,lastb;
int nxta[MAXN][MAXM],nxtb[MAXN][MAXM];
int sum[MAXN][MAXN],dp[MAXN][MAXN];
int sum2[MAXN][MAXN],dp2[MAXN][MAXN];
void compute_dp(int n,vec &a,mat &last,vec &cnt)
{
    memset(sum,0,sizeof(sum));
    memset(dp,0,sizeof(dp));
    dp[0][0]=1; sum[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=sum[i-1][j-1];
            if(last[i-1][a[i]]!=0) dec(dp[i][j],sum[last[i-1][a[i]]-1][j-1]);
        }
        for(int j=0;j<=i;j++)
        {
            sum[i][j]=sum[i-1][j];
            add(sum[i][j],dp[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            add(cnt[j],dp[i][j]);
}
int main()
{
    scanf("%d%d",&n,&m);
    a.resize(n+1); b.resize(m+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    //reverse(++a.begin(),a.end());
    lasta.resize(n+1,vec(101)); lastb.resize(m+1,vec(101));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=100;j++) lasta[i][j]=lasta[i-1][j];
        lasta[i][a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=100;j++) lastb[i][j]=lastb[i-1][j];
        lastb[i][b[i]]=i;
    }
    for(int i=1;i<=100;i++)
    {
        nxta[n+1][i]=n+1;
        nxtb[m+1][i]=m+1;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=100;j++) nxta[i][j]=nxta[i+1][j];
        nxta[i][a[i]]=i;
    }
    for(int i=m;i>=1;i--)
    {
        for(int j=1;j<=100;j++) nxtb[i][j]=nxtb[i+1][j];
        nxtb[i][b[i]]=i;
    }
    cnta.resize(n+1); cntb.resize(m+1);
    compute_dp(n,a,lasta,cnta); compute_dp(m,b,lastb,cntb);
    int ans=0;
    for(int i=2;i<=n;i++)
        for(int j=1;j<min(i,m+1);j++)
            add(ans,1LL*cnta[i]*cntb[j]%MOD);
    memset(dp,0,sizeof(dp)); memset(sum,0,sizeof(sum));
    dp[0][0]=1;
    for(int i=0;i<=n;i++) sum[i][0]=1;
    for(int i=1;i<=m;i++) sum[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]!=b[j]) dp[i][j]=0;
            else
            {
                int x=lasta[i-1][a[i]],y=lastb[j-1][b[j]];
                dp[i][j]=sum[i-1][j-1];
                if(y) dec(dp[i][j],sum[i-1][y-1]);
                if(x) dec(dp[i][j],sum[x-1][j-1]);
                if(x&&y) add(dp[i][j],sum[x-1][y-1]);
            }
            sum[i][j]=sum[i-1][j]; add(sum[i][j],sum[i][j-1]); dec(sum[i][j],sum[i-1][j-1]); add(sum[i][j],dp[i][j]);
        }
    memset(dp2,0,sizeof(dp2)); memset(sum2,0,sizeof(sum2));
    dp2[n+1][m+1]=1;
    for(int i=1;i<=n+1;i++) sum2[i][m+1]=1;
    for(int i=1;i<=m;i++) sum2[n+1][i]=1;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            int x=nxta[i+1][a[i]],y=nxtb[j+1][b[j]];
            dp2[i][j]=sum2[i+1][j+1];
            dec(dp2[i][j],sum2[i+1][y+1]);
            dec(dp2[i][j],sum2[x+1][j+1]);
            add(dp2[i][j],sum2[x+1][y+1]);
            sum2[i][j]=sum2[i+1][j]; add(sum2[i][j],sum2[i][j+1]); dec(sum2[i][j],sum2[i+1][j+1]); add(sum2[i][j],dp2[i][j]);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]>b[j])
            {
                int x=lasta[i-1][a[i]],y=lastb[j-1][b[j]];
                int res1=sum[i-1][j-1];
                if(y) dec(res1,sum[i-1][y-1]);
                if(x) dec(res1,sum[x-1][j-1]);
                if(x&&y) add(res1,sum[x-1][y-1]);
                add(ans,1LL*res1*sum2[i+1][j+1]%MOD);
            }
    printf("%d\n",ans);
    return 0;
}
