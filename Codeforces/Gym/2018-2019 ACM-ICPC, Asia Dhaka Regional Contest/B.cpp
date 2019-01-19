#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T;
ll x,y;
ll p[19];
ll solve(ll x)
{
    if(x<10) return 0;
    vector<ll> v; v.clear();
    ll dummy=x;
    while(dummy) {v.push_back(dummy%10); dummy/=10;}
    reverse(v.begin(),v.end());
    ll sz=(int)v.size();
    ll ans=0,now=0;
    for(ll i=0;i<sz;i++)
    {
        for(ll j=i+1;j<sz;j++)
        {
            ans+=max(0LL,now-1)*45*p[sz-i-2];
            if(now) ans+=36*p[sz-i-2];
            ll cur=0;
            ans+=v[i]*(19-v[i])/2*p[sz-i-2];
            if(!now) ans-=9*p[sz-i-2];
            for(ll k=i+1;k<j;k++) cur=cur*10+v[k];
            ans+=(9-v[i])*cur*p[sz-j-1];
            if(v[j]>v[i])
            {
                cur=0;
                for(ll k=j+1;k<sz;k++) cur=cur*10+v[k];
                ans+=(cur+1);
                ans+=(v[j]-v[i]-1)*p[sz-j-1];
            }
            //printf("ans=%lld\n",ans);
        }
        now=now*10+v[i];
    }
    return ans;
}
int main()
{
    p[0]=1;
    for(ll i=1;i<=18;i++) p[i]=10*p[i-1];
    scanf("%lld",&T);
    int tot=0;
    while(T--)
    {
        scanf("%lld%lld",&x,&y);
        printf("Case %d: %lld\n",++tot,solve(y)-solve(x-1));
    }
    return 0;
}

