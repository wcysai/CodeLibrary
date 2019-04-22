#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll,ll> P;
P p,q,r;
db dis(P p,P q)
{
    return sqrt((db)(p.F-q.F)*(p.F-q.F)+(p.S-q.S)*(p.S-q.S));
}
int main()
{
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld%lld",&p.F,&p.S,&q.F,&q.S,&r.F,&r.S);
    db a=dis(p,q),b=dis(p,r),c=dis(q,r);
    db sum=(a+b+c)/2;
    printf("%.10Lf\n%.10Lf\n%.10Lf\n",sum-c,sum-b,sum-a);
    return 0;
}
