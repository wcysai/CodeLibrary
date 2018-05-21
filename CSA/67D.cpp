#include<bits/stdc++.h>
#define MAXN 131075
#define x first
#define y second
using namespace std;
int n,m,h[MAXN],c[MAXN],query,b[MAXN],lf,rt,md;

typedef pair<int,int> pi;
typedef pair<int,pi> pii;

pii a[MAXN];

bool cmp(pii u,pii v)
{
    return u.first<v.first;
}

struct node
{
    int l,r;
    pi val;
}seg[4*MAXN];

void build(int k,int l,int r)
{
    seg[k].l=l;
    seg[k].r=r;
    if(l==r)
    {
        seg[k].val={0,l};
        b[l]=k;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build((k<<1)|1,mid+1,r);
}

void update(int k,int l,int r,pi vr)
{
    if (r<l) return;
    if(seg[k].l>r||seg[k].r<l) return;
    if(seg[k].l>=l&&seg[k].r<=r) {seg[k].val=vr;return;}
    update(k<<1,l,r,vr);
    update((k<<1)|1,l,r,vr);
}

int qry(int num)
{
    int k=b[num];
    pi tmp={0,0};
    while (k>1){
        tmp=max(tmp,seg[k].val);
        k>>=1;
    }
    return tmp.y;
}

int main()
{
    scanf("%d%d",&n,&query);
    build(1,1,131072);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].y.x,&a[i].y.y,&a[i].x);
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        lf,rt;
        lf=a[i].y.x;
        rt=a[i].y.y;
        md=(lf+rt)>>1;
        //printf("%d %d\n",lf,rt);
        update(1,lf,md,{i,qry(lf)});
        update(1,md+1,rt,{i,qry(rt)});
    }
    while (query--)
    {
        scanf("%d",&m);
        printf("%d\n",qry(m));
    }
    return 0;
}
