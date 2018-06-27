#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,d,a[MAXN],id[MAXN],x,ans;
struct node
{
	int l,r,res;
}seg[4*MAXN];
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r;
	seg[k].res=0;
	if(l==r) {id[l]=k; return;}
	int mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
}
void update(int k,int x)
{
	k=id[k];
	seg[k].res=max(seg[k].res,x);
	while(k>1)
	{
		k=k/2;
		seg[k].res=max(seg[k*2].res,seg[k*2+1].res);
	}
}
int query(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].res;
	return max(query(k*2,l,r),query(k*2+1,l,r));
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		ans=0;
		build(1,1,100000);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&x);
			int lb=max(1,x-d),rb=min(100000,x+d);
			int res=query(1,lb,rb);
			ans=max(ans,res+1);
			update(x,res+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}