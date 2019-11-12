#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll T,N;
ll C[MAXN],J[MAXN];
struct frac
{
    ll p,q;
    frac(){}
    frac(ll _p,ll _q){p=_p; q=_q;}
    void pton()
    {
        ll g=__gcd(p,q);
        p/=g; q/=g;
    }
    bool operator<(const frac& f) const
    {
        return 1LL*p*f.q<1LL*q*f.p;
    }
};
P cal(ll a,ll b,ll c,ll d)
{
    //printf("%lld %lld %lld %lld\n",a,b,c,d);
    ll x=a/b+1;if(x*d<c) return P(x,1);
    if(!a) return P(1,d/c+1);
    if(a<=b&&c<=d)
    {
        P t=cal(d,c,b,a);
        swap(t.F,t.S); return t;
    }
    x=a/b;P t=cal(a-b*x,b,c-d*x,d);
    t.F+=t.S*x;return t;
}
int main()
{
    scanf("%lld",&T);
    for(ll t=1;t<=T;t++)
    {
        scanf("%lld",&N);
        for(ll i=1;i<=N;i++) scanf("%lld%lld",&C[i],&J[i]);
        frac l(1,2*INF),r(2*INF,1);
        bool f=true;
        for(ll i=1;i<=N;i++)
            for(ll j=i+1;j<=N;j++)
            {
                if(C[i]<=C[j]&&J[i]<=J[j]) continue;
                if(C[i]>=C[j]&&J[i]>=J[j])
                {
                    f=false;
                    break;
                }
                if(C[i]>C[j]&&J[i]<J[j])
                {
                    ll d1=C[i]-C[j],d2=J[j]-J[i];
                    r=min(r,frac(d2,d1));
                    r.pton();
                }
                if(C[i]<C[j]&&J[i]>J[j])
                {
                    ll d1=C[j]-C[i],d2=J[i]-J[j];
                    l=max(l,frac(d2,d1));
                    l.pton();
                }
            }
        if(r<l||(l.p==r.p&&l.q==r.q)||!f)
        {
            printf("Case #%lld: IMPOSSIBLE\n",t);
            continue;
        }
        P p=cal(r.q,r.p,l.q,l.p);
        printf("Case #%lld: %lld %lld\n",t,p.S,p.F);
    }
    return 0;
}
