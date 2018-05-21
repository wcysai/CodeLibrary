#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct node
{
	int l,r;
	ll sum;
}seg[4*MAXN];
int n,m;
ll a[MAXN];
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r;
	if(l==r)
	{
		seg[k].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
}
void update(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return;
	if(seg[k].sum==seg[k].r-seg[k].l+1) return;
	if(seg[k].l==seg[k].r)
	{
		seg[k].sum=(ll)sqrt(seg[k].sum+0.0);
		return;
	}
	update(k*2,l,r);
	update(k*2+1,l,r);
	seg[k].sum=seg[k*2].sum+seg[k*2+1].sum;
}
ll query(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return 0LL;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].sum;
	return query(k*2,l,r)+query(k*2+1,l,r);
}
int main()
{
	int kase=0;
	while(scanf("%d",&n)!=EOF)
	{
		kase++;
		printf("Case #%d:\n",kase);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		build(1,1,n);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int type,l,r;
			scanf("%d%d%d",&type,&l,&r);
			if(l>r) swap(l,r);
			if(type==0) update(1,l,r); else printf("%lld\n",query(1,l,r));
		}
	}
	return 0;
}
