#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
P a[MAXN];
vector<int> v;
ll calc(ll x,ll y)
{
    return abs(x)+abs(y);
}
char check(ll &x,ll &y,ll d)
{
    ll now=INF;
    char ret='X';
    if(calc(x-d,y)<now) {now=calc(x-d,y); ret='L';}
    if(calc(x+d,y)<now) {now=calc(x+d,y); ret='R';}
    if(calc(x,y-d)<now) {now=calc(x,y-d); ret='D';}
    if(calc(x,y+d)<now) {now=calc(x,y+d); ret='U';}
    assert(ret!='X');
    if(ret=='L') x-=d; else if(ret=='R') x+=d; else if(ret=='D') y-=d; else y+=d;
    return ret;
}
void solve()
{
    for(auto x:v) printf("%lld ",x);
    puts("");
    for(ll i=0;i<n;i++)
    {
        a[i].F=-a[i].F;a[i].S=-a[i].S;
        for(auto x:v) printf("%c",check(a[i].F,a[i].S,x));
        assert(a[i].F==0&&a[i].S==0);
        puts("");
    }
}
int main()
{
    scanf("%lld",&n);
    ll parity=-1;
    bool f=true;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i].F,&a[i].S);
        if(parity!=-1&&((a[i].F+a[i].S)&1)!=parity) f=false;
        parity=(a[i].F+a[i].S)&1;
    }
    if(!f)
    {
        puts("-1");
        return 0;
    }
    if(parity)
    {
        printf("%lld\n",31);
        for(ll i=30;i>=0;i--) v.push_back(1<<i);
    }
    else
    {
        printf("%lld\n",32);
        for(ll i=30;i>=0;i--) v.push_back(1<<i);
        v.push_back(1);
    }
    solve();
    return 0;
}

