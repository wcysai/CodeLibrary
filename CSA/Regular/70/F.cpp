#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
struct node
{
	int l,r,_and,_or,res,lazy1,lazy2;
}seg[4*MAXN];
void merge(int k)
{
	seg[k].res=max(seg[k*2].res,seg[k*2+1].res);
	seg[k]._and=seg[k*2]._and&seg[k*2+1]._and;
	seg[k]._or=seg[k*2]._or|seg[k*2+1]._or;
}
void Lazy(int k)
{
	if(seg[k].l!=seg[k].r)
	{
		seg[k*2]._and&=seg[k].lazy1;
		seg[k*2+1]._and&=seg[k].lazy1;
		seg[k*2]._or&=seg[k].lazy1;
		seg[k*2+1]._or&=seg[k].lazy1;
		seg[k*2].res&=seg[k].lazy1;
		seg[k*2+1].res&=seg[k].lazy1;
		seg[k*2]._and|=seg[k].lazy2;
		seg[k*2+1]._and|=seg[k].lazy2;
		seg[k*2]._or|=seg[k].lazy2;
		seg[k*2+1]._or|=seg[k].lazy2;
		seg[k*2].res|=seg[k].lazy2;
		seg[k*2+1].res|=seg[k].lazy2;
		seg[k*2].lazy1&=seg[k].lazy1;seg[k*2+1].lazy1&=seg[k].lazy1;
		seg[k*2].lazy2&=seg[k].lazy1;seg[k*2+1].lazy2&=seg[k].lazy1;
		seg[k*2].lazy2|=seg[k].lazy2;seg[k*2+1].lazy2|=seg[k].lazy2;
	}
	seg[k].lazy1=(1<<20)-1;seg[k].lazy2=0;
}
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r;seg[k].lazy1=(1<<20)-1;seg[k].lazy2=0;
	if(l==r) {seg[k]._and=seg[k]._or=seg[k].res=a[l]; return;}
	int mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
	merge(k);
}
void update1(int k,int l,int r,int x)
{
	if(seg[k].l>r||seg[k].r<l||(((~seg[k]._or)&(~x))==(~x))) return;
	if(seg[k].l>=l&&seg[k].r<=r&&(((seg[k]._and^seg[k]._or)&(~x))==0))
	{
		seg[k]._and&=x;
		seg[k]._or&=x;
		seg[k].res&=x;
		seg[k].lazy1&=x;
		seg[k].lazy2&=x;
		return;
	}
	Lazy(k);
	update1(k*2,l,r,x);update1(k*2+1,l,r,x);
	merge(k);
}
void update2(int k,int l,int r,int x)
{
	if(seg[k].l>r||seg[k].r<l||((seg[k]._and&x)==x)) return;
	if(seg[k].l>=l&&seg[k].r<=r&&(((seg[k]._and^seg[k]._or)&x)==0))
	{
		seg[k]._and|=x;
		seg[k]._or|=x;
		seg[k].res|=x;
		seg[k].lazy2|=x;
		return;
	}
	Lazy(k);
	update2(k*2,l,r,x);update2(k*2+1,l,r,x);
	merge(k);
}
int query(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].res;
	Lazy(k);
	return max(query(k*2,l,r),query(k*2+1,l,r));
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int type,l,r,x;
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			update1(1,l,r,x);
		}
		else if(type==2)
		{
			scanf("%d%d%d",&l,&r,&x);
			update2(1,l,r,x);
		}
		else 
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,l,r));
		}
	}
	return 0;
}