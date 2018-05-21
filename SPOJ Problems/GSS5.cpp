#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
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
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,1,n);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(y1<x2)
			{
				res ans1=query(1,x1,y1),ans2=query(1,x2,y2),ans3=query(1,y1+1,x2-1);
				printf("%d\n",ans1.rmax+ans3.sum+ans2.lmax);
			}
			else
			{
				res ans1=query(1,x1,x2-1),ans2=query(1,x2,y1),ans3=query(1,y1+1,y2),ans4=query(1,x2,y2),ans5=query(1,x1,y1);
				printf("%d\n",max(max(ans1.rmax+ans4.lmax,ans5.rmax+ans3.lmax),ans2.pmax));
			}
		}
	}
	return 0;
}