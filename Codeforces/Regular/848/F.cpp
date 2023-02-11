#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,p,a[MAXN];
vector<int> G[MAXN];
int prime[MAXM],val[MAXN];
bool is_prime[MAXM];
vector<int> need[1001];
int dp[MAXN][1001];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void dfs(int v,int p){
    int s=0;
    for(int i=1;i<=1000;i++) dp[v][i]=INF;
    for(int i=1;i*i<=a[v];i++){
        if(a[v]%i) continue;
        dp[v][i]=dp[v][a[v]/i]=0;
    }
    for(auto to:G[v]){
        if(to==p) continue;
        dfs(to,v);
        for(int j=1;j<=1000;j++) dp[v][j]=min(INF,dp[v][j]+dp[to][j]);
    }
   // printf("v=%d\n",v);
    if(v!=1)
    {
        for(int i=1000;i>=2;i--)
            for(auto x:need[i])
                dp[v][i]=min(dp[v][i],dp[v][x]+1);
           // if(i<=24) printf("%d %d %d\n",v,i,dp[v][i]);
    }
}
int main()
{
    for(int i=2;i<=1000;i++)
        for(int j=i-1;j>=1;j--)
            if(((j*j)%i==0)) need[i].push_back(j);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear();
        int g=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        if(k==0) {printf("%d\n",a[1]); continue;}
        dfs(1,0);
        ll ans=a[1];
        for(int i=1000;i>=1;i--) if(dp[1][i]<=k-1)  {ans*=i; break;}
        printf("%lld\n",ans);
    }
    return 0;
}

