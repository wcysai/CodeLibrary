#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define INV 500000004
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int T;
ll N,K;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&N,&K);
        ll ans=K-1;
        if(N>=K) printf("%lld\n",ans%MOD);
        else
        {
            ll res=K-N;
            ll terms=res/(N-1);
            ll last=res-terms*(N-1);
            ans%=MOD;
            ll ret=((res+last)%MOD)*((terms+1)%MOD)%MOD*INV%MOD;
            ans+=ret;
            ans%=MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

