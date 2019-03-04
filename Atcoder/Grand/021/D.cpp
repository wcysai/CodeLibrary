#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 305
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
int n,k;
char str[MAXN];
int dp[MAXN][MAXN][MAXN];
int solve(int l,int r,int k)
{
    if(l>r) return 0;
    if(l==r) return 1;
    if(dp[l][r][k]!=-1) return dp[l][r][k];
    int &ans=dp[l][r][k];
    ans=0;
    ans=max(ans,solve(l+1,r,k));
    ans=max(ans,solve(l,r-1,k));
    if(str[l]==str[r]) ans=max(ans,2+solve(l+1,r-1,k));
    else if(k) ans=max(ans,2+solve(l+1,r-1,k-1));
    return ans;
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    scanf("%d",&k);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,n,k));
    return 0;
}

