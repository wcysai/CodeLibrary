#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN],b[MAXN];
int p[MAXN],r[MAXN],sz[MAXN];
int ans[MAXN];
struct update
{
    int x,y;
    bool addrk;
};
struct query
{
    int x,y,z,id;
};
update st[MAXN];
int t;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        sz[i]=1;
    }
}
int find(int x)
{
   while(p[x]!=x) x=p[x];
   return x;
}
bool unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return false;
    if(r[x]<r[y])
    {
        p[x]=y;
        sz[y]+=sz[x];
        st[t++]=(update){x,y,false};
    }
    else
    {
        p[y]=x; sz[x]+=sz[y];
        st[t++]=(update){y,x,r[x]==r[y]};
        if(r[x]==r[y]) r[x]++;
    }
    return true;
}
void undo()
{
    assert(t);
    int x=st[t-1].x,y=st[t-1].y;
    p[x]=x;p[y]=y;
    sz[y]-=sz[x];
    if(st[t-1].addrk) r[y]--;
    t--;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void solve(int l,int r,vector<query> &v)
{
    if(l==r)
    {
        for(auto p:v) ans[p.id]=l;
        return;
    }
    vector<query> lhs,rhs;
    int mid=(l+r)/2,cnt=0;
    for(int i=l;i<=mid;i++) if(unite(a[i],b[i])) cnt++;
    for(auto p:v)
    {
        int x=find(p.x),y=find(p.y);
        int res=(same(x,y)?sz[x]:sz[x]+sz[y]);
        if(p.z<=res) lhs.push_back(p); else rhs.push_back(p);
    }
    for(int i=0;i<cnt;i++) undo();
    solve(l,mid,lhs);
    for(int i=l;i<=mid;i++) unite(a[i],b[i]);
    solve(mid+1,r,rhs);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
    scanf("%d",&q);
    vector<query> v;
    for(int i=1;i<=q;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v.push_back((query){x,y,z,i});
    }
    init(n);
    solve(1,m,v);
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
