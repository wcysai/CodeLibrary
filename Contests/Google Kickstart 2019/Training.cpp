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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll T,N,P,s[MAXN];
int main()
{
    scanf("%lld",&T);
    for(ll t=1;t<=T;t++)
    {
        scanf("%lld%lld",&N,&P);
        for(ll i=1;i<=N;i++) scanf("%lld",&s[i]);
        sort(s+1,s+N+1);
        ll sum=0;
        for(ll i=1;i<=P;i++) sum+=s[i];
        ll ans=P*s[P]-sum;
        for(ll i=P+1;i<=N;i++) 
        {
            sum+=s[i];
            sum-=s[i-P];
            ans=min(ans,s[i]*P-sum);
        }
        printf("Case #%lld: %lld\n",t,ans);
    }
    return 0;
}

