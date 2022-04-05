#include<bits/stdc++.h>
#define MAXN 500030
using namespace std;
typedef long long ll;
ll N,Q,L,R,a[MAXN],id[MAXN];
ll cal(ll x)
{
    return x*(x+1)/2;
}
struct node
{
    ll l,r,len,llen,rlen,ans;
}seg[2][4*MAXN];
struct save
{
    ll len,ans,llen,rlen;
};
void build(ll i,ll k,ll l,ll r)
{
    seg[i][k].l=l;
    seg[i][k].r=r;
    if(l==r)
    {
        id[l]=k;
        if(i==0)
            if(a[l]<L) seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=seg[i][k].len=1; else {seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=0; seg[i][k].len=1;}
        else
            if(a[l]<=R) seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=seg[i][k].len=1; else {seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=0; seg[i][k].len=1;}
        return;
    }
    ll mid=(l+r)/2;
    build(i,k*2,l,mid);
    build(i,k*2+1,mid+1,r);
    seg[i][k].len=seg[i][k*2].len+seg[i][k*2+1].len;
    seg[i][k].ans=seg[i][k*2].ans+seg[i][k*2+1].ans+cal(seg[i][k*2].rlen+seg[i][k*2+1].llen)-cal(seg[i][k*2].rlen)-cal(seg[i][k*2+1].llen);
    seg[i][k].llen=seg[i][k*2].llen==seg[i][k*2].len?seg[i][k*2].llen+seg[i][k*2+1].llen:seg[i][k*2].llen;
    seg[i][k].rlen=seg[i][k*2+1].rlen==seg[i][k*2+1].len?seg[i][k*2+1].rlen+seg[i][k*2].rlen:seg[i][k*2+1].rlen;
}
void update(ll i,ll k,ll a)
{
    k=id[k];
    if(i==0)
        if(a<L) seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=1; else seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=0;
    else
        if(a<=R) seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=1; else seg[i][k].llen=seg[i][k].rlen=seg[i][k].ans=0;
    while(k>1)
    {
        k=k/2;
        seg[i][k].ans=seg[i][k*2].ans+seg[i][k*2+1].ans+cal(seg[i][k*2].rlen+seg[i][k*2+1].llen)-cal(seg[i][k*2].rlen)-cal(seg[i][k*2+1].llen);
        seg[i][k].llen=seg[i][k*2].llen==seg[i][k*2].len?seg[i][k*2].llen+seg[i][k*2+1].llen:seg[i][k*2].llen;
        seg[i][k].rlen=seg[i][k*2+1].rlen==seg[i][k*2+1].len?seg[i][k*2+1].rlen+seg[i][k*2].rlen:seg[i][k*2+1].rlen;
    }
}

save query(ll i,ll k,ll l,ll r)
{
    if(seg[i][k].l>r||seg[i][k].r<l) return (save){0,0,0,0};
    if(seg[i][k].l>=l&&seg[i][k].r<=r) return (save){seg[i][k].len,seg[i][k].ans,seg[i][k].llen,seg[i][k].rlen};
    save x=query(i,k*2,l,r);
    save y=query(i,k*2+1,l,r);
    ll a,b,c,d;
    a=x.len+y.len;
    b=x.ans+y.ans+cal(x.rlen+y.llen)-cal(x.rlen)-cal(y.llen);
    c=x.llen==x.len?x.llen+y.llen:x.llen;
    d=y.rlen==y.len?y.rlen+x.rlen:y.rlen;
    return (save){a,b,c,d};
}
int main()
{
    scanf("%lld%lld%lld%lld",&N,&Q,&L,&R);
    for(ll i=1;i<=N;i++)
        a[i]=0;
    build(0,1,1,N);
    build(1,1,1,N);
    for(ll i=0;i<Q;i++)
    {
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x==1) {update(0,y,z); update(1,y,z);}
        else printf("%lld\n",query(1,1,y,z).ans-query(0,1,y,z).ans);
    }
    return 0;
}
