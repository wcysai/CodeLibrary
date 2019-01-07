#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXK 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN][MAXK],sum[MAXK];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--)
    {
        memset(sum,0,sizeof(sum));
        sum[0]=dp[i+1][0];
        for(int j=1;j<=k;j++) {sum[j]=sum[j-1]; add(sum[j],dp[i+1][j]);}
        for(int j=0;j<=k;j++)
        {
            int l=max(0,j-a[i]),r=j;
            if(l==0) dp[i][j]=sum[r]; else dp[i][j]=(sum[r]-sum[l-1]+MOD)%MOD;
        }
    }
    printf("%d\n",dp[1][k]);
    return 0;
}

