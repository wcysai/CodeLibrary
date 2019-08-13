#include <bits/stdc++.h>
#define ll long long
#define MAXN 2000005
#define P pair<int,int>
using namespace std;

inline int read()
{
    int ch=getchar(),f=0;
    int x=0;
    while(ch<'0'||ch>'9')
    {
        f|=ch=='-';
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f?-x:x;
}
struct eric
{
    int to,next,v;
}edge[MAXN<<1];
struct requests
{
    int id,type,x;
}b[MAXN<<1];
int head[MAXN],soze=0;
int n,m,K,rt=0;
int tot,rd[MAXN],som[MAXN],maxx[MAXN];
ll f[MAXN],mind[MAXN],maxa=0,mina=0,pp=1ll<<60;
inline void add(int x,int y,int z)
{
    edge[++soze].to=y;
    edge[soze].v=z;
    ++rd[y];
    edge[soze].next=head[x];
    head[x]=soze;
}
void find_root(int pos,int fa)
{
    if(rd[pos]==1)
        som[pos]=1;
    for(int i=head[pos];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)
            continue;
        find_root(v,pos);
        som[pos]+=som[v];
        maxx[pos]=max(maxx[pos],som[v]);
    }
    maxx[pos]=max(maxx[pos],K-som[pos]);
    //printf("%d %d\n",pos,maxx[pos]);
    if(rd[pos]>1&&maxx[pos]<maxx[rt])
        rt=pos;
}
void dfs(int pos,int fa)
{
    if(rd[pos]==1)
    {
        f[pos]=1;
        mind[pos]=0;
        return;
    }
    mind[pos]=1ll<<60;
    for(int i=head[pos];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)
            continue;
        dfs(v,pos);
        f[pos]+=f[v];
        maxa+=f[v]*1ll*edge[i].v;
        mina+=(f[v]&1)*1ll*edge[i].v;
        mind[pos]=min(mind[pos],mind[v]+edge[i].v);
    }
}
void resure(int pos,int fa)
{
    if(rd[pos]==1)
    {
        pp=min(pp,mind[pos]);
        //printf("%d %lld\n",pos,mind[pos]);
        return;
    }
    for(int i=head[pos];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)
            continue;
        if(f[v]&1)
        mind[v]=mind[pos]-edge[i].v;
        else
        mind[v]=mind[pos]+edge[i].v;
        resure(v,pos);
    }
}
int main()
{
    freopen("trams.in","r",stdin);
    freopen("trams.out","w",stdout);
    n=read();
    for(int i=1,x,y,z;i<n;i++)
        x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
    if(n==2)
    {
        printf("%lld\n%lld\n",edge[1].v*1ll,edge[1].v*1ll);
        return 0;
    }
    for(int i=1;i<=n;i++)
        K+=rd[i]==1;
    maxx[0]=1000000000;
    for(int i=1;i<=n;i++)
        if(rd[i]>1)
    {
        find_root(i,0);
        break;
    }
    //printf("%d\n",rt);
    dfs(rt,0);
    //printf("%lld %lld\n",mind[rt],maxa);
    if(K&1)
        maxa-=mind[rt],mind[rt]=0,resure(rt,0),mina+=pp;
    printf("%lld\n%lld\n",mina,maxa);
    return 0;
}
/*
8
1 3 1
2 3 1
3 4 1
4 5 1
5 6 1
5 7 2
5 8 1
12
1 3 1
2 3 1
3 4 1
4 8 1
8 10 1
8 9 1
4 5 1
5 6 1
5 7 1
6 11 1
6 12 1
*/
