#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k,x,y;
vector<int> dis;
int type[MAXN],qx[MAXN],qy[MAXN],v[MAXN];
struct segtree
{
    ll sum[4*MAXM],lazy[4*MAXN];
    int len[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void add(int k,ll x)
    {
        sum[k]+=x*len[k];
        lazy[k]+=x;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            len[k]=dis[l+1]-dis[l];
            sum[k]=0;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        len[k]=len[k*2]+len[k*2+1];
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    pair<ll,int> query(int k,int l,int r,int x,int y,ll rem)
    {
        if(l>y||x>r) return make_pair(rem,r+1);
        if(l>=x&&r<=y&&sum[k]<=rem) return make_pair(rem-sum[k],r+1);
        if(l==r) return make_pair(rem,l);
        pushdown(k);
        int mid=(l+r)/2;
        auto p=query(k*2,l,mid,x,y,rem);
        if(p.S!=mid+1)return p;
        else return query(k*2+1,mid+1,r,x,y,p.F);
    }
}seg;
set<P> s;
int main()
{
    scanf("%d",&q);
    memset(ask,false,sizeof(ask));
    for(int i=0;i<q;i++)
    {
        scanf("%d",&type[i]);
        scanf("%d",&qx[i]);
        if(type[i]!=2) scanf("%d",&qy[i]);
        if(type[i]==3) scanf("%d",&v[i]);
        dis.push_back(qx[i]);
        if(type[i]==3) dis.push_back(qy[i]-1);
    }
    sort(dis.begin(),dis.end());
    dis.push_back(INF+1);
    dis.push_back(0);
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=0;i<q;i++)
    {
        qx[i]=lower_bound(dis.begin(),dis.end(),qx[i])-dis.begin();
        if(type[i]==3) qy[i]=lower_bound(dis.begin(),dis.end(),qy[i]-1)-dis.begin();
    }
    int sz=(int)dis.size();
    s.insert(P(0,0)); s.insert(P(sz-1,0));
    seg.build(1,0,sz-1);
    for(int i=0;i<q;i++)
    {
        if(type[i]==1)
        {
            s.insert(P(qx[i],qy[i]));
            auto it=s.find(P(qx[i],qy[i]));
            int nxt=(++it)->F; it--;
            int val=qy[i]-((--it)->S);
            seg.update(1,0,sz-1,qx[i],nxt-1,val);
        }
        else if(type[i]==2)
        {
            auto it=s.find(P(qx[i],qy[i]));
            int nxt=(++it)->F; it--;
            int val=qy[i]-((--it)->S); it++;
            seg.update(1,0,sz-1,qx[i],nxt-1,-val);
            s.erase(it);
        }
        else
        {
            auto p=seg.query(1,0,sz-1,qx[i],qy[i],v[i]);
            if(p.S==qy[i]+1) puts("-1");
            else printf("%d\n",)

        }
    }
    return 0;
}

