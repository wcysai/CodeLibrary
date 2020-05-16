#include<bits/stdc++.h>
#define MAXL 35
#define MAXN 105
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l;
ll dp[MAXL][MAXN][MAXN];
int pre[MAXL][MAXN][MAXN];//0: make leaf 1: next level
int p[MAXN],save[MAXN];
P f[MAXN];
ll sum[MAXN];
void upd(ll &a,ll b) {a=min(a,b);}
int main()
{
    while(scanf("%d%d",&n,&l)==2)
    {
        if(!n) break;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&f[i].F);
            f[i].S=i;
        }
        if(n==1)
        {
            printf("%d\n%d\n",f[1].F,1);
            continue;
        }
        memset(pre,-1,sizeof(pre));
        memset(p,0,sizeof(p));
        sort(f+1,f+n+1);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+f[i].F;
        for(int i=0;i<=l;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    dp[i][j][k]=INF;
        dp[0][1][0]=0;
        for(int i=0;i<=l;i++)
            for(int j=n;j>=0;j--)
                for(int k=0;k<=n;k++)
                {
                    if(dp[i][j][k]==INF) continue;
                    if(j) 
                    {
                        if(dp[i][j-1][k+1]>dp[i][j][k])
                        {
                            dp[i][j-1][k+1]=dp[i][j][k];
                            pre[i][j-1][k+1]=0;
                        }
                    }
                    if(j*2+k<=n) 
                    {
                        if(dp[i+1][2*j][k]>dp[i][j][k]+sum[n-k])
                        {
                            dp[i+1][2*j][k]=dp[i][j][k]+sum[n-k];
                            pre[i+1][2*j][k]=1;
                        }
                    }
                }
        ll ans=INF;
        int id=-1;
        for(int i=0;i<=l;i++) 
        {
            if(dp[i][0][n]<ans)
            {
                ans=dp[i][0][n];
                id=i;
            }
        }
        printf("%lld\n",ans);
        int x=id,y=0,z=n,cnt=0;
        while(true)
        {
            if(x==0) break;
            assert(pre[x][y][z]!=-1);
            if(pre[x][y][z]==0)
            {
                cnt++;
                y++;
                z--;
            }
            else
            {
                assert(y%2==0);
                p[cnt]++;
                y/=2; x--;
            }
        }
        for(int i=n;i>=1;i--) p[i]+=p[i+1];
        for(int i=1;i<=n;i++) save[f[i].S]=p[i];
        for(int i=1;i<=n;i++) printf("%d ",save[i]);
        puts("");
    }
    return 0;
}