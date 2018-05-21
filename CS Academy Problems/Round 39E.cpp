#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,x,id[MAXN];
vector<int> save[MAXN];
vector<int> ans;
struct node
{
	int l,r,num;
}seg[4*MAXN];
void build(int k,int l,int r)
{
	seg[k].l=l;seg[k].r=r;seg[k].num=0;
	if(l==r) {id[l]=k; return;}
	int mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
}
void update(int k,int x)
{
	k=id[k];
	seg[k].num=max(seg[k].num,x);
	while(k>1)
	{
		k/=2;
		seg[k].num=max(seg[k*2].num,seg[k*2+1].num);
	}
}
int query(int k,int l,int r)
{
	if(seg[k].r<l||seg[k].l>r) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].num;
	return max(query(k*2,l,r),query(k*2+1,l,r));
}
int main()
{
	scanf("%d%d",&n,&k);
	build(1,1,100000);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int pos=max(query(1,1,x-k-1),query(1,x+k+1,100000));
		update(x,pos+1);
		save[pos+1].push_back(x);
	}
	for(int i=1;i<=100000;i++)
	{
		sort(save[i].begin(),save[i].end());
		ans.insert(ans.end(),save[i].begin(),save[i].end());
	}
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}
