#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<int(n);i++)
#define Rep(i,n) for (int i=1; i<=int(n);i++)
#define range(x) begin(x),end(x)
#define MAXN 50005
#define MAXW 20005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,k;
const ll INF = 1ll * MAXN * MAXW;
struct MDST
{
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > heap[2*MAXN];
    ll shift[2*MAXN];
    int fa[2*MAXN],vis[2*MAXN],cnt;
    ll ans;
    void init(int n)
    {
        cnt=0;
        for(int i=1;i<=n;i++) 
        {
            vis[i]=0;
            shift[i]=0;
            while(heap[i].size()) heap[i].pop();
        }
    }
    int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
    void unite(int x,int y)
    {
        x=find(x); y=find(y);
        if(x==y) return;
        fa[y]=x;
        if(heap[x].size()<heap[y].size())
        {
            swap(heap[x],heap[y]);
            swap(shift[x],shift[y]);
        }
        while(heap[y].size())
        {
            auto p=heap[y].top();heap[y].pop();
            heap[x].emplace(p.first-shift[y]+shift[x],p.second);
        }
    }
    void addedge(int u,int v,ll w)
    {
        heap[v].emplace(w,u);
    }
    void run(int n,int rt)
    {
        ans=0; cnt=0;
        iota(fa,fa+n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(find(i)!=find(rt))
            {
                int u=find(i);
                stack<int,vector<int> >s;
                while(find(u)!=find(rt))
                {
                    if(vis[u])
                    {
                        while(s.top()!=u) {vis[s.top()]=0; unite(u,s.top()); s.pop();}
                    }
                    else{vis[u]=1; s.push(u);}
                    while(heap[u].size())
                    {
                        ans+=heap[u].top().first-shift[u];
                        shift[u]=heap[u].top().first;
                        if(find(heap[u].top().second)!=u) break;
                        heap[u].pop();
                    }
                    if(heap[u].empty()) assert(0);
                    if(heap[u].top().second==rt) cnt++;
                    u=find(heap[u].top().second);
                }
                while(s.size()) {vis[s.top()]=0; unite(rt,s.top()); s.pop();}
            }
        }
    }
}mdst;
//maxn=2.5e18
int u[MAXN],v[MAXN],w[MAXN];
int check(ll x)
{
    mdst.init(n+1);
    for(int i=1;i<=m;i++) mdst.addedge(u[i],v[i],w[i]);
    for(int i=1;i<=n;i++) mdst.addedge(n+1,i,x);
    mdst.run(n+1,n+1);
    return mdst.cnt;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]); 
    ll l=-1,r=INF;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(check(mid)<=k) r=mid; else l=mid;
    }
    int x=check(r);   
    printf("%lld\n",mdst.ans-1LL*x*r);
    return 0;
}