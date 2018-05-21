#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
ll a[MAXN];
ll n,ans;
map<ll,ll> mp;
ll L[MAXN],R[MAXN];
int main()
{
    scanf("%I64d",&n);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(ll i=0;i<n;i++)
    {
        if(mp.find(a[i])==mp.end()) mp[a[i]]=1; else mp[a[i]]++;
        ll cnt=0;
        if(mp.find(a[i]-1)!=mp.end()) cnt+=mp[a[i]-1];
        if(mp.find(a[i])!=mp.end()) cnt+=mp[a[i]]-1;
        if(mp.find(a[i]+1)!=mp.end()) cnt+=mp[a[i]+1];
        L[i]=i-cnt;
    }
    for(ll i=0;i<n;i++)
    {
        ll cnt=0;
        if(mp.find(a[i]-1)!=mp.end()) cnt+=mp[a[i]-1];
        if(mp.find(a[i])!=mp.end()) cnt+=mp[a[i]]-1;
        if(mp.find(a[i]+1)!=mp.end()) cnt+=mp[a[i]+1];
        R[i]=n-1-cnt-L[i];
    }
    ans=0;
    for(ll i=0;i<n;i++)
        ans+=a[i]*(L[i]-R[i]);
    printf("%I64d\n",ans);
    return 0;
}
