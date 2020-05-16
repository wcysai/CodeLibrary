#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 800005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,l;
int a[MAXN];
int suma[MAXN],sumb[MAXN];
int cnt[MAXN];
vector<int> dis;
struct node
{
    int ans,mini,maxi,lazy1,lazy2;
    //f(i): sumA(i)-sumB(i+k)
    //g(i): sumA(i)-sumB(i-k)
    //minimize f(r)-g(l)
    //lazy1 for f, lazy2 for g
    void merge(node &lhs,node &rhs)
    {
        if(lhs.mini==INF) *this=rhs;
        if(rhs.mini==INF) *this=lhs;
        mini=min(lhs.mini,rhs.mini);
        maxi=max(lhs.maxi,rhs.maxi);
        ans=min(min(lhs.ans,rhs.ans),rhs.mini-lhs.maxi);
    }
    void st_dummy()
    {
        mini=INF;
    }
    void st(int val)
    {
        ans=mini=maxi=val;
    }
    void clear()
    {
        lazy1=0; lazy2=0;
    }
    void add1(int val)
    {
        lazy1+=val;
        mini+=val; 
        ans+=val;
    }
    void add2(int val)
    {
        lazy2+=val;
        maxi+=val;
        ans-=val;
    }
};
struct segtree
{
    node val[4*MAXN];
    void pushup(int k)
    {
        val[k].merge(val[k*2],val[k*2+1]);
    }
    void pushdown(int k)
    {
        int x=val[k].lazy1;
        for(int i=k*2;i<=k*2+1;i++)
            val[i].add1(x);
        int y=val[k].lazy2;
        for(int i=k*2;i<=k*2+1;i++)
            val[i].add2(y);
        val[k].clear();
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            val[k].st(0);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update1(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            val[k].add1(v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update1(k*2,l,mid,x,y,v); update1(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void update2(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            val[k].add2(v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update2(k*2,l,mid,x,y,v); update2(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query()
    {
        return val[1].ans;
    }
    int get_pos(int k,int l,int r)
    {
        if(l==r) return l;
        pushdown(k);
        int mid=(l+r)/2;
        if(val[k*2+1].mini-val[k*2].maxi>0) return get_pos(k*2,l,mid);
        else return get_pos(k*2+1,mid+1,r);
    }
}seg;
void changeA(int x,int val)
{
    int id=lower_bound(dis.begin(),dis.end(),x)-dis.begin()+1;
    seg.update1(1,1,m,id,m,val);
    seg.update2(1,1,m,id,m,val);
}
void changeB(int x,int val)
{
    int id=lower_bound(dis.begin(),dis.end(),x-k)-dis.begin()+1;
    seg.update1(1,1,m,id,m,-val);
    id=lower_bound(dis.begin(),dis.end(),x+k)-dis.begin()+1;
    seg.update2(1,1,m,id,m,-val);
}
int main()
{
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]);
        dis.push_back(a[i]-1);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    m=(int)dis.size();
    seg.build(1,1,m);
    for(int i=1;i<=l;i++) changeA(a[i],1);
    for(int i=1;i<=n;i++) changeB(a[i],1);
    printf("%d\n",(int)seg.query());
    for(int i=1;i<=l;i++)
    {
        changeA(a[i],-1);
    }
    return 0;
}