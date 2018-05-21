#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q,a[MAXN],id[MAXN];
struct node
{
	ll l,r,val,pos;
}seg[4*MAXN];
void build(ll k,ll l,ll r)
{
	seg[k].l=l;
	seg[k].r=r;
	if(l==r) 
	{
		id[l]=k;
		seg[k].val=a[l];
		seg[k].pos=l;
		return;
	}
	ll mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	if(seg[k*2].val>=seg[k*2+1].val)
	{
		seg[k].val=seg[k*2].val;
		seg[k].pos=seg[k*2].pos;
	}
	else
	{
		seg[k].val=seg[k*2+1].val;
		seg[k].pos=seg[k*2+1].pos;
	}
}
void update(ll i,ll x)
{
	ll k=id[i];
	seg[k].val=x;
	while(k>1)
	{
		k=k/2;
		if(seg[k*2].val>=seg[k*2+1].val)
		{
			seg[k].val=seg[k*2].val;
			seg[k].pos=seg[k*2].pos;
		}
		else
		{
			seg[k].val=seg[k*2+1].val;
			seg[k].pos=seg[k*2+1].pos;
		}
	}
}
P query(ll k,ll l,ll r)
{
	if(seg[k].l>r||seg[k].r<l) return P(-INF,0);
	if(seg[k].l>=l&&seg[k].r<=r) return P(seg[k].val,seg[k].pos);
	P p=query(k*2,l,r);
	P q=query(k*2+1,l,r);
	if(p.F>=q.F) return p; else return q;
}
int main()
{
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);
	vector<P> save;
	for(ll i=0;i<q;i++)
	{
		ll type;
		scanf("%lld",&type);
		if(type==1)
		{
			ll pos,val;
			scanf("%lld%lld",&pos,&val);
			update(pos,val);
		}
		else
		{
			ll l,r;
			scanf("%lld%lld",&l,&r);
			ll len=r-l+1;
			if(len<3)
			{
				puts("0");
				continue;
			}
			else
			{
				save.clear();
				P p=query(1,l,r);
				save.push_back(p);
				ll f1=p.F;
				update(p.S,0);
				p=query(1,l,r);
				save.push_back(p);
				ll f2=p.F;
				update(p.S,0);
				len-=2;
				ll f3;
				while(len>0)
				{
					p=query(1,l,r);
					save.push_back(p);
					update(p.S,0);
					f3=p.F;
					if(f3+f2>f1) break;
					len--;
					f1=f2;
					f2=f3;
				}
				if(len==0) puts("0"); else printf("%lld\n",f1+f2+f3);
				for(ll j=0;j<save.size();j++)
					update(save[j].S,save[j].F);
			}
		}
	}
	return 0;
}