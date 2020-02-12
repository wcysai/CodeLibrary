#include<bits/stdc++.h>
#define MAXN 250005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,t;
vector<int> G[MAXN];
bool centroid[MAXN];
int sz[MAXN],a[MAXN];
ll ans;
struct node
{
    ll psum,sum,len;
};
vector<node> tmp;
P st[MAXN];
bool qu=0;
struct line
{
	long long m,b;
	mutable function<const line*()> succ;
	bool operator<(const line& rhs) const
	{
		if (!qu) return m<rhs.m;
		const line* s=succ();
		if (!s)
		return 0;
		return b-s->b<rhs.m*(s->m-m);
	}
};
struct hull:public multiset<line>
{
	bool bad(iterator y)
	{
		auto z=next(y);
		if (y==begin())
		{
			if (z==end())
			return 0;
			return (y->m==z->m && y->b<=z->b);
		}
		auto x=prev(y);
		if (z==end())
		return (y->m==x->m && y->b<=x->b);
		return 1.0*(x->b-y->b)*(z->m-y->m)>=1.0*(y->b-z->b)*(y->m-x->m);
	}
	void add(long long m,long long b)
	{
		auto it=insert({m,b});
		it->succ=[=] { return (next(it)==end())? 0:&*next(it); };
		if (bad(it))
		{
			erase(it);
			return;
		}
		while (next(it)!=end() && bad(next(it))) erase(next(it));
		while (it!=begin() && bad(prev(it))) erase(prev(it));
	}
	long long eval(long long x)
	{
		if (empty()) return -(1LL<<60);
		qu=1;line l=*lower_bound((line){x,0});qu=0;
		return l.m*x+l.b;
	}
}h;
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getdeep(int v,int p,ll psum,ll sum,ll len)//enumerate path
{
    tmp.push_back((node){psum,sum,len});
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        getdeep(to,v,psum+a[to]*(len+1),sum+a[to],len+1);
    }
}
void solve(int v)
{
    h.clear();
    centroid[v]=true;
    ans=max(ans,1LL*a[v]);
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        tmp.clear();
        getdeep(to,v,a[to],a[to],1);
        for(auto p:tmp) 
        {
            ans=max(ans,p.psum+1LL*a[v]*(p.len+1));
            ans=max(ans,p.sum*(p.len+1)-p.psum+p.sum+a[v]);
            ans=max(ans,p.sum*(p.len+1)-p.psum+h.eval(p.len+1));
        }
        for(auto p:tmp) h.add(p.sum+a[v],p.psum);
    }
    h.clear();
    for(int i=(int)G[v].size()-1;i>=0;i--)
    {
        int to=G[v][i];
        if(centroid[to]) continue;
        tmp.clear();
        getdeep(to,v,a[to],a[to],1);
        for(auto p:tmp) ans=max(ans,p.sum*(p.len+1)-p.psum+h.eval(p.len+1));
        for(auto p:tmp) h.add(p.sum+a[v],p.psum);
    }
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        int rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
void go()
{
    ans=0;
    int rt=getroot(1,0,n).S;
    solve(rt);
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    go();
    return 0;
}

