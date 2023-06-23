#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
ll dp[MAXN][2];
void upd(ll &a,ll b) {a=max(a,b);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<2;j++)
            dp[i][j]=-INF;
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            if(dp[i][j]==-INF) continue;
            upd(dp[i+1][j],dp[i][j]);
            if(!a[i+1]) upd(dp[i+1][0],dp[i][j]+b[i+1]);
            else if(j!=1) upd(dp[i+1][1],dp[i][j]+b[i+1]);
        }
    }
    printf("%lld\n",max(dp[n][0],dp[n][1]));
    return 0;
}

