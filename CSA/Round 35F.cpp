#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN];
int minL[MAXN],maxL[MAXN],p[MAXN],s[MAXN];
int st[MAXN];
struct node
{
	int l,r,sum,sump,minsum,maxsum,psum,lazy1,lazy2;
}seg[4*MAXN];
void Lazy(int k)
{
	if(!seg[k].lazy1&&!seg[k].lazy2) return;
	if(seg[k].l!=seg[k].r)
	{
		if(seg[k].lazy1) 
		{
			seg[k*2].lazy1=seg[k*2+1].lazy1=seg[k].lazy1;
			seg[k*2].sum=1LL*seg[k*2].maxsum*seg[k].lazy1%MOD;
			seg[k*2+1].sum=1LL*seg[k*2+1].maxsum*seg[k].lazy1%MOD;
			seg[k*2].minsum=1LL*seg[k].lazy1*seg[k*2].psum%MOD;
			seg[k*2+1].minsum=1LL*seg[k].lazy1*seg[k*2+1].psum%MOD;
		}
		if(seg[k].lazy2)
		{
			seg[k*2].lazy2=seg[k*2+1].lazy2=seg[k].lazy2;
			seg[k*2].sum=1LL*seg[k*2].minsum*seg[k].lazy2%MOD;
			seg[k*2+1].sum=1LL*seg[k*2+1].minsum*seg[k].lazy2%MOD;
			seg[k*2].maxsum=1LL*seg[k].lazy2*seg[k*2].psum%MOD;
			seg[k*2+1].maxsum=1LL*seg[k].lazy2*seg[k*2+1].psum%MOD;
		}
	}
	seg[k].lazy1=seg[k].lazy2=0;
}
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r; seg[k].sum=seg[k].minsum=seg[k].maxsum=0; seg[k].lazy1=seg[k].lazy2=0;
	if(l==1) seg[k].psum=s[r-1]; else seg[k].psum=(s[r-1]-s[l-2]+MOD)%MOD;
	if(l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
}
void update(int type,int k,int l,int r,int x)
{
	if(seg[k].l>r||seg[k].r<l) return;
	if(seg[k].l>=l&&seg[k].r<=r)
	{
		if(type==1)
		{
			seg[k].sum=1LL*seg[k].maxsum*x%MOD;
			seg[k].minsum=1LL*seg[k].psum*x%MOD;
			seg[k].lazy1=x;
		}
		else
		{
			seg[k].sum=1LL*seg[k].minsum*x%MOD;
			seg[k].maxsum=1LL*seg[k].psum*x%MOD;
			seg[k].lazy2=x;
		}
		return;
	}
	Lazy(k);
	update(type,k*2,l,r,x);update(type,k*2+1,l,r,x);
	seg[k].minsum=(seg[k*2].minsum+seg[k*2+1].minsum)%MOD;
	seg[k].maxsum=(seg[k*2].maxsum+seg[k*2+1].maxsum)%MOD;
	seg[k].sum=(seg[k*2].sum+seg[k*2+1].sum)%MOD;
}
int query(int k,int l,int r)
{
	if(seg[k].l>r||seg[k].r<l) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].sum;
	Lazy(k);
	return (query(k*2,l,r)+query(k*2+1,l,r))%MOD;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&a[st[t-1]]>=a[i]) t--;
		minL[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&a[st[t-1]]<=a[i]) t--;
		maxL[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	//for(int i=1;i<=n;i++) printf("%d %d\n",minL[i],maxL[i]);
	p[0]=1;p[1]=1;
	for(int i=2;i<=n;i++)
		p[i]=2LL*p[i-1]%MOD;
	s[0]=1;
	for(int i=1;i<=n;i++)
		s[i]=(p[i]+s[i-1])%MOD;
	int ans=0;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		update(1,1,maxL[i]+1,i,a[i]);
		update(2,1,minL[i]+1,i,a[i]);
		ans=(ans+1LL*query(1,1,i)*p[n-i]%MOD)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}