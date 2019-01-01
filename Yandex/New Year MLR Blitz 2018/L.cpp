#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct node
{
	ll l,r,num,res;
}seg[4*MAXN];
char s[MAXN];
ll n,k,p,a[MAXN],ans[MAXN];
void build(ll k,ll l,ll r)
{
	seg[k].l=l;seg[k].r=r;
	if(l==r)
	{
		seg[k].num=1;
		seg[k].res=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
	seg[k].num=seg[k*2].num+seg[k*2+1].num;
	seg[k].res=min(seg[k*2].res,seg[k*2+1].res);
}
ll get(ll k,ll l,ll r,ll p)
{
	if(seg[k].num<=p) return seg[k].res;
	ll mid=(l+r)/2;
	if(seg[k*2].num<p) return min(seg[k*2].res,get(k*2+1,mid+1,r,p-seg[k*2].num));
	return get(k*2,l,mid,p);
}
ll del(ll k,ll l,ll r,ll p)
{
	if(l==r)
	{
		seg[k].num=0;seg[k].res=INF;
		return 0;
	}
	ll mid=(l+r)/2,ans=0;
	if(seg[k*2].res>p) ans=seg[k*2].num+del(k*2+1,mid+1,r,p);
	else ans=del(k*2,l,mid,p);
	seg[k].num=seg[k*2].num+seg[k*2+1].num;
	seg[k].res=min(seg[k*2].res,seg[k*2+1].res);
	return ans;
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
	scanf("%lld",&k);
	for(ll i=1;i<=n;i++) a[i]=s[i]-'a';
	build(1,1,n);
	for(ll i=1;i<=n;i++)
	{
		ll v=get(1,1,n,k+1);
		ll p=del(1,1,n,v);
		ans[i]=v;
		k-=p;
	}
	for(ll i=1;i<=n;i++) printf("%c",(char)ans[i]+'a');
	return 0;
}

