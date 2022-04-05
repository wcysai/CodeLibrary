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
int T,N,A[MAXN],K,X;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        ll ans=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&A[i]);
            ans+=A[i];
        }
        scanf("%d%d",&K,&X);
        for(int i=1;i<=N;i++) A[i]=(A[i]^X)-A[i];
        sort(A+1,A+N+1,greater<int>());
        K=(N==K?K:(K&1?1:2));
        for(int i=1;i+K-1<=N;i+=K)
        {
            ll sum=0;
            for(int j=i;j<=i+K-1;j++) sum+=A[j];
            if(sum>0) ans+=sum; else break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

