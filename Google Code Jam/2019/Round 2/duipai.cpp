#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int main()
{
    scanf("%lld",&T);
    for(ll t=1;t<=T;t++)
    {
        scanf("%lld",&N);
        for(ll i=1;i<=N;i++) scanf("%lld%lld",&C[i],&J[i]);
        bool f=false;
        for(int i=1;i<=300;i++)
        {
            if(f) break;
            for(int j=1;j<=300;j++)
            {
                if(f) break;
                bool flag=true;
                for(int k=1;k<N;k++)
                {
                    if(C[k]*i+J[k]*j>=C[k+1]*i+J[k+1]*j) {flag=false; break;}
                }
                if(flag)
                {
                    f=true;
                    printf("Case #%lld: %d %d\n",t,i,j);
                    break;
                }
            }
        }
        if(!f)
        {
            printf("Case #%lld: IMPOSSIBLE\n",t);
            continue;
        }
    }
    return 0;
}
