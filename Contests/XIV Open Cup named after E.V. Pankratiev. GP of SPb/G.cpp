#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
#define int128 __int128_t
#define P pair<int128,int>
#define INF (((int128)1)<<126)
using namespace std;

struct eric
{
    int to,next,v;
    int128 cost;
}edge[MAXN];
struct bib
{
    int from,to,lv;
}b[MAXN];
struct cmp
{
    inline bool operator()(const bib& a,const bib& b)
    {
        return a.lv<b.lv;
    }
};
int head[MAXN],soze=1,totl,cur[MAXN];
int last[MAXN],pre[MAXN],flow[MAXN],ined[MAXN];
int n,m,s,t,S,T;
int out[MAXN];
int128 dis[MAXN],mincost;
inline int128 power(int128 a,int p)
{
    int128 ret=1;
    while(p>0)
    {
        if(p&1)
            ret=ret*a;
        a=a*a;
        p>>=1;
    }
    return ret;
}
inline void add(int x,int y,int z,int128 w)
{
    edge[++soze].to=y;
    edge[soze].v=z;
    edge[soze].cost=w;
    edge[soze].next=head[x];
    head[x]=soze;
    edge[++soze].to=x;
    edge[soze].v=0;
    edge[soze].cost=-w;
    edge[soze].next=head[y];
    head[y]=soze;
}
queue<int> que;
inline bool spfa()
{
    for(int i=s;i<=t;i++)
        dis[i]=INF,cur[i]=head[i],ined[i]=0,flow[i]=1000000000;
    dis[s]=0;pre[t]=-1;
    while(!que.empty())
        que.pop();
    que.push(s);ined[s]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();ined[u]=0;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            //printf("%d %d %d %d\n",u,v,flow[u],flow[v]);
            if(dis[v]>dis[u]+edge[i].cost&&edge[i].v>0&&flow[u]>0)
            {
                dis[v]=dis[u]+edge[i].cost;
                flow[v]=min(edge[i].v,flow[u]);
                pre[v]=u;
                last[v]=i;
                if(ined[v]==0)
                {
                    ined[v]=1;
                    que.push(v);
                }
            }
        }
    }
    //for(int i=1;i<=n;i++)
        //printf("%d\n",flow[i]);
    return pre[t]!=-1&&dis[t]<0;
}
inline int dinic()
{
    int maxflow=0;
    while(spfa())
    {
        int pos=t;
        maxflow+=flow[t];
        mincost+=flow[t]*dis[t];
        while(pos!=s)
        {
            edge[last[pos]].v-=flow[t];
            edge[last[pos]^1].v+=flow[t];
            pos=pre[pos];
        }
    }
    return maxflow;
}
int main()
{
    freopen("medals.in","r",stdin);
    freopen("medals.out","w",stdout);
    scanf("%d",&n);
    s=0,t=2001;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            ++totl;
            scanf("%d%d",&b[totl].to,&b[totl].lv);
            b[totl].from=i;
            add(i,1000+b[totl].to,1,-power(1000,10-b[totl].lv));
        }
    }
    for(int i=1;i<=n;i++)
        add(s,i,1,0);
    for(int i=1;i<=1000;i++)
        add(i+1000,t,1,0);
    int128 tmp=dinic(),tt=-mincost;
    for(int i=1;i<=10;i++)
    {
        int128 tp=power(1000,10-i);
        out[i]=tt/tp;
        tt%=tp;
        printf("%d ",out[i]);
    }
    puts("");
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        for(int j=head[i];j;j=edge[j].next)
        {
            if(edge[j].to>s&&edge[j].v==0)
            {
                printf("%d ",edge[j].to-1000);
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("0 ");
    }
    printf("\n");
    return 0;
}
/*
5
2 1 1 2 1
2 2 2 3 3
1 1 2
1 3 3
1 4 1
*/
