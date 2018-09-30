/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 17:59:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k,a[MAXN];
int ch[MAXM][2],f[MAXM],size[MAXM],cnt[MAXM],key[MAXM];
int sz,root[MAXN];
int ans[MAXN],sum[MAXN];
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
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
inline void splay(int i,int x,int goal=0)
{
    for(int fa;(fa=f[x])!=goal;rotate(x))
        if(f[fa]!=goal) rotate((get(x)==get(fa))?fa:x);
    if(goal==0) root[i]=x;
}
inline void insert(int i,int x)
{
    int now=root[i],fa=0;
    if (!root[i]){root[i]=++sz; ch[sz][0]=ch[sz][1]=f[sz]=0; size[sz]=cnt[sz]=1; key[sz]=x; return;}
    while(1)
    {
        if (x==key[now])
        {
            cnt[now]++; pushup(now); pushup(fa); splay(i,now); break;
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
            splay(i,sz);
            break;
        }
    }
}
inline int find(int i,int x)
{
    int now=root[i],ans=0;
    while(1)
    {
        if(x<key[now]) now=ch[now][0];
        else
        {
            ans+=(ch[now][0]?size[ch[now][0]]:0);
            if (x==key[now]){splay(i,now); return ans+1;}
            ans+=cnt[now];
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
        if(key[now]==x) return ((ch[now][0])?size[ch[now][0]]:0)+ans+cnt[now];
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
inline void Del(int i,int x)
{
    int whatever=find(i,x);
    int rt=root[i];
    if (cnt[rt]>1){cnt[rt]--; pushup(rt); return;}
    if (!ch[rt][0]&&!ch[rt][1]) {clear(rt); root[i]=0; return;}
    if (!ch[rt][0])
    { 
        int oldroot=rt; root[i]=ch[rt][1]; f[root[i]]=0; clear(oldroot); return;
    }
    else if (!ch[rt][1])
    {
        int oldroot=rt; root[i]=ch[rt][0]; f[root[i]]=0; clear(oldroot); return;
    }
    int leftbig=pre(i),oldroot=rt;
    splay(i,leftbig);
    ch[root[i]][1]=ch[oldroot][1];
    f[ch[oldroot][1]]=rt;
    clear(oldroot);
    pushup(rt);
}
int lowbit(int x) {return x&(-x);}
void add(int i,int x)
{
    while(i<MAXN)
    {
        insert(i,x);
        i+=lowbit(i);
    }
}
int query(int i,int x)
{
    int ans=0;
    while(i>0)
    {
        ans+=findx(i,x);
        i-=lowbit(i);
    }
    return ans;
}
void del(int i,int x)
{
    while(i<MAXN)
    {
        Del(i,x);
        i+=lowbit(i);
    }
}
char str[5];
int main()
{
    read(n);read(q);
    for(int i=1;i<=n;i++) 
    {
        read(a[i]);
        add(i,a[i]);
    }
    int l,r,x,y;
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        if(str[0]=='G')
        {
            read(l);read(r);read(x);read(y);
            int ans=query(r,y)-query(r,x-1)-(query(l-1,y)-query(l-1,x-1));
            printf("%d\n",ans);
        }
        else
        {
            read(x);read(y);
            del(x,a[x]);a[x]=y;add(x,a[x]);
        }
    }
    return 0;
}

