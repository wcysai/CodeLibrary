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
int k,q;
ll l,r;
char str[5];
mt19937 wcy(time(NULL));
int ask(ll l,ll r)
{
    printf("%lld %lld\n",l,r); fflush(stdout); q--; 
    scanf("%s",str);
    int ret=(str[0]=='Y'?1:0);
    if(l==r&&ret) exit(0);
    if(q==0) exit(0);
    return ret; 
}
void reduce()
{
    ll mid=(l+r)/2;
    if(ask(l,mid))
    {
        l=max(1LL,l-k);
        r=min(n,mid+k);
    }
    else
    {
        l=max(1LL,mid+1-k);
        r=min(n,r+k);
    }
}
void guess()
{
    ll gap=(r-l+1);
    int dif=wcy()%gap;
    ask(l+dif,l+dif);
    l=max(1LL,l-k); r=min(n,r+k);
}
int main()
{
    scanf("%lld",&n);
    scanf("%d%d",&k,&q);
    l=1,r=n;
    for(;;)
    {
        if(r-l+1>6*k) reduce(); else guess();
    }

    return 0;
}

