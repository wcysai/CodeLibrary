#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll t,n;
P a[MAXN];
map<pair<P,ll>,ll> mp;

struct line
{
    ll a,b,c;
    //ax+by+c=0
    void norm()
    {
        ll g=__gcd(a,b);
        g=__gcd(g,c);
        a/=g;b/=g;c/=g;
        if(a<0) {a=-a; b=-b; c=-c;}
        if(a==0&&b<0) {b=-b; c=-c;}
    }
};
struct node
{
    ll a,b,c;
    void norm()
    {
        ll g=__gcd(a,b);
        a/=g;b/=g;
        if(a<0) {a=-a; b=-b;}
        if(a==0&&b<0) b=-b;
    }
};
bool cmp(node x,node y)
{
    if(x.a!=y.a) return x.a<y.a;
    if(x.b!=y.b) return x.b<y.b;
    return x.c<y.c;
}
vector<node> vv;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);vv.clear();mp.clear();
        for(ll i=0;i<n;i++) scanf("%lld%lld",&a[i].F,&a[i].S);
        if(n<=2) {printf("%lld\n",n); continue;}
        for(ll i=0;i<n;i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                line newline;
                newline.a=a[j].S-a[i].S;
                newline.b=a[i].F-a[j].F;
                newline.c=-a[i].F*(a[j].S-a[i].S)+a[i].S*(a[j].F-a[i].F);
                newline.norm();
                mp[{{newline.a,newline.b},newline.c}]++;
            }
        }
        for(auto v:mp)
        {
            ll t=sqrt(2*v.S),ans=-1;
            for(ll i=max(1LL,t-5);i<=t+5;i++)
            {
                if(i*(i-1)/2==v.S)
                {
                    ans=i;
                    break;
                }
            }
            assert(ans!=-1);
            node newnode;
            newnode.a=v.F.F.F;newnode.b=v.F.F.S;newnode.c=ans;
            newnode.norm();
            vv.push_back(newnode);
        }
        sort(vv.begin(),vv.end(),cmp);
        ll ans=0,curmax=0;
        for(ll i=0;i<(int)vv.size();i++)
        {
            ans=max(ans,vv[i].c+1);
            if(i>=1&&vv[i].a==vv[i-1].a&&vv[i].b==vv[i-1].b)
            {
                ans=max(ans,vv[i].c+curmax);
                curmax=max(curmax,vv[i].c);
            }
            else curmax=vv[i].c;
        }
        printf("%lld\n",min(n,ans));
    }
    return 0;
}

