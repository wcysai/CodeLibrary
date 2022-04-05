#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],x;
struct node
{
	int maxi,mini;
	bool inc,dec;
	node(){maxi=mini=0; inc=dec=true;}
};
struct segtree
{
	int mini[4*MAXN],maxi[4*MAXN];
	void pushup(int k)
	{
		mini[k]=max(mini[k*2],mini[k*2+1]);
		maxi[k]=min(maxi[k*2],maxi[k*2+1]);
	}
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			if(a[l]==a[l+1])
			{
				mini[k]=-INF; maxi[k]=INF;
			}
			else if(a[l]<a[l+1]) 
			{
				mini[k]=-INF; maxi[k]=(a[l]+a[l+1])/2;
			}
			else
			{
				maxi[k]=INF; mini[k]=(a[l]+a[l+1]+1)/2;
			}
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid); build(k*2+1,mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int p)
	{
		if(l==r)
		{
			if(a[l]==a[l+1])
			{
				mini[k]=-INF; maxi[k]=INF;
			}
			else if(a[l]<a[l+1]) 
			{
				mini[k]=-INF; maxi[k]=(a[l]+a[l+1])/2;
			}
			else
			{
				maxi[k]=INF; mini[k]=(a[l]+a[l+1]+1)/2;
			}
			return;
		}
		int mid=(l+r)/2;
		if(p<=mid) update(k*2,l,mid,p); else update(k*2+1,mid+1,r,p);
		pushup(k);
	}
	P query(int k,int l,int r,int x,int y)
	{
		if(l>y||x>r) 
		{
			return P(-INF,INF);
		}
		if(l>=x&&r<=y) return P(mini[k],maxi[k]);
		int mid=(l+r)/2;
		P p=query(k*2,l,mid,x,y); P q=query(k*2+1,mid+1,r,x,y);
		return P(max(p.F,q.F),min(p.S,q.S));
	}
}seg;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	seg.build(1,1,n-1);
	for(int i=0;i<q;i++)
	{
		int type,l,r;
		scanf("%d%d%d",&type,&l,&r);
		if(type==1)
		{
			a[l]=r;
			seg.update(1,1,n-1,l); if(l>1) seg.update(1,1,n-1,l-1);
		}
		else
		{
			if(l==r) puts("0");
			else
			{
				P p=seg.query(1,1,n-1,l,r-1);
				if(p.F>p.S) puts("-1");
				else printf("%d\n",max(p.F,0));
			}
		}
	}
	return 0;
}