#include<bits/stdc++.h>
#define MAXN 10
#define MAXM 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll dp[20][10][(1<<8)][(1<<8)],tot;
void add(ll &a,ll b) {a+=b;}
ll n,m;
int main()
{
    //freopen("solid.in","r",stdin);
    //freopen("solid.out","w",stdout);
    while(scanf("%lld%lld",&n,&m)==2)
    {
        tot++;
        memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            for(ll mask=0;mask<(1<<n);mask++)
            {
                for(ll mask2=0;mask2<(1<<n);mask2++)
                {
                    if(!dp[i][j][mask][mask2]) continue;
                    if((mask>>j)&1)
                    {
                        add(dp[i][j+1][mask^(1<<j)][mask2],dp[i][j][mask][mask2]);
                        continue;
                    }
                    if(j<n-1&&(!(mask&(1<<(j+1))))) add(dp[i][j+2][mask][mask2|(1<<j)],dp[i][j][mask][mask2]);
                    add(dp[i][j+1][mask^(1<<j)][mask2],dp[i][j][mask][mask2]);
                }
            }
        }
        if(i==m-1)
        {
            printf("%lld,",dp[m-1][n][0][(1<<(n-1))-1]);
            break;
        }
        for(ll mask=1;mask<(1<<n);mask++) 
            for(ll mask2=0;mask2<(1<<n);mask2++)
                dp[i+1][0][mask][mask2]=dp[i][n][mask][mask2];
        }
        if(tot%10==0) printf("\n");
    }
    return 0;
}
