#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
int n,c[MAXN];
int nxt[MAXN];
int leftmost[MAXN];
int dp[MAXN];
int solve(int i)
{
    if(i==n+1) return 1;
    if(dp[i]!=-1) return dp[i];
    int &ret=dp[i];
    ret=0;
    if(nxt[i]==n+1||nxt[i]==i+1) ret=solve(i+1);
    else 
    {
        ret=solve(nxt[i])+solve(i+1);
        if(ret>=MOD) ret-=MOD;
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=200000;i++) leftmost[i]=n+1;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=n;i>=1;i--)
    {
        nxt[i]=leftmost[c[i]];
        leftmost[c[i]]=i;
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1));
    return 0;
}

