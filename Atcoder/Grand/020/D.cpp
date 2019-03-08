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
ll q,a,b,c,d,k;
bool check(ll turns)
{
    if(b<turns||a<k*turns) return false;
    ll restb=b-turns;
    ll resta=a-turns*k;
    if(restb>=k*(resta+1)) return false; else return true;
}
int main()
{
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        ll s=a+b;
        k=(max(a,b)-1)/(min(a,b)+1)+1;
        ll l=0,r=(a-1)/k+2;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        ll turns=l;
        a-=turns*k;b-=turns;
        ll cnta=0,cntb=0;
        cnta=a-(b-1)/k; a-=cnta;
        cntb=b-k*a; b-=cntb;
        assert(b==k*a);
        for(ll i=max(c,1LL);i<=min(d,turns*(k+1));i++)
        {
            if(i%(k+1)==0) printf("B"); else printf("A");
        }
        for(ll i=max(c,turns*(k+1)+1);i<=min(d,turns*(k+1)+cnta);i++) printf("A");
        for(ll i=max(c,turns*(k+1)+cnta+1);i<=min(d,turns*(k+1)+cnta+cntb);i++) printf("B");
        for(ll i=max(c,turns*(k+1)+cnta+cntb+1);i<=min(s,d);i++) if((s-i)%(k+1)!=k) printf("B"); else printf("A");
        puts("");
    }
    return 0;
}

