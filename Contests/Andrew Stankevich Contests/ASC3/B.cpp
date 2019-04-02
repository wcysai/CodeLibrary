#include<bits/stdc++.h>
#define MAXN 605
#define INF 100000000000000LL
#define MODD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN];
ll w[MAXN][MAXN];
vector<ll> u(MAXN),v(MAXN),p(MAXN),way(MAXN);
ll ans[MAXN];
void km(ll n,ll m)
{
    for(ll i=1;i<=n;i++)
    {
        p[0]=i;
        ll j0=0;
        vector<ll> minv(m+1,INF);
        vector<char> used(m+1,false);
        do
        {
            used[j0]=true;
            ll i0=p[j0],delta=INF,j1=0;
            for(ll j=1;j<=m;j++)
                if(!used[j])
                {
                    ll cur=w[i0][j]-u[i0]-v[j];
                    if(cur<minv[j]) minv[j]=cur,way[j]=j0;
                    if(minv[j]<delta) delta=minv[j],j1=j;
                }
            for(ll j=0;j<=m;++j) if(used[j]) u[p[j]]+=delta,v[j]-=delta; else minv[j]-=delta;
            j0=j1;
        }while(p[j0]!=0);
        do
        {
            ll j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
}
int main()
{
    freopen("beloved.in","r",stdin);
    freopen("beloved.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
    {
        ll k;
        scanf("%lld",&k);
        for(ll j=0;j<k;j++)
        {
            ll x;scanf("%lld",&x);
            w[i][x]=-a[i]*a[i];
        }
    }
    km(n,n);
    for(ll i=1;i<=n;i++) if(w[p[i]][i]==0) ans[p[i]]=0; else ans[p[i]]=i;
    for(ll i=1;i<=n;i++) printf("%lld%c",ans[i],i==n?'\n':' ');
    return 0;
}
