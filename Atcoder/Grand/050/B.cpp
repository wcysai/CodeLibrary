#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 505
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
int n,a[MAXN];
int dp[MAXN][MAXN],ans[MAXN];
int solve(int l,int r)
{
    if(l>r) return 0;
    if(dp[l][r]!=-INF) return dp[l][r];
    int ans=-INF;
    for(int i=l+1;i<=r-1;i+=3)
    {
        int res=a[l]+a[i]+a[r];
        ans=max(ans,solve(l+1,i-1)+solve(i+1,r-1)+max(res,0));
    }
    for(int i=l+2;i<=r-3;i+=3) ans=max(ans,solve(l,i)+solve(i+1,r));
    return dp[l][r]=ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int need=n-n%3;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            dp[i][j]=-INF;
    ans[0]=0;
    for(int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1];
        for(int j=3;j<=i;j+=3) ans[i]=max(ans[i],ans[i-j]+solve(i-j+1,i));
    }
    printf("%d\n",ans[n]);
    return 0;
}

