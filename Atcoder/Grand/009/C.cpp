#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll a,b,s[MAXN];
int n;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
struct segtree
{
	int sum[4*MAXN],lazy[4*MAXN],len[4*MAXN];
	void pushup(int k)
	{
		sum[k]=sum[k*2];
		add(sum[k],sum[k*2+1]);
	}
	void st(int k,int v)
	{
		lazy[k]=v;
		sum[k]=1LL*len[k]*v%MOD;
	}
	void pushdown(int k)
	{
		if(lazy[k]==-1) return;
		for(int i=k*2;i<=k*2+1;i++) st(i,lazy[k]);
		lazy[k]=-1;
	}
	void build(int k,int l,int r)
	{
		lazy[k]=-1; sum[k]=0; len[k]=r-l+1;
		if(l==r) return;
		int mid=(l+r)/2;
		build(k*2,l,mid); build(k*2+1,mid+1,r);
	}
	void update(int k,int l,int r,int x,int y,int v)
	{
		if(l>y||x>r) return;
		if(l>=x&&r<=y) {st(k,v); return;}
		pushdown(k);
		int mid=(l+r)/2;
		update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
		pushup(k);
	}
	int query(int k,int l,int r,int x,int y)
	{
		if(l>y||x>r) return 0;
		if(l>=x&&r<=y) return sum[k];
		pushdown(k);
		int mid=(l+r)/2;
		int res=query(k*2,l,mid,x,y);
		add(res,query(k*2+1,mid+1,r,x,y));
		return res;
	}
}f,g;
int main()
{
	scanf("%d%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	f.build(1,0,n); g.build(1,0,n);
	f.update(1,0,n,0,0,1); g.update(1,0,n,0,0,1);
	for(int i=2;i<=n;i++)
	{
		int posa=upper_bound(s+1,s+i+1,s[i]-a)-s-1;
		int vala=g.query(1,0,n,0,min(posa,i-2));
		int posb=upper_bound(s+1,s+i+1,s[i]-b)-s-1;
		int valb=f.query(1,0,n,0,min(posb,i-2));
		if(posa!=i-1) f.update(1,0,n,0,i,0);
		f.update(1,0,n,i-1,i-1,vala);
		if(posb!=i-1) g.update(1,0,n,0,i,0);
		g.update(1,0,n,i-1,i-1,valb);
	}
	int ans=f.query(1,0,n,0,n-1);
	add(ans,g.query(1,0,n,0,n-1));
	printf("%d\n",ans);
	return 0;
}