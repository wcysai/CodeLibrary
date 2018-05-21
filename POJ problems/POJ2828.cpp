#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MAXN 200050
using namespace std;
int n,ans[MAXN];
pair<int,int> a[MAXN];
struct node
{
    node *l, *r, *p;
    int key;
    int cnt;
} *tree;
void Update(node *x)
{
    x->cnt = 1;
    if(x->l) x->cnt += x->l->cnt;
    if(x->r) x->cnt += x->r->cnt;
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
void Insert(int key)
{
    node *p = tree, **pp;
    if(!p)
    {
        node *x = new node;
        tree = x;
        x->l = x->r = x->p = NULL;
        x->key = key;
        x->cnt = 1;
        return;
    }
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
        }
        else
        {
            if(!p->r)
            {
                pp = &p->r;
                break;
            }
            p = p->r;
        }
    }
    node *x = new node;
    *pp = x;
    x->l = x->r = NULL;
    x->p = p;
    x->key = key;
    x->cnt = 1;
    Splay(x);
}
void Find_Kth(int k)
{
    node *x = tree;
    while(1)
    {
        while(x->l && x->l->cnt > k)
            x = x->l;
        if(x->l) k -= x->l->cnt;
        if(!k--) break;
        x = x->r;
    }
    Splay(x);
}
void Delete()
{
    node *p = tree;
    if(p->l)
    {
        if(p->r)
        {
            tree = p->l;
            tree->p = NULL;
            node *x = tree;
            while(x->r)
                x = x->r;
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
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            Insert(i+1);
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i].first,&a[i].second);
        for(int i=n-1;i>=0;i--)
        {
            Find_Kth(a[i].first);
            ans[tree->key]=a[i].second;
            Delete();
        }
        for(int i=1;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}


