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
ll n,x,y,z,a[MAXN],b[MAXN],c[MAXN];
ll ans,res;
vector<P> v;
multiset<int> ms;
ll res1[MAXN],res2[MAXN];
int main()
{
    scanf("%lld%lld%lld",&x,&y,&z);
    n=x+y+z;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        res+=a[i];
        v.push_back(P(b[i]-a[i],c[i]-a[i]));
    }
    sort(v.begin(),v.end(),greater<P>());
    ll s=0;
    for(ll i=0;i<y;i++) 
    {
        s+=v[i].F;
        ms.insert(v[i].S-v[i].F);
    }
    auto it=ms.end();
    res1[0]=s;
    for(ll i=y;i<y+z;i++)
    {
        s+=v[i].F;
        if(it!=ms.end()&&(v[i].S-v[i].F>=*it))
        {
            s+=v[i].S-v[i].F;
            ms.insert(v[i].S-v[i].F);
        }
        else
        {
            ms.insert(v[i].S-v[i].F);
            it--;s+=*it;
        }
        res1[i-y+1]=s;
    }
    ms.clear();s=0;
    for(ll i=n-1;i>=y+z;i--) ms.insert(v[i].S);
    it=ms.end();
    res2[0]=0;
    for(ll i=y+z-1;i>=y;i--)
    {
        if(it!=ms.end()&&(v[i].S>=*it))
        {
            s+=v[i].S;
            ms.insert(v[i].S);
        }
        else
        {
            ms.insert(v[i].S);
            it--;s+=*it;
        }
        res2[y+z-i]=s;
    }
    for(ll i=0;i<=z;i++) ans=max(ans,res+res1[i]+res2[z-i]);
    printf("%lld\n",ans);
    return 0;
}

