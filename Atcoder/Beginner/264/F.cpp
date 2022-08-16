#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,r[MAXN],c[MAXN];
string str[MAXN];
ll dp[MAXN][MAXN][4];
void upd(ll &a,ll b) {a=min(a,b);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&r[i]);
    for(int i=0;i<m;i++) scanf("%d",&c[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int mask=0;mask<4;mask++)
                dp[i][j][mask]=INF;
    for(int i=0;i<n;i++) cin>>str[i];
    dp[0][0][0]=0; dp[0][0][1]=r[0]; dp[0][0][2]=c[0]; dp[0][0][3]=r[0]+c[0];
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++)
        {
            for(int mask=0;mask<4;mask++)
            {
                if(i+1<n) 
                {
                    int same=(str[i][j]==str[i+1][j]?1:0)^(mask&1);
                    if(same)
                    {
                        upd(dp[i+1][j][mask-(mask&1)],dp[i][j][mask]);
                    }
                    else
                    {
                        upd(dp[i+1][j][mask|1],dp[i][j][mask]+r[i+1]);
                    }
                }
                if(j+1<m) 
                {
                    int same=(str[i][j]==str[i][j+1]?1:0)^((mask>>1)&1);
                    if(same)
                    {
                        upd(dp[i][j+1][mask-(mask&2)],dp[i][j][mask]);
                    }
                    else
                    {
                        upd(dp[i][j+1][mask|2],dp[i][j][mask]+c[j+1]);
                    }
                }
            }
        }
    ll ans=INF;
    for(int mask=0;mask<4;mask++) ans=min(ans,dp[n-1][m-1][mask]);
    printf("%lld\n",ans);
    return 0;
}

