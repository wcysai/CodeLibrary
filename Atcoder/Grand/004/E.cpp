#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define x1 dasokda
#define y1 dsodkaso
#define x2 dkaosdsd
#define y2 dkasodsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x,y;
char str[MAXN][MAXN];
int sum[MAXN][MAXN];
short dp[MAXN][MAXN][MAXN][MAXN];
void update(short &x,short y) {x=max(x,y);}
int get_sum(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+(str[i][j]=='o');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]+=sum[i-1][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='E')
            {
                x=i;
                y=j;
            }
        }
    dp[0][0][0][0]=0;
    int ans=0;
    for(int l=0;l<=y-1;l++)
        for(int r=0;r<=m-y;r++)
            for(int u=0;u<=x-1;u++)
                for(int d=0;d<=n-x;d++)
                {
                    ans=max(ans,(int)dp[l][r][u][d]);
                    if(l!=y-1)
                    {
                        if(r>=y-l-1) update(dp[l+1][r][u][d],dp[l][r][u][d]);
                        else
                        {
                            int ub=max(x-u,d+1),db=min(x+d,n-u);
                            update(dp[l+1][r][u][d],dp[l][r][u][d]+get_sum(ub,y-l-1,db,y-l-1));
                        }
                    }
                    if(r!=m-y)
                    {
                        if(l>=m-y-r) update(dp[l][r+1][u][d],dp[l][r][u][d]);
                        else
                        {
                            int ub=max(x-u,d+1),db=min(x+d,n-u);
                            update(dp[l][r+1][u][d],dp[l][r][u][d]+get_sum(ub,y+r+1,db,y+r+1));
                        }
                    }
                    if(u!=x-1)
                    {
                        if(d>=x-u-1) update(dp[l][r][u+1][d],dp[l][r][u][d]);
                        else
                        {
                            int lb=max(y-l,r+1),rb=min(y+r,m-l);
                            update(dp[l][r][u+1][d],dp[l][r][u][d]+get_sum(x-u-1,lb,x-u-1,rb));
                        }
                    }
                    if(d!=n-x)
                    {
                        if(u>=n-x-d) update(dp[l][r][u][d+1],dp[l][r][u][d]);
                        else
                        {
                            int lb=max(y-l,r+1),rb=min(y+r,m-l);
                            update(dp[l][r][u][d+1],dp[l][r][u][d]+get_sum(x+d+1,lb,x+d+1,rb));
                        }
                    }
                }
    printf("%d\n",ans);
    return 0;
}