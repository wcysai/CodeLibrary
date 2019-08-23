#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q,l,w;
ll offset=1000001;
struct update
{
    ll y,mult;
};
struct query
{
    ll y,id,mult;
};
struct bit
{
    ll s[MAXN];
    ll sum(int i)
    {
        ll res=0;
        while(i>0)
        {
            res+=s[i];
            i-=i&-i;
        }
        return res;
    }
    void add(ll i,ll x)
    {
        while(i<MAXN)
        {
            s[i]+=x;
            i+=i&-i;
        }
    }
    void add(ll l,ll r,ll x)
    {
        add(r,x);
        add(l-1,-x);
    }
}X,Y,XY,cons;

vector<update> t[MAXN];
vector<query> tq[MAXN];
ll ans[MAXN];
int main()
{
    scanf("%lld%lld%lld%lld",&n,&q,&l,&w);
    for(ll i=0;i<n;i++)
    {
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        t[a+1].push_back((update){b+1,1});
        t[a+1].push_back((update){d+1,-1});
        t[c+1].push_back((update){b+1,-1});
        t[c+1].push_back((update){d+1,1});
    }
    for(ll i=0;i<q;i++)
    {
        ll a,b,c,d;
        scanf("%lld%lld",&a,&b);
        c=a+l; d=b+w;
        tq[c].push_back((query){d,i,1});
        tq[c].push_back((query){b,i,-1});
        tq[a].push_back((query){d,i,-1});
        tq[a].push_back((query){b,i,1});
    }
    for(ll i=1;i<=1000000;i++)
    {
        for(auto x:t[i])
        {
            ll a=i-1,b=x.y-1,pos=x.y,v=x.mult;
            XY.add(pos,v); X.add(pos,-b*v);
            Y.add(pos,-a*v); cons.add(pos,a*b*v);
        }
        for(auto qu:tq[i]) ans[qu.id]+=qu.mult*(XY.sum(qu.y)*qu.y*i+Y.sum(qu.y)*qu.y+X.sum(qu.y)*i+cons.sum(qu.y));
    }
    for(ll i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}
