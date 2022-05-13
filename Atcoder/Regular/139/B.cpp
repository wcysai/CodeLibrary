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
int t;
ll n,a,b,x,y,z;
ll solve(ll rem,ll val,ll cost)
{
    ll used=rem/val;
    return cost*used+(rem-used*val)*x;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&n,&a,&b,&x,&y,&z);
        if(a*x<=y&&b*x<=z) printf("%lld\n",n*x);
        else if(a*x<=y) printf("%lld\n",solve(n,b,z));
        else if(b*x<=z) printf("%lld\n",solve(n,a,y));
        else
        {
            ll ans=n*x;
            if(a>=40000)
            {
                for(int i=0;i*a<=n;i++)
                    ans=min(ans,solve(n-i*a,b,z)+i*y);
            }
            else if(b>=40000)
            {
                for(int i=0;i*b<=n;i++)
                    ans=min(ans,solve(n-i*b,a,y)+i*z);
            }
            else
            {
                if(1LL*a*z<1LL*b*y) {swap(a,b); swap(y,z);}
                ll maxi=n/a;
                for(int i=max(0LL,maxi-b);i<=maxi;i++)
                    ans=min(ans,solve(n-i*a,b,z)+i*y);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

