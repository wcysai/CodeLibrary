#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int T;
ll a,b,c,x,y;
int main()
{
    freopen("end.in","r",stdin);
    freopen("end.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a>b) swap(a,b);
        if(c>b) {puts("-1"); continue;}
        if(c==a||c==b) {puts("1"); continue;}
        ll d=extgcd(a,b,x,y);
        if(c%d) {puts("-1"); continue;}
        a/=d; b/=d; c/=d;
        ll u=((x*c)%b+b)%b,v=u*a/b;
        ll ans=u+v;
        if(c<a) ans--;
        ans=min(ans,a+b-u-v-1);
        printf("%lld\n",2*ans);
    }
}
