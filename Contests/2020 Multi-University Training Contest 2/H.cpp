#include<bits/stdc++.h>
#define MAXN 100005
#define INF 9000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int T,n,m,x,y;
int a[2*MAXN]; 
ll b[2*MAXN];
int num;
vector<P> h[4*MAXN];
int pos[4*MAXN];
bool cmp(P x,P y)
{
    if(x.F!=y.F) return x.F>y.F;
    return x.S<y.S;
}
int t;
void build(int k,int l,int r)
{
    h[k].clear();
    if(l==r) return;
    int mid=(l+r)/2;
    build(k*2,l,mid); build(k*2+1,mid+1,r);
}
void add_func(int k,int l,int r,int x,int y,int a,ll b)
{
    if(x>r||l>y) return;
    if(l>=x&&r<=y)
    {
        h[k].push_back(P(a,b));
        return;
    }
    int mid=(l+r)/2;
    add_func(k*2,l,mid,x,y,a,b);add_func(k*2+1,mid+1,r,x,y,a,b);
}
ll eval(P p,int x)
{
    int a=p.F; ll b=p.S;
    return 1LL*(x-a)*(x-a)*(x-a)*(x-a)+b;
}
void sort_all(int k,int flag)
{
    if(!flag)sort(h[k].begin(),h[k].end()); else sort(h[k].begin(),h[k].end(),cmp);
    pos[k]=0;
}
void solve(int k,int l,int r,int flag)
{
    sort_all(k,flag);
    if(l==r) return;
    int mid=(l+r)/2;
    solve(k*2,l,mid,flag); solve(k*2+1,mid+1,r,flag);
}
ll query_hull(int k,int x,int flag)
{
    if(!flag)
    {
        if(!h[k].size()||h[k][pos[k]].F>x) return INF;
        while(pos[k]+1<(int)h[k].size()&&h[k][pos[k]+1].F<=x&&eval(h[k][pos[k]+1],x)<=eval(h[k][pos[k]],x)) pos[k]++;
        return eval(h[k][pos[k]],x);
    }
    else
    {
        if(!h[k].size()||h[k][pos[k]].F<x) return INF;
        while(pos[k]+1<(int)h[k].size()&&h[k][pos[k]+1].F>=x&&eval(h[k][pos[k]+1],x)<=eval(h[k][pos[k]],x)) pos[k]++;
        return eval(h[k][pos[k]],x);
    }
}
ll query(int k,int l,int r,int p,int x,int flag)
{
    ll cur=query_hull(k,x,flag);
    if(l==r) return cur;
    int mid=(l+r)/2;
    ll res;
    if(p<=mid) res=query(k*2,l,mid,p,x,flag); else res=query(k*2+1,mid+1,r,p,x,flag);
    return min(res,cur);
}
map<int,int> mp;
vector<pair<P,int> > q;
ll ans[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        mp.clear(); q.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%lld",&a[i],&b[i]);
            mp[i]=1;
        }
        build(1,1,m);
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            int type,t,x;
            scanf("%d",&type);
            if(type==3)
            {
                scanf("%d",&x);
                q.push_back(make_pair(P(x,i),++cnt));
                continue;
            }
            if(type==1)
            {
                ++n;
                scanf("%d%lld",&a[n],&b[n]);
                mp[n]=i;
            }
            else
            {
                scanf("%d",&t);
                add_func(1,1,m,mp[t],i-1,a[t],b[t]);
                mp[t]=-1;
            }
        }
        for(auto p:mp) 
            if(p.S!=-1) 
                add_func(1,1,m,p.S,m,a[p.F],b[p.F]);
        solve(1,1,m,0);
        sort(q.begin(),q.end());
        for(auto x:q) ans[x.S]=query(1,1,m,x.F.S,x.F.F,0);
        solve(1,1,m,1);
        reverse(q.begin(),q.end());
        for(auto x:q) ans[x.S]=min(ans[x.S],query(1,1,m,x.F.S,x.F.F,1));
        for(int i=1;i<=(int)q.size();i++) if(ans[i]==INF) puts("-1"); else printf("%lld\n",ans[i]);
    }
    return 0;
}

