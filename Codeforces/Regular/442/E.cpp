#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,p[MAXN],in[MAXN],out[MAXN],t[MAXN],q,ti,num[MAXN];
bool used[MAXN];
vector<int> G[MAXN];
struct node
{
    int l,r,cnt,lazy;
}seg[4*MAXN];
void dfs(int x)
{
    in[x]=++ti;
    for(int i=0;i<G[x].size();i++)
    {
        if(G[x][i]==p[x]) continue;
        dfs(G[x][i]);
    }
    out[x]=ti;
    return;
}
void build(int k,int l,int r)
{
    seg[k].l=l;
    seg[k].r=r;
    seg[k].lazy=0;
    if(l==r)
    {
        seg[k].cnt=t[num[l]];
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    seg[k].cnt=seg[k*2].cnt+seg[k*2+1].cnt;
}
void update(int k)
{
    seg[k].lazy^=1;
    seg[k].cnt=seg[k].r-seg[k].l+1-seg[k].cnt;
}
void pass(int k)
{
    seg[k].lazy=0;
    if(seg[k].l==seg[k].r) return;
    update(k*2);
    update(k*2+1);
}
void flip(int k, int l, int r)
{
    if(seg[k].l>r||seg[k].r<l) return;
    if(seg[k].l>=l&&seg[k].r<=r)
    {
        update(k);
        return;
    }
    if(seg[k].lazy) pass(k);
    flip(k*2,l,r);
    flip(k*2+1,l,r);
    seg[k].cnt=seg[k*2].cnt+seg[k*2+1].cnt;
}
int query(int k,int l,int r)
{
    if(seg[k].l>r||seg[k].r<l) return 0;
    if(seg[k].l>=l&&seg[k].r<=r) return seg[k].cnt;
    if(seg[k].lazy) pass(k);
    return query(k*2,l,r)+query(k*2+1,l,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);
        G[i].push_back(p[i]);
        G[p[i]].push_back(i);
    }
    ti=0;
    dfs(1);
    for(int i=1;i<=n;i++)
        num[in[i]]=i;
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    build(1,1,n);
    scanf("%d",&q);
    char str[5];
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%s%d",str,&x);
        if(str[0]=='p') flip(1,in[x],out[x]); else printf("%d\n",query(1,in[x],out[x]));
    }
    return 0;
}
