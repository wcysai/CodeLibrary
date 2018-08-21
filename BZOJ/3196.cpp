/*************************************************************************
    > File Name: 3196.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-21 08:24:50
 ************************************************************************/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
int ch[MAXN][2],f[MAXN],size[MAXN],cnt[MAXN],key[MAXN];
int sz,root[MAXN],ans;
inline int in()
{
    int x=0,f=1; char ch=getchar();
    while (ch>'9'||ch<'0'){
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void clear(int x)
{
    ch[x][0]=ch[x][1]=f[x]=size[x]=cnt[x]=key[x]=0;
}
inline bool get(int x)
{
    return ch[f[x]][1]==x;
}
inline void pushup(int x)
{
    if (x)
    {
        size[x]=cnt[x];
        if (ch[x][0]) size[x]+=size[ch[x][0]];
        if (ch[x][1]) size[x]+=size[ch[x][1]];
    }
}
inline void rotate(int x)
{
    int old=f[x],oldf=f[old],whichx=get(x);
    ch[old][whichx]=ch[x][whichx^1]; f[ch[old][whichx]]=old;
    ch[x][whichx^1]=old; f[old]=x;
    f[x]=oldf;
    if (oldf) ch[oldf][ch[oldf][1]==old]=x;
    pushup(old); pushup(x);
}
inline void splay(int x,int goal=0)
{
    for(int fa;(fa=f[x])!=goal;rotate(x))
        if(f[fa]!=goal) rotate((get(x)==get(fa))?fa:x);
    
}
inline void insert(int i,int x)
{
    int now=root[i],fa=0;
    if (!root[i]){root[i]=++sz; ch[sz][0]=ch[sz][1]=f[sz]=0; size[sz]=cnt[sz]=1; key[sz]=x; return;}
    while(1)
    {
        if (x==key[now])
        {
            cnt[now]++; pushup(now); pushup(fa); splay(now); root[i]=now; break;
        }
        fa=now;
        now=ch[now][key[now]<x];
        if (now==0)
        {
            sz++;
            ch[sz][0]=ch[sz][1]=0;
            f[sz]=fa;
            size[sz]=cnt[sz]=1;
            ch[fa][key[fa]<x]=sz;
            key[sz]=x;
            pushup(fa);
            splay(sz);root[i]=sz;
            break;
        }
    }
}
inline void find(int i,int x)
{
    int now=root[i];
    while(1)
    {
        if(x<key[now]) now=ch[now][0];
        else
        {
            if (x==key[now]){splay(now); root[i]=now; return;}
            now=ch[now][1];
        }
    }
}
inline int findx(int i,int x)
{
    int now=root[i],ans=0;
    while(1)
    {
        if(!now) return ans;
        if(key[now]==x) return ((ch[now][0])?size[ch[now][0]]:0)+ans;
        else if(key[now]<x)
        {
            ans+=((ch[now][0])?size[ch[now][0]]:0)+cnt[now];
            now=ch[now][1];
        }
        else if(key[now]>x) now=ch[now][0];
    }
}
inline int pre(int i)
{
    int now=ch[root[i]][0];
    while (ch[now][1]) now=ch[now][1];
    return now;
}
inline int next(int i)
{
    int now=ch[root[i]][1];
    while (ch[now][0]) now=ch[now][0];
    return now;
}
inline int findpre(int i,int k)
{
    int now=root[i];
    while(now)
    {
        if(key[now]<k)
        {
            if(ans<key[now]) ans=key[now];
            now=ch[now][1];
        }
        else now=ch[now][0];
    }
    return ans;
}
inline int findnext(int i,int k)
{
    int now=root[i];
    while(now)
    {
        if(key[now]>k)
        {
            if(ans>key[now]) ans=key[now];
            now=ch[now][0];
        }
        else now=ch[now][1];
    }
    return ans;
}
inline void del(int i)
{
    int now=root[i];
    if (cnt[now]>1){cnt[now]--; pushup(now); return;}
    if (!ch[now][0]&&!ch[now][1]) {clear(now); root[i]=0; return;}
    if (!ch[now][0])
    { 
        int oldroot=now; root[i]=ch[oldroot][1]; f[root[i]]=0; clear(oldroot); return;
    }
    else if (!ch[now][1])
    {
        int oldroot=now; root[i]=ch[oldroot][0]; f[root[i]]=0; clear(oldroot); return;
    }
    int leftbig=pre(i),oldroot=root[i];
    splay(leftbig,0);root[i]=leftbig;
    ch[root[i]][1]=ch[oldroot][1];
    f[ch[oldroot][1]]=root[i];
    clear(oldroot);
    pushup(root[i]);
}
inline void seg_insert(int now,int l,int r,int pos,int v)
{
    insert(now,v);if(l==r) return;
    int mid=(l+r)/2;
    if(pos<=mid) seg_insert(now*2,l,mid,pos,v);
    else seg_insert(now*2+1,mid+1,r,pos,v);
}
inline void seg_findx(int now,int l,int r,int x,int y,int k)
{
    if(l>=x&&r<=y)
    {
        ans+=findx(now,k);
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) seg_findx(now*2,l,mid,x,y,k);
    if(y>=mid+1) seg_findx(now*2+1,mid+1,r,x,y,k);
}
inline void seg_update(int now,int l,int r,int pos,int k)
{
    find(now,a[pos]);del(now);insert(now,k);
    if(l==r) return;
    int mid=(l+r)/2;
    if(pos<=mid) seg_update(now*2,l,mid,pos,k);
    else seg_update(now*2+1,mid+1,r,pos,k);
}
inline void seg_pre(int now,int l,int r,int x,int y,int k)
{
    if(l>=x&&r<=y)
    {
        ans=max(ans,findpre(now,k));
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) seg_pre(now*2,l,mid,x,y,k);
    if(y>=mid+1) seg_pre(now*2+1,mid+1,r,x,y,k);
}
inline void seg_next(int now,int l,int r,int x,int y,int k)
{
    if(x>r||l>y) return;
    if(l>=x&&r<=y)
    {
        ans=min(ans,findnext(now,k));
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) seg_next(now*2,l,mid,x,y,k);
    if(y>=mid+1) seg_next(now*2+1,mid+1,r,x,y,k);
}
int main()
{
    n=in();m=in();
    int mx=0;
    for(int i=1;i<=n;i++) {a[i]=in(); mx=max(mx,a[i]); seg_insert(1,1,n,i,a[i]);}
    int op,l,r,pos,k;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&op);
        if(op==1)
        {
            l=in();r=in();k=in();
            ans=0;
            seg_findx(1,1,n,l,r,k);
            printf("%d\n",ans+1);
        }
        else if(op==2)
        {
            l=in();r=in();k=in();
            int ll=-1,rr=mx+1;
            while(rr-ll>1)
            {
                int mid=(ll+rr)/2;
                ans=0;
                seg_findx(1,1,n,l,r,mid);
                if(ans<k) ll=mid; else rr=mid;
            }
            printf("%d\n",ll);
        }
        else if(op==3)
        {
            pos=in();k=in();
            seg_update(1,1,n,pos,k);
            a[pos]=k;mx=max(mx,k);
        }
        else if(op==4)
        {
            l=in();r=in();k=in();
            ans=0;
            seg_pre(1,1,n,l,r,k);
            printf("%d\n",ans);
        }
        else
        {
            l=in();r=in();k=in();
            ans=INF;
            seg_next(1,1,n,l,r,k);
            printf("%d\n",ans);
        }
    }
    return 0;
}

