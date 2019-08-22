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
ll bit[2][MAXN];
ll sum(ll id,ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(ll id,ll i,ll x)
{
    while(i<MAXN)
    {
        bit[id][i]+=x;
        i+=i&-i;
    }
}
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
        t[a+1].push_back((update){d,1});
        t[a+1].push_back((update){b,-1});
        t[c+1].push_back((update){d,-1});
        t[c+1].push_back((update){b,1});
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
        for(auto upd:t[i])
        {
            add(0,offset-upd.y,-upd.mult*(i-1));
            add(1,offset-upd.y,upd.mult);
            printf("add0 %lld %lld\n",upd.y,-upd.mult*(i-1));
            printf("add1 %lld %lld\n",upd.y,upd.mult);
        }
        for(auto qu:tq[i])
        {
            ans[qu.id]+=qu.mult*qu.y*(sum(0,offset-qu.y)+sum(1,offset-qu.y)*i);
            printf("query %lld %lld %lld %lld ",qu.mult,qu.y,sum(0,offset-qu.y),sum(1,offset-qu.y));
            printf("%lld\n",ans[qu.id]);
        }
    }
    for(ll i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}
