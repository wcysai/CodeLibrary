#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1000005
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
int n,h,d;
int fact[MAXN],sfact[MAXN],dp[MAXN],sum[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int get_sum(int x,int y)
{
    if(x<=0) return sum[y];
    int ret=sum[y];
    dec(ret,sum[x-1]);
    return ret;
}
int main()
{
    fact[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    for(int i=1;i<=1000000;i++) {sfact[i]=fact[i]; add(sfact[i],sfact[i-1]);}
    dp[0]=1;
    sum[0]=1;
    scanf("%d%d%d",&n,&h,&d);
    for(int i=1;i<=h-1;i++)
    {
        dp[i]=get_sum(i-d,i-1);
        dp[i]=1LL*dp[i]*sfact[n]%MOD;
        sum[i]=sum[i-1]; add(sum[i],dp[i]);
    }
    dp[h]=get_sum(h-d,h-1);
    dp[h]=1LL*dp[h]*fact[n]%MOD;
    printf("%d\n",dp[h]);
    return 0;
}

