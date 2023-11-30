#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define F first
#define S second
#define ls t[o].ch[0]
#define rs t[o].ch[1]
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
struct node
{
    int ch[2],sz,pri;
    ll val,sum,maxx,secx,maxnum,lazy,add;
};
namespace treap
{
    int root,tot;
    node t[MAXN];
    void pushdown(int o);
    int newnode(int val)
    {
        tot++;
        t[tot].val=val; t[tot].ch[0]=t[tot].ch[1]=0;
        t[tot].sz=1; t[tot].pri=rng(); t[tot].add=0; t[tot].lazy=INT_MAX;
        t[tot].sum=t[tot].maxx=val; t[tot].secx=-1; t[tot].maxnum=1;
        return tot;
    }
    void pushup(int o)
    {
        if(!o) return;
        t[o].sz=1; t[o].sum=t[o].maxx=t[o].val;
        if(ls) {t[o].sz+=t[ls].sz; t[o].sum+=t[ls].sum; t[o].maxx=max(t[o].maxx,t[ls].maxx);}
        if(rs) {t[o].sz+=t[rs].sz; t[o].sum+=t[rs].sum; t[o].maxx=max(t[o].maxx,t[rs].maxx);}
        t[o].maxnum=0; t[o].secx=-1;
        if(t[o].val==t[o].maxx) t[o].maxnum=1; else t[o].secx=t[o].val;
        if(ls){
            if(t[ls].maxx==t[o].maxx) t[o].maxnum+=t[ls].maxnum; else t[o].secx=max(t[o].secx,t[ls].maxx);
            t[o].secx=max(t[o].secx,t[ls].secx);
        }
        if(rs){
            if(t[rs].maxx==t[o].maxx) t[o].maxnum+=t[rs].maxnum; else t[o].secx=max(t[o].secx,t[rs].maxx);
            t[o].secx=max(t[o].secx,t[rs].secx);
        }
    }
    void add(int o,ll v)
    {
        if(!o) return;
        if(t[o].lazy!=INT_MAX) t[o].lazy+=v; 
        t[o].add+=v; t[o].maxx+=v; 
        if(t[o].secx!=-1) t[o].secx+=v;
        t[o].sum+=t[o].sz*v;
        t[o].val+=v;
    }
    void cut_to(int o,ll v)
    {
        if(!o) return;
        if(t[o].maxx<=v) return;
        if(t[o].secx<v)
        {
            if(t[o].val==t[o].maxx) t[o].val=v;
            t[o].sum-=t[o].maxnum*(t[o].maxx-v);
            t[o].maxx=v; t[o].lazy=min(t[o].lazy,v);
            return;
        }
        pushdown(o);
        cut_to(ls,v); cut_to(rs,v);
        t[o].val=min(t[o].val,v);
        pushup(o);
    }
    void pushdown(int o)
    {
        if(!o) return;
        if(t[o].add)
        {
            add(ls,t[o].add); add(rs,t[o].add);
            t[o].add=0;
        }
        if(t[o].lazy!=INT_MAX)
        {
            cut_to(ls,t[o].lazy); cut_to(rs,t[o].lazy);
            t[o].lazy=INT_MAX;
        }
    }
    P split(int o,int cnt)
    {
        if(!o) return P(0,0);
        pushdown(o);
        if(t[ls].sz>=cnt)
        {
            P p=split(ls,cnt);
            int tl=p.F,tr=p.S;
            ls=tr; pushup(o); 
            return P(tl,o);
        }
        else
        {
            P p=split(rs,cnt-t[ls].sz-1);
            int tl=p.F,tr=p.S;
            rs=tl; pushup(o);             
            return P(o,tr);
        }
    }
    int merge(int x,int y)
    {
        if(!x||!y) return x+y;
        if(t[x].pri<t[y].pri)
        {
            pushdown(x);
            t[x].ch[1]=merge(t[x].ch[1],y);
            pushup(x);
            return x;
        }
        else
        {
            pushdown(y);
            t[y].ch[0]=merge(x,t[y].ch[0]);
            pushup(y);
            return y;
        }
    }
    void ins(int val)
    {
       root=merge(root,newnode(val));
    }
};
using namespace treap;
int n,q;
string str;
int main()
{
    scanf("%d%d",&n,&q);
    int val; scanf("%d",&val);
    root=newnode(val);
    for(int i=2;i<=n;i++) 
    {
        scanf("%d",&val);
        ins(val);
    }
    int type,l,r,h,x;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d%d",&type,&l,&r);
        if(type==1)
        {
            scanf("%d",&h);
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            cut_to(q.F,h);
            root=merge(p.F,merge(q.F,q.S));
        }
        else if(type==2)
        {
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            root=merge(p.F,merge(q.S,q.F));
        }
        else
        {
            scanf("%d",&x);
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            add(q.F,x);
            root=merge(p.F,merge(q.F,q.S));
        }
        printf("%lld\n",t[root].sum);
    }
    return 0;
}
