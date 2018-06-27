#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MAXN 120050
using namespace std;
typedef long long ll;
ll n,q,a[MAXN];
struct node
{
    node *l, *r, *p;
    ll key;
    ll cnt;
    ll val;
    ll sum;
    ll lazy;
} *tree;
void Update(node *x)
{
    x->cnt = 1;
    x->sum=x->val;
    if(x->l) x->cnt += x->l->cnt;
    if(x->r) x->cnt += x->r->cnt;
    if(x->l) x->sum+=x->l->sum;
    if(x->r) x->sum+=x->r->sum;
}
void Lazy(node *x)
{
    if(x->l) x->l->sum += (x->l->cnt)*(x->lazy);
    if(x->r) x->r->sum += (x->r->cnt)*(x->lazy);
    if(x->l) x->l->lazy += x->lazy;
    if(x->r) x->r->lazy += x->lazy;
    if(x->l) x->l->val+= x->lazy;
    if(x->r) x->r->val += x->lazy;
    x->lazy = 0;
}
void Rotate(node *x)
{
    node *p = x->p;
    node *b;
    if(x == p->l)
    {
        p->l = b = x->r;
        x->r = p;
    }
    else
    {
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if(b) b->p = p;
    (x->p? p == x->p->l? x->p->l : x->p->r : tree) = x;
    Update(p);
    Update(x);
}
void Splay(node *x)
{
    while(x->p)
    {
        node *p = x->p;
        node *g = p->p;
        if(g) Rotate((x == p->l) == (p == g->l)? p : x);
        Rotate(x);
    }
}
void Insert(ll key,ll val)
{
    node *p = tree, **pp;
    if(!p)
    {
        node *x = new node;
        tree = x;
        x->l = x->r = x->p = NULL;
        x->key = key;
        x->val = val;
        x->cnt = 1;
        x->sum= val;
        x->lazy = 0;
        return;
    }
    Lazy(p);
    while(1)
    {
        if(key == p->key) return;
        if(key < p->key)
        {
            if(!p->l)
            {
                pp = &p->l;
                break;
            }
            p = p->l;
            Lazy(p);
        }
        else
        {
            if(!p->r)
            {
                pp = &p->r;
                break;
            }
            p = p->r;
            Lazy(p);
        }
    }
    node *x = new node;
    *pp = x;
    x->l = x->r = NULL;
    x->p = p;
    x->val = val;
    x->key = key;
    x->cnt = 1;
    x->sum = val;
    x->lazy = 0;
    Splay(x);
}
bool Find(ll key)
{
    node *p = tree;
    node *ret;
    if(!p) return false;
    Lazy(p);
    while(p)
    {
        if(key < p->key)
        {
            if(!p->l) break;
            p = p->l;
            Lazy(p);
        }
        else
        {
            ret = p;
            if(!p->r) break;
            p = p->r;
            Lazy(p);
        }
    }
    Splay(ret);
    return key == ret->key;
}
void Delete(ll key)
{
    if(!Find(key)) return;
    node *p = tree;
    if(p->l)
    {
        if(p->r)
        {
            tree = p->l;
            tree->p = NULL;
            node *x = tree;
            Lazy(x);
            while(x->r)
            {
                x = x->r;
                Lazy(x);
            }
            x->r = p->r;
            p->r->p = x;
            Splay(x);
            delete p;
            return;
        }
        tree = p->l;
        tree->p = NULL;
        delete p;
        return;
    }
    if(p->r)
    {
        tree = p->r;
        tree->p = NULL;
        delete p;
        return;
    }
    tree = NULL;
}

void Find_Kth(ll k)
{
    node *x = tree;
    Lazy(x);
    while(1)
    {
        while(x->l && x->l->cnt > k)
        {
            x = x->l;
            Lazy(x);
        }
        if(x->l) k -= x->l->cnt;
        if(!k--) break;
        x = x->r;
        Lazy(x);
    }
    Splay(x);
}
void Interval(ll l, ll r)
{
    Find_Kth(l - 1);
    node *x = tree;
    tree = x->r;
    tree->p = NULL;
    Find_Kth(r - l + 1);
    x->r = tree;
    tree->p = x;
    tree = x;
}
void Add(ll l, ll r, ll z)
{
    Interval(l, r);
    node *x = tree->r->l;
    if(x->key!=0&&x->key!=n+1)
    {
        x->lazy += z;
        x->val+=z;
        x->sum+=(x->cnt)*z;
    }
    return;
}
int main()
{
    scanf("%I64d %I64d",&n,&q);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(ll i=0;i<=n+1;i++)
        if(i==0||i==n+1) Insert(i,0); else Insert(i,a[i-1]);
    for(ll i=0;i<q;i++)
    {
        ll x,y;
        ll z;
        char str[2];
        scanf("%s %I64d %I64d",str,&x,&y);
        if(str[0]=='C')
        {
            scanf("%I64d",&z);
            Add(x,y,z);
        }
        else
        {
            Interval(x,y);
            node *x = tree->r->l;
            printf("%I64d\n",x->sum);
        }
    }
    return 0;
}
