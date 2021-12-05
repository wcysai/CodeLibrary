#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
ll x[MAXN],y[MAXN],c[MAXN];
vector<pair<ll,pair<ll,ll> > > v[MAXN*MAXN];
map<pair<pair<ll,ll>,ll >,int> mp;
ll get_id(pair<pair<ll,ll>,ll> p)
{
    if(mp.find(p)==mp.end()) mp[p]=tot++;
    return mp[p];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld%lld%lld",&x[i],&y[i],&c[i]);
        x[i]*=2; y[i]*=2;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            //mid point
            ll xmid=(x[i]+x[j])/2,ymid=(y[i]+y[j])/2;
            ll deltax=x[j]-x[i],deltay=y[j]-y[i];
            swap(deltax,deltay);
            deltay=-deltay;
            ll g=__gcd(max(-deltax,deltax),max(-deltay,deltay));
            deltax/=g; deltay/=g;
            if(deltax<0) {deltax=-deltax; deltay=-deltay;}
            int id;
            if(deltax!=0)
            {
                ll res=xmid*deltay-ymid*deltax;
                id=get_id(make_pair(make_pair(deltax,deltay),res));
            }
            else id=get_id(make_pair(make_pair(0,1),xmid));
            v[id].push_back(make_pair(c[i]+c[j],make_pair(xmid,ymid)));
        }
    ll ans=-1;
    for(int i=0;i<tot;i++)
    {
        if(v[i].size()<2) continue;
        sort(v[i].begin(),v[i].end(),greater<pair<ll,pair<ll,ll> > >());
        auto p=v[i][0];
        for(int j=1;j<(int)v[i].size();j++)
            if(v[i][j].S!=p.S) ans=max(ans,p.F+v[i][j].F);
    }
    printf("%lld\n",ans);
    return 0;
}