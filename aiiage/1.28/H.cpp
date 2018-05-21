#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct node
{
	int l,r,lazy;
}seg[4*MAXN];
int a[MAXN],val[MAXN];
int T,n,Q;
void build(int k,int l,int r)
{
	seg[k].l=l;
	seg[k].r=r;
	seg[k].lazy=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void Lazy(int k)
{
	if(seg[k].l==seg[k].r) return;
	else
	{
		seg[k*2].lazy=seg[k*2+1].lazy=seg[k].lazy;
		seg[k].lazy=0;
	}
}
void change(int k,int l,int r,int v)
{
	if(seg[k].lazy) Lazy(k);
	if(seg[k].l>=l&&seg[k].r<=r) {seg[k].lazy=v; return;}
	if(seg[k].l>r||seg[k].r<l) return;
	change(k*2,l,r,v);
	change(k*2+1,l,r,v);
}
int sum=0;
void clr(int k)
{
	if(seg[k].l==seg[k].r) {sum+=seg[k].lazy==0?a[seg[k].l]:val[seg[k].lazy]; return;}
	if(seg[k].lazy) Lazy(k);
	clr(k*2);
	clr(k*2+1);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		scanf("%d%d",&n,&Q);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,1,n);
		int cnt=0,deleted=0;
		for(int i=1;i<=Q;i++)
		{
			int x,l,r;
			scanf("%d",&x);
			if(x==1)
			{
				scanf("%d%d%d",&l,&r,&val[++cnt]);
				change(1,l,r,cnt);
			}
			else deleted++;
		}
		clr(1);
		printf("%d\n",sum);
	}
	return 0;
}