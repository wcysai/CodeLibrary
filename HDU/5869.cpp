#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
struct node
{
	int l,r,res;
}seg[4*MAXN];
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r;
	if(l==r)
	{
		seg[k].res=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
	seg[k].res=gcd(seg[k*2].res,seg[k*2+1].res);
}
int query(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].res;
	return gcd(query(k*2,l,r),query(k*2+1,l,r));
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,l,r));
	}
	return 0;
}