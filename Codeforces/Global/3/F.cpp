#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
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
int n,k,a[MAXN];
ll mask[MAXN];
int val[MAXN];
mt19937 wcy(time(NULL));
ll gen()
{
    ll s=0;
    for(int i=0;i<62;i++) s=s*2+(wcy()%2);
    return max(s,1LL);
}
int main()
{
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%lld",&val[i],&mask[i]);
        sum+=val[i];
    }
    for(int i=0;;i++)
    {
        ll s=gen(),cursum=0;
        for(int i=1;i<=n;i++) if(__builtin_popcountll(s&mask[i])&1) cursum-=val[i]; else cursum+=val[i];
        if((cursum<0&&sum>0)||(cursum>0&&sum<0))
        {
            printf("%lld\n",s);
            exit(0);
        }
    }
    return 0;
}

