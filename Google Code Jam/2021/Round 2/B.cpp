#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int prime[MAXN],fact[MAXN];
bool is_prime[MAXN];
int dp[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    dp[1]=1; 
    for(int i=2;i<=1000000;i++) 
        for(int j=1;j*j<=i-1;j++)
        {
            if((i-1)%j) continue;
            if(j!=1&&dp[(i-1)/j]!=-1) dp[i]=max(dp[i],dp[(i-1)/j]+1);
            if((i-1)/j!=1&&dp[j]!=-1) dp[i]=max(dp[i],dp[j]+1);
        }
    for(int i=1;i<=1000000;i++)
    {
        if(dp[i]==-1) continue;
        for(int j=3*i;j<=1000000;j+=i)
            ans[j]=max(ans[j],dp[i]);
    }
    for(int _=1;_<=t;_++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",_,ans[n]);
    }
    return 0;
}