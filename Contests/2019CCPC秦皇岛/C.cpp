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
int sum[MAXN][MAXN],dp[MAXN][MAXN];
void compute_dp(int n,vec &a,mat &last,vec &cnt)
{
    memset(sum,0,sizeof(sum));
    memset(dp,0,sizeof(dp));
    dp[0][0]=1; sum[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(last[i-1][a[i]]==0) dp[i][j]=sum[i-1][j-1];
            else
            {
                dp[i][j]=sum[i-1][j-1];
                dec(dp[i][j],sum[last[i-1][a[i]]-1][j-1]);
            }
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
    cnta.resize(n+1); cntb.resize(m+1);
    compute_dp(n,a,lasta,cnta); compute_dp(m,b,lastb,cntb);
    for(int i=1;i<=n;i++) printf("%d ",cnta[i]);
    puts("");
    for(int i=1;i<=m;i++) printf("%d ",cntb[i]);
    puts("");
    return 0;
}
