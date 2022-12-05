#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int val[MAXN];
set<P> s;
vector<P> todel,toadd;
P find_interval(int pos)
{
    auto it=s.lower_bound(P(pos+1,0));
    if(it!=s.begin())
    {
        it--;
        if(it->F<=pos&&it->S>=pos) return *it;
    }
    return P(-1,-1);
}
struct segtree
{
    int mini[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v)
    {
        mini[k]+=v;
        lazy[k]+=v;
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            mini[k]=-l;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void pushdown(int k)
    {
        if(lazy[k])
        {
            for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
            lazy[k]=0;
        }
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        int mid=(l+r)/2;
        pushdown(k);
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int find_first(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return -1;
        if(mini[k]>v) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        pushdown(k);
        int res=find_first(k*2,l,mid,x,y,v);
        if(res!=-1) return res; else return find_first(k*2+1,mid+1,r,x,y,v); 
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        int mid=(l+r)/2;
        pushdown(k);
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
void extend(P p,int cnt)
{
    while(cnt)
    {
        P q=find_interval(p.S+1);
        if(q.F!=-1)
        {
            s.erase(s.find(q)); todel.push_back(q);
            p.S=q.S;
        }
        else {p.S++; cnt--;}
    }
    s.insert(p);
    toadd.push_back(p);
}
void shrink(P p)
{
    for(int i=1;i<=2;i++)
    {
        int sum=seg.query(1,0,1000000,p.F-1,p.F-1);
        //printf("sum=%d\n",sum);
        int nxtpos=seg.find_first(1,0,1000000,p.F,p.S,sum-1);
        assert(nxtpos!=-1);
        if(nxtpos!=p.F)
        {
            s.insert(P(p.F,nxtpos-1));
            toadd.push_back(P(p.F,nxtpos-1));
        }
        p.F=nxtpos+1;
    }
    if(p.F<=p.S)
    {
        s.insert(p);
        toadd.push_back(p);
    }
}
int main()
{
    scanf("%d",&n);
    seg.build(1,0,1000000);
    for(int i=1;i<=n;i++) 
    {
        todel.clear(); toadd.clear();
        scanf("%d",&a[i]);
        val[a[i]]^=1;
        if(val[a[i]]==1)//add
        {
            seg.update(1,0,1000000,a[i],1000000,2);
            int cnt=1;
            P p=find_interval(a[i]);
            if(p.F!=-1) {s.erase(s.find(p)); todel.push_back(p); cnt=2;}
            else p=P(a[i],a[i]);
            extend(p,cnt);
        }
        else
        {
            seg.update(1,0,1000000,a[i],1000000,-2);
            P p=find_interval(a[i]);
            if(p.F!=-1) {s.erase(s.find(p)); todel.push_back(p); shrink(p);}
        }
        printf("%d\n",(int)todel.size());
        for(auto p:todel) printf("%d %d\n",p.F,p.S);
        printf("%d\n",(int)toadd.size());
        for(auto p:toadd) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

