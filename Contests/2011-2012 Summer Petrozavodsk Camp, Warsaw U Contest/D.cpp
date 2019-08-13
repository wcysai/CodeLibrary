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
    int to,next,from;
}edge[MAXN<<1];
struct requests
{
    int id,type,x;
}b[MAXN<<1];
int head[MAXN],soze=0;
int n,m,q;
int dis[MAXN],cut[MAXN<<1],out[MAXN<<1],tot;
inline void add(int x,int y)
{
    edge[++soze].to=y;
    edge[soze].from=x;
    edge[soze].next=head[x];
    head[x]=soze;
}
void dfs(int pos)
{
    for(int i=head[pos];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(dis[pos]+1<dis[v]&&!cut[i])
            dis[v]=dis[pos]+1,dfs(v);
    }
}
int main()
{
    freopen("evacuation.in","r",stdin);
    freopen("evacuation.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i=1,x,y;i<=m;i++)
    {
        x=read(),y=read();
        add(x,y);
    }
    for(int i=q;i;i--)
    {
        b[i].id=i;
        int ch=getchar();
        while(ch!='U'&&ch!='E')
            ch=getchar();
        b[i].type=ch=='U';
        b[i].x=read();
        if(ch=='U')
            cut[b[i].x]=1;
    }
    for(int i=1;i<=n;i++)
        dis[i]=1000000000;
        dis[1]=0;
    dfs(1);
    for(int i=1;i<=q;i++)
    {
        if(b[i].type==1)
        {
            cut[b[i].x]=0;
            int u=edge[b[i].x].from,v=edge[b[i].x].to;
            if(dis[u]+1<dis[v])
                dis[v]=min(dis[u]+1,dis[v]),dfs(v);
        }
        else
            out[++tot]=dis[b[i].x]==1000000000?-1:dis[b[i].x];
    }
    reverse(out+1,out+tot+1);
    for(int i=1;i<=tot;i++)
        printf("%d\n",out[i]);
    return 0;
}
/*
7 8 8
1 2
1 3
1 5
2 4
3 1
3 5
4 5
4 6
E 7
E 5
U 7
E 6
E 5
U 2
E 5
E 4
*/
