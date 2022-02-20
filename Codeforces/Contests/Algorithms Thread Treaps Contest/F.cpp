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
    int ch[2],sz,pri,fa;
    int val;
    ll sum;
};
namespace treap
{
    int root,tot;
    node t[MAXN];
    void init()
    {
        root=0;
        t[root].ch[0]=t[root].ch[1]=0; t[root].fa=0;
        tot=0;
    }
    int newnode(int val)
    {
        tot++;
        t[tot].ch[0]=t[tot].ch[1]=0;
        t[tot].sz=1; t[tot].pri=rng(); t[tot].val=t[tot].sum=val; 
        t[tot].fa=tot;
        return tot;
    }
    void pushup(int o)
    {
        if(!o) return;
        t[o].sz=t[ls].sz+t[rs].sz+1;
        t[o].sum=t[ls].sum+t[rs].sum+t[o].val;
    }
    P split(int o,int cnt)
    {
        if(!o) return P(0,0);
        if(t[ls].sz>=cnt)
        {
            P p=split(ls,cnt);
            int tl=p.F,tr=p.S;
            t[tr].fa=o; t[tl].fa=tl; ls=tr; pushup(o);
            return P(tl,o);
        }
        else
        {
            P p=split(rs,cnt-t[ls].sz-1);
            int tl=p.F,tr=p.S;
            t[tl].fa=o; t[tr].fa=tr; rs=tl; pushup(o);
            return P(o,tr);
        }
    }
    int merge(int x,int y)
    {
        if(!x||!y) return x+y;
        if(t[x].pri<t[y].pri)
        {
            int c=merge(t[x].ch[1],y);
            t[c].fa=x; t[x].ch[1]=c;
            pushup(x);
            return x;
        }
        else
        {
            int c=merge(x,t[y].ch[0]);
            t[c].fa=y; t[y].ch[0]=c;
            pushup(y);
            return y;
        }
    }
    void ins(int val)
    {
        root=merge(root,newnode(val));
    }
    int find_root(int id)
    {
        if(!id) return 0;
        int cur=id;
        while(t[id].fa!=id) id=t[id].fa;
        return id;
    }
};
using namespace treap;
int n,q;
vector<int> id;
int get_id(int x)
{
    return lower_bound(id.begin(),id.end(),x)-id.begin()+1;
}
int main()
{
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int type,y,z;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d",&y);
            newnode(y);
            id.push_back(i);
        }
        else if(type==2)
        {
            scanf("%d%d",&y,&z); y=get_id(y); z=get_id(z);
            int rooty=find_root(y),rootz=find_root(z);
            if(rooty!=rootz) merge(rooty,rootz);
        }
        else if(type==3)
        {
            scanf("%d%d",&y,&z); y=get_id(y);
            int rooty=find_root(y);
            if(t[rooty].sz>z) split(rooty,z);
        }
        else
        {
            scanf("%d",&y); y=get_id(y);
            int rooty=find_root(y);
            printf("%lld\n",t[rooty].sum);
        }
    }
    return 0;
}
