/*************************************************************************
    > File Name: 3263_splay.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-21 14:03:39
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node
{
    int x,y,z;
}a[MAXN];
bool cmp(node p,node q)
{
    if(p.x!=q.x) return p.x<q.x;
    if(p.y!=q.y) return p.y<q.y;
    return p.z<q.z;
}
int n,k;
int ch[MAXM][2],f[MAXM],size[MAXM],cnt[MAXM],key[MAXM];
int sz,root[MAXN];
int ans[MAXN],sum[MAXN];
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
int lowbit(int x) {return x&(-x);}
void add(int i,int x)
{
    while(i<=k)
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
int main()
{
    n=read();k=read();
    for(int i=1;i<=n;i++) {a[i].x=read();a[i].y=read();a[i].z=read();}
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y&&a[i].z==a[i+1].z&&i!=n) sum[i+1]+=sum[i]+1;
        else
        {
            int res=query(a[i].y,a[i].z);
            ans[res]+=sum[i]+1;
        }
        add(a[i].y,a[i].z);
    }
    for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}

