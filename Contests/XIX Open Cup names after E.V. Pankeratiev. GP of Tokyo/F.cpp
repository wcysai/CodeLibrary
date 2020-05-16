#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> a,b;
int tot,l[MAXN],r[MAXN];
int id[MAXN];
int rev[MAXM];
vector<int> G[MAXM];
void add_edge(int u,int v)
{
    G[u].push_back(v);
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        id[l]=k;
        rev[k]=l;
        tot=max(tot,k);
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid); build(k*2+1,mid+1,r);
    add_edge(k*2,k); add_edge(k*2+1,k);
}
void add_seg(int k,int l,int r,int x,int y,int v)
{
    if(l>y||x>r) return;
    if(l>=x&&r<=y) 
    {
        add_edge(k,v);
        return;
    }
    int mid=(l+r)/2;
    add_seg(k*2,l,mid,x,y,v); add_seg(k*2+1,mid+1,r,x,y,v);
}
int color[MAXM];
vector<int> order;
void dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<(int)G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==0) dfs_visit(to);
	}
	color[v]=2;
	order.push_back(v);
}
void toposort()
{
	memset(color,0,sizeof(color));
	for(int i=1;i<=tot;i++)
		if(color[i]==0)
			dfs_visit(i);
}
vector<int> ans;
int main()
{
    memset(rev,-1,sizeof(rev));
    scanf("%d",&n);
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        b.push_back(x);
    }
    for(int i=0;i<n;i++) res+=max(a[i]-b[i],b[i]-a[i]);
    for(int i=0;i<n;i++)
    {
        if(b[i]<a[i])
        {
            int lb=b[i]-(a[i]-b[i]),rb=a[i]-1;
            int rid=upper_bound(a.begin(),a.end(),rb)-a.begin()-1,lid=lower_bound(a.begin(),a.end(),lb)-a.begin();
            l[i]=lid; r[i]=rid;
        }
        else
        {
            int lb=a[i]+1,rb=b[i]+(b[i]-a[i])-1;
            int rid=upper_bound(a.begin(),a.end(),rb)-a.begin()-1,lid=lower_bound(a.begin(),a.end(),lb)-a.begin();
            l[i]=lid; r[i]=rid;
        }
    }
    build(1,0,n-1);
    for(int i=0;i<n;i++) add_seg(1,0,n-1,l[i],r[i],id[i]);
    toposort();
    reverse(order.begin(),order.end());
    for(auto x:order) if(rev[x]!=-1) ans.push_back(rev[x]);
    printf("%lld\n",res);
    for(auto x:ans) printf("%d ",x+1);
    puts("");
    return 0;
}