#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,p[MAXN];
int p2[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
struct segtree
{
    int val1[4*MAXN],len[4*MAXN],val2[4*MAXN];
    //val1: a1+a2/2+a3/4...
    //val2: an+an-1/2+an-2/4...
    void pushup(int k)
    {
        val1[k]=val1[k*2];
        add(val1[k],1LL*val1[k*2+1]*p2[len[k*2]]%MOD);
        val2[k]=val2[k*2+1];
        add(val2[k],1LL*val1[k*2]*p2[len[k*2+1]]%MOD);
    }
    void build(int k,int l,int r)
    {
        len[k]=r-l+1;
        if(l==r)
        {
            val1[k]=val2[k]=p[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void modify(int k,int l,int r,int p,int v)
    {
        if(l==r)
        {
            val1[k]=val2[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) modify(k*2,l,mid,p,v); else modify(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    P query1(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(0,0);
        if(l>=x&&r<=y) return P(val1[k],len[k]);
        int mid=(l+r)/2;
        P p=query1(k*2,l,mid,x,y),q=query1(k*2+1,mid+1,r,x,y);
        int val=p.F;
        add(val,1LL*q.F*p2[p.S]%MOD);
        return make_pair(val,p.S+q.S);
    }
    P query2(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(0,0);
        if(l>=x&&r<=y) return P(val2[k],len[k]);
        int mid=(l+r)/2;
        P p=query1(k*2,l,mid,x,y),q=query1(k*2+1,mid+1,r,x,y);
        int val=q.F;
        add(val,1LL*p.F*p2[q.S]%MOD);
        return make_pair(val,p.S+q.S);
    }
}seg;
int main()
{
    scanf("%d",&n);
    p2[0]=1;
    for(int i=1;i<=n;i++) p2[i]=1LL*p2[i-1]*INV%MOD;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    seg.build(1,1,n);
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        int val=seg.query1(1,1,n,i+1,n).F;
        printf("val=%d\n",val);
        add(ans,1LL*p[i]*val%MOD*INV%MOD*INV%MOD);
    }
    printf("%d\n",ans);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int lval=seg.query2(1,1,n,1,x-1).F,rval=seg.query1(1,1,n,x+1,n).F;
        printf("lval=%d rval=%d\n",lval,rval);
        dec(ans,1LL*p[x]*lval%MOD*INV%MOD*INV%MOD);
        dec(ans,1LL*p[x]*rval%MOD*INV%MOD*INV%MOD);
        seg.modify(1,1,n,x,y);
        p[x]=y;
        add(ans,1LL*p[x]*lval%MOD*INV%MOD*INV%MOD);
        add(ans,1LL*p[x]*rval%MOD*INV%MOD*INV%MOD);
        printf("%d\n",ans);
    }
    return 0;
}