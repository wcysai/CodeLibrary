#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
ll n;
int dp[20][2];
vector<int> v;
int solve(int now,int less)
{
    if(now==(int)v.size()) return 0;
    if(dp[now][less]!=-1) return dp[now][less];
    int limit=less?9:v[now];
    int &ans=dp[now][less];
    ans=0;
    for(int i=0;i<=limit;i++) ans=max(ans,i+solve(now+1,less||(i<v[now])));
    return ans;
}
int main()
{
    scanf("%lld",&n);
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(0,0));
    return 0;
}

