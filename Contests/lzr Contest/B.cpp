#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 8005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN],cur[MAXN],ndp[MAXN],inv[MAXN];
int upd[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    inv[1]=1;
    for(int i=2;i<=8000;i++) inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
    dp[0]=1;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(!dp[j]) continue;
            int prob=1LL*dp[j]*inv[a[i]]%MOD;
            add(upd[i+1][j+1],prob);
            add(upd[i+a[i]+1][j+1],MOD-prob);
        }
        for(int j=0;j<=i;j++) add(cur[j],upd[i+1][j]);
        for(int j=0;j<=i;j++) dp[j]=cur[j];
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,1LL*dp[i]*dp[i]%MOD);
    printf("%d\n",ans);
    return 0;
}

