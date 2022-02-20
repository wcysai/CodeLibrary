#include<bits/stdc++.h>
#define MAXN 500005
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
    int ch[2],sz,val,pri,sum;
    int pre[2],suf[2],ans[2];
    int rev,asgn,flip;
};
namespace treap
{
    int root,tot;
    node t[MAXN];
    void init()
    {
        root=0;
        t[root].ch[0]=t[root].ch[1]=0;
        t[root].sz=t[root].val=t[root].sum=t[root].pri=t[root].rev=t[root].flip=0;
        t[root].pre[0]=t[root].pre[1]=t[root].suf[0]=t[root].suf[1]=t[root].ans[0]=t[root].ans[1]=0;
        t[root].asgn=-1;
        tot=0;
    }
    int newnode(int val)
    {
        tot++;
        t[tot].val=val; t[tot].ch[0]=t[tot].ch[1]=0;
        t[tot].sz=1; t[tot].pri=rng(); 
        t[tot].rev=t[tot].flip=0; t[tot].asgn=-1; t[tot].sum=val;
        t[tot].pre[val]=t[tot].suf[val]=t[tot].ans[val]=1;
        t[tot].pre[val^1]=t[tot].suf[val^1]=t[tot].ans[val^1]=0;
        return tot;
    }
    void assign(int o,int v)
    {
        if(!o) return;
        t[o].sum=(v?t[o].sz:0); t[o].asgn=v; t[o].val=v;
        t[o].rev=t[o].flip=0;
        t[o].pre[v]=t[o].suf[v]=t[o].ans[v]=t[o].sz;
        t[o].pre[v^1]=t[o].suf[v^1]=t[o].ans[v^1]=0;
    }
    void flip(int o)
    {
        if(!o) return;
        t[o].flip^=1; 
        t[o].val^=1;
        t[o].sum=t[o].sz-t[o].sum;
        swap(t[o].pre[0],t[o].pre[1]); swap(t[o].suf[0],t[o].suf[1]);
        swap(t[o].ans[0],t[o].ans[1]);
    }
    void rever(int o)
    {
        if(!o) return;
        t[o].rev^=1; 
        swap(ls,rs);
        swap(t[o].pre[0],t[o].suf[0]); swap(t[o].pre[1],t[o].suf[1]);
    }
    void pushup(int o)
    {
        if(!o) return;
        t[o].sz=t[ls].sz+t[rs].sz+1;
        t[o].sum=t[ls].sum+t[rs].sum+t[o].val;
        for(int i=0;i<2;i++)
        {
            t[o].pre[i]=t[o].suf[i]=t[o].ans[i]=(t[o].val==i?1:0);
            t[o].ans[i]=max(max(t[o].ans[i],t[ls].ans[i]),t[ls].suf[i]+t[o].pre[i]);
            if(t[ls].pre[i]==t[ls].sz) t[o].pre[i]=t[ls].pre[i]+t[o].pre[i]; else t[o].pre[i]=t[ls].pre[i];
            if(t[o].suf[i]==1) t[o].suf[i]=t[ls].suf[i]+1; else t[o].suf[i]=0;
            t[o].ans[i]=max(max(t[o].ans[i],t[rs].ans[i]),t[o].suf[i]+t[rs].pre[i]);
            if(t[o].pre[i]==t[ls].sz+1) t[o].pre[i]=t[o].pre[i]+t[rs].pre[i]; 
            if(t[rs].suf[i]==t[rs].sz) t[o].suf[i]=t[rs].suf[i]+t[o].suf[i]; else t[o].suf[i]=t[rs].suf[i];
        }
    }
    void pushdown(int o)
    {
        if(!o) return;
        if(t[o].asgn!=-1)
        {
            assign(ls,t[o].asgn); assign(rs,t[o].asgn);
            t[o].asgn=-1;
        }
        if(t[o].flip)
        {
            flip(ls); flip(rs); t[o].flip=0;
        }
        if(t[o].rev)
        {
            rever(ls); rever(rs); t[o].rev=0;
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
    init();
    cin>>str;
    for(int i=0;i<n;i++) ins((int)(str[i]-'0'));
    int type,l,r;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&type,&l,&r);
        if(type==1)
        {
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            flip(q.F);
            root=merge(p.F,merge(q.F,q.S));
        }
        else if(type==2)
        {
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            rever(q.F);
            root=merge(p.F,merge(q.F,q.S));
        }
        else
        {
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            int val=t[q.F].sz-t[q.F].sum;
            P r=split(q.F,val);
            assign(r.F,0); assign(r.S,1);
            root=merge(p.F,merge(merge(r.F,r.S),q.S));
        }
        printf("%d\n",max(t[root].ans[0],t[root].ans[1]));
    }
    return 0;
}
