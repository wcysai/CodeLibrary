#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P p[MAXN];
ll dp[MAXN][MAXN][2][MAXN];
void upd(ll &x,ll y) {x=max(x,y);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].F,&p[i].S);
    n++; p[n]=P(0,0);
    sort(p+1,p+n+1);
    int id=-1;
    for(int i=1;i<=n;i++) if(p[i]==P(0,0)) id=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<=n;l++)
                    dp[i][j][k][l]=-INF;
    for(int i=0;i<=n;i++) dp[id][id][0][i]=dp[id][id][1][i]=0;
    for(int len=1;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            for(int k=0;k<2;k++)
                for(int l=0;l<=n;l++)
                {
                    if(dp[i][j][k][l]==-INF) continue;
                    int pos=(k?p[j].F:p[i].F);
                    //go left and take it
                    if(i>1&&l) upd(dp[i-1][j][0][l-1],dp[i][j][k][l]-1LL*(pos-p[i-1].F)*l+p[i-1].S);
                    //go left but don't take
                    if(i>1) upd(dp[i-1][j][0][l],dp[i][j][k][l]-1LL*(pos-p[i-1].F)*l);
                    //go right and take it
                    if(j<n&&l) upd(dp[i][j+1][1][l-1],dp[i][j][k][l]-1LL*(p[j+1].F-pos)*l+p[j+1].S);
                    //go right but don't take
                    if(j<n) upd(dp[i][j+1][1][l],dp[i][j][k][l]-1LL*(p[j+1].F-pos)*l);
                }
        }
    printf("%lld\n",max(dp[1][n][0][0],dp[1][n][1][0]));
    return 0;
}