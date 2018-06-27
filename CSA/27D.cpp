#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 300005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,k;
ll p[MAXN],r[MAXN],cnt[MAXN];
ll save[MAXM][3];
bool used[MAXN];
void init(ll n)
{
    for(ll i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        used[i]=false;
        cnt[i]=1;
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; cnt[y]+=cnt[x];}
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        cnt[x]+=cnt[y];
    }
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    ll ans=0;
    init(n);
    for(ll i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&save[i][0],&save[i][1],&save[i][2]);
        save[i][0]--;
        save[i][1]--;
        if(save[i][2]<=k) unite(save[i][0],save[i][1]);
    }
    for(ll i=0;i<n;i++)
    {
        ll x=find(i);
        if(used[x]) continue;
        ans+=cnt[x]*(cnt[x]-1)/2;
        used[x]=true;
    }
    init(n);
    for(ll i=0;i<m;i++)
         if(save[i][2]<k) unite(save[i][0],save[i][1]);
    for(ll i=0;i<n;i++)
    {
        ll x=find(i);
        if(used[x]) continue;
        ans-=cnt[x]*(cnt[x]-1)/2;
        used[x]=true;
    }
    printf("%lld\n",ans);
    return 0;
}
