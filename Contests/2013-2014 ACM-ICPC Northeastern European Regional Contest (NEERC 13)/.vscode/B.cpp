#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double dp[MAXN][MAXN];
int n,a,b;
int main()
{
    //freopen("bonus.in","r",stdin);
    freopen("bonus.out","w",stdout);
    scanf("%d%d%d",&n,&a,&b);
    a++;
    memset(dp,0,sizeof(dp));
    for(int i=min(n,a);i>=0;i--)
        for(int j=min(b,n-i);j>=0;j--)
        {
            if(i+j==n) continue;
            int xx=a-i,yy=b-j;
            double ret=(double)2.0/(double)(2LL*xx+yy);
            if(xx>1) ret+=(double)(2*xx-2)/(double)(2LL*xx+yy)*dp[i+1][j];
            if(yy) ret+=(double)(yy)/(double)(2LL*xx+yy)*dp[i][j+1];
            dp[i][j]=ret;
        }
    printf("%.16Lf\n",dp[0][0]);
    a--; b++;
    memset(dp,0,sizeof(dp));
    for(int i=min(n,a);i>=0;i--)
        for(int j=min(b,n-i);j>=0;j--)
        {
            if(i+j==n) continue;
            int xx=a-i,yy=b-j;
            double ret=1.0/(double)(2LL*xx+yy);
            if(yy>1) ret+=(double)(yy-1)/(double)(2LL*xx+yy)*dp[i][j+1];
            if(xx) ret+=(double)(2*xx)/(double)(2LL*xx+yy)*dp[i+1][j];
            dp[i][j]=ret;
        }
    printf("%.16Lf\n",dp[0][0]);
    return 0;
}