#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
using namespace std;
int n;
struct Node
{   
    int sz,key,cnt;
    Node *p,*ch[2];
    Node(int v=0) {p=ch[0]=ch[1]=0;key=v;cnt=1; }
};
typedef Node* pnode;
pnode root;
int sz(pnode t)
{
    return t?t->sz:0;
}
void pushup(Node *x)
{
    if(!x) return;
    x->sz=x->cnt+sz(x->ch[0])+sz(x->ch[1]);
}
void rot(Node *x)
{
    Node *y,*z;
    y=x->p,z=y->p;
    int xp=(x==y->ch[0])?0:1,yp=(z)?((y==z->ch[0])?0:1):-1;
    if((y->ch[xp]=x->ch[1^xp]))y->ch[xp]->p=y;
    x->ch[1^xp]=y,y->p=x;
    if((x->p=z))z->ch[yp]=x;
    pushup(y);
}
 
void splay(Node *x)
{
    if(!x)return;
    while (x->p)rot(x);
    pushup(x);
}

void merge (pnode &c,Node *L,Node *R)
{
    if(!L||!R){ c=(!L)?R:L,pushup(c);return;}
    c=L;
    while (c->ch[1])c=c->ch[1];
    splay(c);c->ch[1]=R;if(R) R->p=c;
    pushup(c);
}
Node *find (Node *T,int k,Node *p=0)
{
    if(!T)return p;
    return (T->key==k)?T:(T->key>k)?find(T->ch[0],k,T):find(T->ch[1],k,T);
}
Node *findx(Node *T,int k)
{
    pnode now=T;
    while(1)
    {
        if (now->ch[0]&&k<=now->ch[0]->sz) now=now->ch[0];
        else
        {
            int temp=(now->ch[0]?now->ch[0]->sz:0)+now->cnt;
            if (k<=temp) return now;
            k-=temp; now=now->ch[1];
        }
    }
}
void split (pnode T,pnode & L,pnode & R ,int x)
{
    if(!T){L=R=NULL;return;}
    T=find(T,x);splay(T);
    if(T->key>x)L=T->ch[0],T->ch[0]=0,R=T;
    else R=T->ch[1],T->ch[1]=0,L=T;
    if(L)L->p=0;if(R)R->p=0;
    pushup(L);pushup(R);
}
 
void insert(pnode &T,int x)
{
    pnode n=new Node(x);
    pnode l=0,r=0;
    if(T) 
    {
        T=find(T,x);splay(T);
        if(T->key==x)T->cnt++;
        else
        {
            split(T,l,r,x),n->ch[0]=l,n->ch[1]=r;
            if(l)l->p=n;
            if(r)r->p=n;
            T=n;
        }
    }
    if(!T) T=n;
    pushup(T);
}
void erase(pnode &n,int k)
{
    if(!n) return;
    n=find(n,k);splay(n);
    if(n->key==k)
    {
        n->cnt--;
        if(!n->cnt)
        {
            if(n->ch[0]) n->ch[0]->p=0;
            if(n->ch[1]) n->ch[1]->p=0;
            merge(n,n->ch[1],n->ch[0]);
        }
    }
}
int pre(pnode &n)
{
    if(!n) return -1;
    pnode now=n->ch[0];
    if(!now) return 0;
    while(now->ch[1]) now=now->ch[1];
    return now->key;
}
int next(pnode &n)
{
    if(!n) return -1;
    pnode now=n->ch[1];
    if(!now) return 0;
    while(now->ch[0]) now=now->ch[0];
    return now->key;
}
int main()
{
    scanf("%d",&n);
    int op,x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&op,&x);
        switch(op)
        {
            case 1: insert(root,x); break;
            case 2: erase(root,x); break;
            case 3: printf("%d\n",find(root,x)->key); break;
            case 4: printf("%d\n",findx(root,x)->key); break;
            case 5: insert(root,x); printf("%d\n",pre(root)); erase(root,x); break;
            case 6: insert(root,x); printf("%d\n",next(root)); erase(root,x); break;
        }
    }
}

