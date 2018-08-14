#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,m,t;
ll a[MAXN];
bool C(ll x)
{
    vector<ll> save;
    save.push_back(-1);
    for(ll i=0;i<n;i++)
        if(a[i]>x) save.push_back(i);
    ll s=0;
    for(ll i=k;i<save.size();i++)
        s+=(save[i-k+1]-save[i-k])*(n-save[i]);
    return s>m-1;
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&k,&m);
        for(ll i=0;i<n;i++)
            scanf("%lld",&a[i]);
        ll left=0,right=1e9+1;
        while(right-left>1)
        {
            ll mid=(left+right)/2;
            if(C(mid)) left=mid; else right=mid;
        }
        printf("%lld\n",right);
    }
}
