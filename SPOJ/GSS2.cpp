#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN],save[2*MAXN],last[MAXN],ans[MAXN];
struct qry
{
	ll l,r,id;
}q[MAXN];
struct node
{
	ll l,r,cur,best,lazy,bestlazy;
}seg[4*MAXN];
void build(ll k,ll l,ll r)
{
	seg[k].l=l;seg[k].r=r;
	seg[k].cur=seg[k].lazy=0;
	seg[k].bestlazy=seg[k].best=0;
	if(l==r) return;
	ll mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
}
bool cmp(qry x,qry y)
{
	if(x.r!=y.r) return x.r<y.r;
	return x.l<y.l;
}
void Lazy(ll k)
{
	if(seg[k].l!=seg[k].r)
	{
		seg[k*2].bestlazy=max(seg[k*2].bestlazy,seg[k*2].lazy+seg[k].bestlazy);
		seg[k*2+1].bestlazy=max(seg[k*2+1].bestlazy,seg[k*2+1].lazy+seg[k].bestlazy);
		seg[k*2].best=max(seg[k*2].best,seg[k*2].cur+seg[k].bestlazy);
		seg[k*2+1].best=max(seg[k*2+1].best,seg[k*2+1].cur+seg[k].bestlazy);
		seg[k*2].lazy+=seg[k].lazy;seg[k*2+1].lazy+=seg[k].lazy;
		seg[k*2].cur+=seg[k].lazy;seg[k*2+1].cur+=seg[k].lazy;
	}
	seg[k].lazy=seg[k].bestlazy=0;
}
void update(ll k,ll l,ll r,ll x)
{
	if(seg[k].l>r||seg[k].r<l) return;
	if(seg[k].l>=l&&seg[k].r<=r)
	{
		seg[k].lazy+=x;
		seg[k].cur+=x;
		seg[k].bestlazy=max(seg[k].bestlazy,seg[k].lazy);
		seg[k].best=max(seg[k].best,seg[k].cur);
		Lazy(k);
		return;
	}
	Lazy(k);
	update(k*2,l,r,x);update(k*2+1,l,r,x);
	seg[k].cur=max(seg[k*2].cur,seg[k*2+1].cur);
	seg[k].best=max(seg[k*2].best,seg[k*2+1].best);
}
ll query(ll k,ll l,ll r)
{
	if(seg[k].l>r||seg[k].r<l) return -INF;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].best;
	Lazy(k);
	return max(query(k*2,l,r),query(k*2+1,l,r)); 
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);
	memset(save,0,sizeof(save));
	for(ll i=1;i<=n;i++)
	{
		last[i]=save[a[i]+100000];
		save[a[i]+100000]=i;
	}
	scanf("%lld",&m);
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	ll now=1;
	for(ll i=1;i<=n;i++)
	{
		update(1,last[i]+1,i,a[i]);
		//printf("update %lld %lld %lld\n",last[i]+1,i,a[i]);
		while(q[now].r==i&&now<=m)
		{
			ans[q[now].id]=query(1,q[now].l,q[now].r);
			//printf("query %lld %lld %lld\n",q[now].l,q[now].r,ans[q[now].id]);
			now++;
		}
	}
	for(ll i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
