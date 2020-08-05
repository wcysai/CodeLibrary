#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,x;
struct segtree
{
    int sum[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            sum[k]=1;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p)
    {
        if(l==r)
        {
            sum[k]=0;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p); else update(k*2+1,mid+1,r,p);
        pushup(k);
    }
    int query(int k,int l,int r,int p)
    {
        if(l==r) return l;
        int mid=(l+r)/2;
        if(sum[k*2]>=p) return query(k*2,l,mid,p); else return query(k*2+1,mid+1,r,p-sum[k*2]);
    }
}seg;
int p[MAXN],s[MAXN];
vector<int> q;
vector<int> cont(vector<int> p,vector<int> q)
{
    vector<int> tmp;
    tmp.resize(n);
    for(int i=0;i<n;i++) tmp[i]=p[q[i]-1];
    return tmp;
}
vector<int> _pow(vector<int> p,int k)
{
    vector<int> id; id.resize(n);
    for(int i=0;i<n;i++) id[i]=i+1;
    while(k)
    {
        if(k&1) id=cont(id,p);
        p=cont(p,p);
        k>>=1;
    }
    return id;
}
void solve_josephus(int k)
{
    seg.build(1,1,n);
    q.clear();
    int id=0;
    for(int i=1;i<=n;i++)
    {
        int nxt=(id+k)%(n-i+1);
        if(nxt==0) nxt=n-i+1;
        int pos=seg.query(1,1,n,nxt);
        q.push_back(pos);
        seg.update(1,1,n,pos);
        id=nxt-1;
    }
}
vector<int> res;
int main()
{
    scanf("%d%d",&n,&m);
    res.resize(n);
    for(int i=0;i<n;i++) res[i]=i+1;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&k,&x);
        solve_josephus(k);
        vector<int> tmp=_pow(q,x);
        res=cont(res,tmp);
    }
    for(int i=0;i<n;i++) printf("%d ",res[i]);
}