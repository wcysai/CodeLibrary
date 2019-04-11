#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
mat id(2,vec(2));
ll mod,n,m;
mat a[MAXN];
mat mul(mat A,mat B)
{
    mat C(2,vec(2));
    C[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%mod;
    C[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%mod;
    C[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%mod;
    C[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%mod;
    return C;
}
struct segtree
{
    mat seg[4*MAXN];
    void pushup(ll k)
    {
        seg[k]=mul(seg[k*2],seg[k*2+1]);
    }
    void build(ll k,ll l,ll r)
    {
        if(l==r) {seg[k]=a[l]; return;}
        ll mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    mat query(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return id;
        if(l>=x&&r<=y) return seg[k];
        ll mid=(l+r)/2;
        return mul(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    freopen("crypto.in","r",stdin);
    freopen("crypto.out","w",stdout);
    id[0][0]=id[1][1]=1; id[0][1]=id[1][0]=0;
    scanf("%lld%lld%lld",&mod,&n,&m);
    for(ll i=1;i<=n;i++)
    {
        a[i].resize(2); a[i][0].resize(2); a[i][1].resize(2);
        scanf("%lld%lld%lld%lld",&a[i][0][0],&a[i][0][1],&a[i][1][0],&a[i][1][1]);
    }
    seg.build(1,1,n);
    for(ll i=0;i<m;i++)
    {
        ll l,r;scanf("%lld%lld",&l,&r); assert(l<=r);
        mat q=seg.query(1,1,n,l,r);
        printf("%lld %lld\n%lld %lld\n\n",q[0][0]%mod,q[0][1]%mod,q[1][0]%mod,q[1][1]%mod);
    }
    return 0;
}
