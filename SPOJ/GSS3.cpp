#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],id[MAXN];
struct node
{
	int k,l,r,lmax,rmax,pmax,sum;
}seg[4*MAXN];
struct res
{
	int lmax,rmax,pmax,sum;
};
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r;
	if(l==r)
	{
		id[l]=k;
		seg[k].lmax=seg[k].rmax=seg[k].pmax=seg[k].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
	seg[k].lmax=max(seg[k*2].lmax,seg[k*2].sum+seg[k*2+1].lmax);
	seg[k].rmax=max(seg[k*2+1].rmax,seg[k*2+1].sum+seg[k*2].rmax);
	seg[k].pmax=max(max(seg[k*2].pmax,seg[k*2+1].pmax),seg[k*2].rmax+seg[k*2+1].lmax);
}
void update(int k,int x)
{
	seg[k].lmax=seg[k].rmax=seg[k].pmax=seg[k].sum=x;
	while(k>=1)
	{
		k=k/2;
		seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
		seg[k].lmax=max(seg[k*2].lmax,seg[k*2].sum+seg[k*2+1].lmax);
		seg[k].rmax=max(seg[k*2+1].rmax,seg[k*2+1].sum+seg[k*2].rmax);
		seg[k].pmax=max(max(seg[k*2].pmax,seg[k*2+1].pmax),seg[k*2].rmax+seg[k*2+1].lmax);
	}
}
res query(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return (res){-INF,-INF,-INF,0};
	if(seg[k].l>=l&&seg[k].r<=r) return (res){seg[k].lmax,seg[k].rmax,seg[k].pmax,seg[k].sum};
	res lb=query(k*2,l,r),rb=query(k*2+1,l,r);
	res ans;
	ans.sum=lb.sum+rb.sum;
	ans.lmax=max(lb.lmax,lb.sum+rb.lmax);
	ans.rmax=max(rb.rmax,rb.sum+lb.rmax);
	ans.pmax=max(max(lb.pmax,rb.pmax),lb.rmax+rb.lmax);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int type,l,r;
		scanf("%d%d%d",&type,&l,&r);
		if(type==0) update(id[l],r);
		else printf("%d\n",query(1,l,r).pmax);
	}
	return 0;
}