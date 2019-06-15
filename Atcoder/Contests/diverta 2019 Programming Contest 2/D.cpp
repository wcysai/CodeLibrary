#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,dp[MAXN*MAXN];
int w[3][2];
vector<P> v1,v2;
ll solve(ll n,vector<P> &v)
{
    memset(dp,-1,sizeof(dp));
    dp[n]=0;
    for(int i=0;i<(int)v.size();i++)
        for(int j=n;j>=0;j--)
        {            
            if(dp[j]==-1) continue;
            if(j>=v[i].F) dp[j-v[i].F]=max(dp[j-v[i].F],dp[j]+v[i].S);
        }
    ll ans=0;
    for(int i=0;i<=n;i++) ans=max(ans,dp[i]);
    return n+ans;
}
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&w[j][i]);
    for(int i=0;i<3;i++)
    {
        if(w[i][0]<w[i][1]) v1.push_back(P(w[i][0],w[i][1]-w[i][0]));
        else v2.push_back(P(w[i][1],w[i][0]-w[i][1]));
    }
    n=solve(n,v1);
    n=solve(n,v2);
    printf("%lld\n",n);
    return 0;
}

