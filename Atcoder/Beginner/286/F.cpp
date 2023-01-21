#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
ll r[MAXN][MAXN],x[MAXN];
vector<int> pr={4,9,5,7,11,13,17,19,23};
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    int d=a;
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
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll solve(vector<P> &v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            r[i][j]=mod_inverse(v[i].S,v[j].S);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        x[i]=v[i].F;
        for(int j=0;j<i;j++)
        {
            x[i]=r[j][i]*(x[i]-x[j]);
            x[i]=x[i]%v[i].S;
            if(x[i]<0) x[i]+=v[i].S;
        }
    }
    ll base=1;
    for(int i=0;i<n;i++)
    {
        ans+=base*x[i];
        base*=v[i].S;
    }
    return ans;
}
int a[MAXN],b[MAXN],c[MAXN],tmp[MAXN];
void gen(int x){
    for(int i=1;i<=n;i++) b[i]=i,c[i]=a[i];
    while(x){
        if(x&1){
            for(int i=1;i<=n;i++) tmp[i]=b[c[i]];
            for(int i=1;i<=n;i++) b[i]=tmp[i];
        }
        x>>=1;
        for(int i=1;i<=n;i++) tmp[i]=c[c[i]];
        for(int i=1;i<=n;i++) c[i]=tmp[i];
    }
}
int main()
{
    printf("108\n"); fflush(stdout);
    int tot=1;
    for(int i=0;i<(int)pr.size();i++){
        for(int j=tot;j<tot+pr[i]-1;j++) a[j]=j+1;
        a[tot+pr[i]-1]=tot;
        tot+=pr[i];
    }
    assert(tot==109);
    for(int i=1;i<=108;i++) printf("%d%c",a[i],i==108?'\n':' '); fflush(stdout);
    n=108;
    //int x; scanf("%d",&x); gen(x);
    for(int i=1;i<=108;i++) scanf("%d",&b[i]);
   // for(int i=1;i<=108;i++) printf("%d ",b[i]); puts("");
    tot=1;
    vector<P> v;
    for(int i=0;i<(int)pr.size();i++){
        int id=0;
        for(int j=tot;j<=tot+pr[i]-1;j++){
            if(b[j]==tot){
                id=(tot+pr[i]-j)%pr[i];
                break;
            }
        }
       // printf("id=%d pr=%d\n",id,pr[i]);
        tot+=pr[i];
        v.push_back(P(id,pr[i]));
    }
    ll ret=solve(v);
    printf("%lld\n",ret); fflush(stdout);
    return 0;
}

