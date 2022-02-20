#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,x,p[MAXN];
struct segtree
{
	int cnt[3][4*MAXN];
	int lazy[4*MAXN],len[4*MAXN];
	void pushup(int k)
	{
		for(int i=0;i<3;i++) cnt[i][k]=cnt[i][k*2]+cnt[i][k*2+1];
	}
	void st(int k,int v)
	{
		lazy[k]=v;
		for(int i=0;i<3;i++) if(i==v) cnt[i][k]=len[k]; else cnt[i][k]=0;
	}
	void pushdown(int k)
	{
		if(lazy[k]==-1) return;
		for(int i=k*2;i<=k*2+1;i++) st(i,lazy[k]);
		lazy[k]=-1;
	}
	void build(int k,int l,int r)
	{
		lazy[k]=-1; len[k]=r-l+1;
		if(l==r)
		{
			cnt[0][k]=cnt[1][k]=cnt[2][k]=0;
			if(p[l]>x) cnt[2][k]=1;
			else if(p[l]<x) cnt[0][k]=1;
			else cnt[1][k]=1;
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid); build(k*2+1,mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int x,int y,int v)
	{
		if(l>y||x>r) return;
		if(l>=x&&r<=y)
		{
			st(k,v);
			return;
		}
		pushdown(k);
		int mid=(l+r)/2;
		update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
		pushup(k);
	}
	int query(int k,int l,int r,int x,int y,int v)
	{
		if(l>y||x>r) return 0;
		if(l>=x&&r<=y) return cnt[v][k];
		pushdown(k);
		int mid=(l+r)/2;
		return query(k*2,l,mid,x,y,v)+query(k*2+1,mid+1,r,x,y,v);
	}
	int find_pos(int k,int l,int r)
	{
		if(l==r) return l;
		pushdown(k);
		int mid=(l+r)/2;
		if(cnt[1][k*2]) return find_pos(k*2,l,mid); else return find_pos(k*2+1,mid+1,r);
	}
}seg;
int main()
{
	scanf("%d%d%d",&n,&q,&x);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	seg.build(1,1,n);
	for(int i=0;i<q;i++)
	{
		int type,l,r;
		scanf("%d%d%d",&type,&l,&r);
		int tmp[3];
		for(int j=0;j<3;j++) tmp[j]=seg.query(1,1,n,l,r,j);
		if(type==1)
		{
			seg.update(1,1,n,l,l+tmp[0]-1,0);
			seg.update(1,1,n,l+tmp[0],l+tmp[0]+tmp[1]-1,1);
			seg.update(1,1,n,l+tmp[0]+tmp[1],r,2);
		}
		else
		{
			seg.update(1,1,n,l,l+tmp[2]-1,2);
			seg.update(1,1,n,l+tmp[2],l+tmp[2]+tmp[1]-1,1);
			seg.update(1,1,n,l+tmp[2]+tmp[1],r,0);
		}
	}
	printf("%d\n",seg.find_pos(1,1,n));
	return 0;
}