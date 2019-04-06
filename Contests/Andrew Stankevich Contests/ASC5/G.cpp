#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m;
ll w[MAXN][MAXN],a[MAXN];
vector<ll> valid[MAXN];
vector<ll> u,v,p,way;
ll res[MAXN];
ll km(ll n,ll m)
{
    u.resize(n+1);v.resize(m+1);p.resize(m+1);way.resize(m+1);
    for(ll i=1;i<=n;i++)
    {
        p[0]=i;
        ll j0=0;
        vector<int> minv(m+1,INF);
        vector<char> used(m+1,false);
        do
        {
            used[j0]=true;
            ll i0=p[j0],delta=INF,j1=0;
            for(ll j=1;j<=m;j++)
            {
                if(!used[j])
                {
                    ll cur=w[i0][j]-u[i0]-v[j];
                    if(cur<minv[j]) minv[j]=cur,way[j]=j0;
                    if(minv[j]<delta) delta=minv[j],j1=j;
                }
            }
            for(ll j=0;j<=m;j++) if(used[j]) u[p[j]]+=delta,v[j]-=delta; else minv[j]-=delta;
            j0=j1;
        }while(p[j0]!=0);
        do
        {
            ll j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
    ll res=0;
    for(ll i=1;i<=m;i++) res+=w[p[i]][i];
    return res;
}
bool has[MAXN];
int main()
{
    freopen("keeper.in","r",stdin);
    freopen("keeper.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    memset(has,false,sizeof(has));
    if(m<n) m=n;
    for(ll i=1;i<=n;i++)
    {
        ll k;scanf("%lld",&k);
        for(ll j=0;j<k;j++)
        {
            ll x;scanf("%lld",&x);
            valid[i].push_back(x);
        }
    }
    for(ll i=1;i<=n;i++) {scanf("%lld",&a[i]); has[a[i]]=true;}
    ll dummy=n;
    for(ll i=1;i<=n;i++)
    {
        for(auto x:valid[i]) 
        {
            if(has[x])
            {
                if(a[i]==x) w[i][x]=-INF-1;
                else w[i][x]=-INF;
            }
            else w[i][x]=-INF-1;
        }
    }
    if(n<m) n=m;
    for(ll i=1;i<=m;i++)
    {
        if(has[i])
        {
            for(ll j=1;j<=n;j++) 
            {
                bool f=false;
                for(auto x:valid[j]) if(x==i) {f=true; break;}
                if(!f) w[j][i]=INF;
            }
        }
    }
    ll ans=km(n,m);
    printf("%lld %lld\n",-ans/INF,-ans/INF-(-ans%INF));
    for(ll i=1;i<=m;i++) if(w[p[i]][i]!=0) res[p[i]]=i;
    for(ll i=1;i<=dummy;i++) printf("%lld ",res[i]);
    puts("");
    return 0;
}
