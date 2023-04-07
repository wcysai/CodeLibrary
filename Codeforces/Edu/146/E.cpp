#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k,a[MAXN];
struct mat{
    ll a[2][2];
    void init(int val){
        a[1][0]=val; a[1][1]=-INF;
        a[0][0]=a[0][1]=0;
    }
    void init_empty(){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=-INF;
    }
};
mat mul(mat &x,mat &y){
    mat z; z.init_empty();
    for(int k=0;k<2;k++)
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                z.a[i][j]=max(z.a[i][j],x.a[i][k]+y.a[k][j]);
    return z;
}
struct segtree{
    mat m[4*MAXN];
    void pushup(int k){
        m[k]=mul(m[k*2],m[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r){
            m[k].init(a[l+1]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v){
        if(l==r){
            m[k].init(v);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n-1;i++) {scanf("%d",&a[i]); sum+=a[i];}
    seg.build(1,1,n-3);
    scanf("%d",&q);
    while(q--){
        int k,x;
        scanf("%d%d",&k,&x);
        sum-=a[k]; a[k]=x; sum+=a[k];
        if(k>1&&k<n-1) seg.update(1,1,n-3,k-1,x);
        mat z=seg.m[1];
        ll ans=-INF;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ans=max(ans,z.a[i][j]);
        printf("%lld\n",2*(sum-ans));
    }
    return 0;
}

