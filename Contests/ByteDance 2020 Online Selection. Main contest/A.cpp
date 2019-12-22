#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,b[MAXN],x[MAXN],y[MAXN];
ll add,shift;
vector<P> v;

bool check(P x,P y,P z)
{
    return 1LL*(z.S-y.S)*(y.F-x.F)<=1LL*(y.S-x.S)*(z.F-y.F);
}

void insert(ll x,ll y)
{
    int t=(int)v.size();
    while(t>=2&&check(P(v[t-2].F+add,v[t-2].S+shift),P(v[t-1].F+add,v[t-1].S+shift),P(x,y)))
    {
        v.pop_back();
        t--;
    }
    v.push_back(P(x-add,y-shift));
}
bool cmp(P x,P y)
{
    if(x.S!=y.S) return x.S<y.S;
    return x.F<y.F;
}
ll query(P p)
{
    int x=p.F,y=p.S;
    int t=(int)v.size();
    ll l=-1,r=t-1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(1LL*(v[mid].F+add)*x+1LL*(v[mid].S+shift)*y<=1LL*(v[mid+1].F+add)*x+1LL*(v[mid+1].S+shift)*y) l=mid;
        else r=mid;
    }
    return 1LL*(v[r].F+add)*x+1LL*(v[r].S+shift)*y;
}
int maxi[MAXN],pos[MAXN];
int main()
{
    add=shift=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&b[i],&x[i],&y[i]);
    maxi[1]=b[1]; pos[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(b[i]>=maxi[i-1])
        {
            maxi[i]=b[i];
            pos[i]=i;
        }
        else
        {
            maxi[i]=maxi[i-1];
            pos[i]=pos[i-1];
        }
    }
    insert(0,0);
    for(int i=1;i<=n;i++)
    {
        if(maxi[i]<=b[i])
        {
            if(i==1)
            {
                insert(0,1);
            }
            else 
            {
                add+=b[i]-maxi[i-1]; shift++;
                if(b[i]!=maxi[i-1]) insert(0,1);
            }
        }
        printf("%lld\n",query(P(-x[i],y[i])));
    }
    return 0;
}