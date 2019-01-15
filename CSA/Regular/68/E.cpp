#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,K,M;
vector<ll> id;
void add(ll &x,ll y) {x+=y; if(x>=M) x-=M;}
ll mul_mod(ll x,ll y)
{
    ll s=0;
    while(y)
    {
        if(y&1) add(s,x);
        add(x,x);
        y>>=1;
    }
    return s;
}
vector<ll> find_ans(ll x)
{
    vector<ll> ret(K+1);
    if(x==1) return id;
    if(x&1)
    {
        ret=find_ans(x-1);
        for(int i=K;i>=1;i--) add(ret[i],ret[i-1]);
        return ret;
    }
    else
    {
        ret=find_ans(x>>1);
        for(int i=K;i>=0;i--)
        {
            ll ans=0;
            for(int j=0;j<=i;j++) add(ans,mul_mod(ret[j],ret[i-j]));
            ret[i]=ans;
        }
        return ret;
    }
}
int main()
{
    scanf("%lld%lld%lld",&N,&K,&M); K++;
    id.resize(K+1);
    id[0]=id[1]=1%M;
    for(int i=2;i<=K;i++) id[i]=0;
    vector<ll> ans=find_ans(N+1);
    ll fans=0,fact=1;
    for(ll i=2;i<=K;i++)
    {
        fact=mul_mod(fact,i-1);
        add(fans,mul_mod(fact,ans[i]));
    }
    printf("%lld\n",fans);
    return 0;
}
