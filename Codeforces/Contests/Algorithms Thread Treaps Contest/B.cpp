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
int MOD[2]={1000000007,1000000009};
int BASE[2]={19260817,19990303};
P p[MAXN];
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
struct node
{
    int ch[2],sz,pri;
    char c; 
    P hash; P rhash;
};
namespace treap
{
    int root,tot;
    node t[MAXN];
    void init()
    {
        root=0;
        t[root].ch[0]=t[root].ch[1]=0;
        tot=0;
    }
    int newnode(char c)
    {
        tot++;
        t[tot].ch[0]=t[tot].ch[1]=0;
        t[tot].sz=1; t[tot].pri=rng(); t[tot].c=c; 
        t[tot].hash=t[tot].rhash=P((int)(c-'a'+1),(int)(c-'a'+1));
        return tot;
    }
    void pushup(int o)
    {
        t[o].sz=t[ls].sz+t[rs].sz+1;
        int rsz=t[rs].sz; int lsz=t[ls].sz;
        t[o].hash.F=(1LL*t[ls].hash.F*p[rsz+1].F+1LL*(int)(t[o].c-'a'+1)*p[rsz].F+t[rs].hash.F)%MOD[0];
        t[o].hash.S=(1LL*t[ls].hash.S*p[rsz+1].S+1LL*(int)(t[o].c-'a'+1)*p[rsz].S+t[rs].hash.S)%MOD[1];
        t[o].rhash.F=(1LL*t[rs].rhash.F*p[lsz+1].F+1LL*(int)(t[o].c-'a'+1)*p[lsz].F+t[ls].rhash.F)%MOD[0];
        t[o].rhash.S=(1LL*t[rs].rhash.S*p[lsz+1].S+1LL*(int)(t[o].c-'a'+1)*p[lsz].S+t[ls].rhash.S)%MOD[1];
    }
    P split(int o,int cnt)
    {
        if(!o) return P(0,0);
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
            t[x].ch[1]=merge(t[x].ch[1],y);
            pushup(x);
            return x;
        }
        else
        {
            t[y].ch[0]=merge(x,t[y].ch[0]);
            pushup(y);
            return y;
        }
    }
    void ins(char ch)
    {
        root=merge(root,newnode(ch));
    }
};
using namespace treap;
int n,q;
string str;
int main()
{
    p[0]=P(1,1);
    for(int i=1;i<=300000;i++) p[i]=P(1LL*BASE[0]*p[i-1].F%MOD[0],1LL*BASE[1]*p[i-1].S%MOD[1]);
    scanf("%d%d",&n,&q);
    init();
    cin>>str;
    for(int i=1;i<=n;i++) ins(str[i-1]);
    for(int i=0;i<n;i++)
    {
        int type,l,r,pos;
        string s;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&l,&r);
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            root=merge(p.F,q.S);
        }
        else if(type==2)
        {
            cin>>s;
            scanf("%d",&pos);
            P p=split(root,pos-1);
            root=merge(p.F,merge(newnode(s[0]),p.S));
        }
        else
        {
            scanf("%d%d",&l,&r);
            P p=split(root,l-1);
            P q=split(p.S,r-l+1);
            if(t[q.F].hash==t[q.F].rhash) puts("yes"); else puts("no");
            root=merge(p.F,merge(q.F,q.S));
        }
    }
    return 0;
}
