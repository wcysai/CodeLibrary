#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,K,c[MAXN],pos[MAXN],p[MAXN];
ll dp[MAXN][MAXN];
bool consec[MAXN][MAXN];
void upd(ll &x,ll y) {x=min(x,y);}
void check_good(int l1,int r1,int l2,int r2){
    return consec[l1][r1]&&consec[l2][r2]&&pos[r1]<=pos[l2];
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<=K;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) {scanf("%d",&p[i]); pos[p[i]]=i;}
    vector<int> bad;
    for(int i=1;i<=n-1;i++){
        if(pos[i]>=pos[i+1]){
            bad.push_back(i+1);
        }
    }
    int sz=(int)bad.size();
    for(int i=0;i<=K;i++)
        for(int j=0;j<=n;j++)
            for(int k=1;k<=n;k++)
                dp[i][j][k]=INF;
    dp[0][0][0]=0;
    for(int i=0;i<=K;i++)
        for(int j=0;j<=n;j++){
            for(int k=1;k<=n;k++)
            if(dp[i][j][k]==INF) continue;
           // printf("i=%d j=%d dp=%lld\n",i,j,dp[i][j]);
            upd(dp[i+1][j],dp[i][j]);
            for(int choice=1;j+choice<=n;choice++){
                if(!consec[n-j-choice+1][n-j]) continue;
                upd(dp[i+1][j+choice],dp[i][j]+1LL*c[i+1]*choice);
            }
        }
    ll ans=INF;
    for(int i=1;i<=n;i++)
        if(consec[1][i]) ans=min(ans,dp[k][n-i]);
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}

