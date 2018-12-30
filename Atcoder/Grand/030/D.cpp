#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int n,q,a[MAXN],pos[MAXN];
int dp[MAXN][MAXN];
int cnt[MAXN][MAXN];
P query[MAXN];
int p2[MAXN];
int main()
{
    p2[0]=1;
    for(int i=1;i<=3000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d%d",&n,&q);
    vector<int> v;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<q;i++) scanf("%d%d",&query[i].F,&query[i].S);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
           if(a[i]>a[j]) dp[i][j]=1;
           else if(a[j]>a[i]) dp[j][i]=1;
        }
    
    for(int i=0;i<q;i++)
    {
        int u=query[i].F,v=query[i].S;
        if(u>v) swap(u,v);
        int s=dp[u][v]+dp[v][u];
        if(s>=MOD) s-=MOD;
        dp[u][v]=dp[v][u]=1LL*s*INV%MOD;
        for(int j=1;j<=n;j++)
        {
            if(j==u||j==v) continue;
            int s=dp[u][j]+dp[v][j];
            if(s>=MOD) s-=MOD;
            dp[u][j]=dp[v][j]=1LL*s*INV%MOD;
            s=dp[j][u]+dp[j][v];
            if(s>=MOD) s-=MOD;
            dp[j][u]=dp[j][v]=1LL*s*INV%MOD;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            add(ans,1LL*dp[i][j]*p2[q]%MOD);
    printf("%d\n",ans);
    return 0;
}

