#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
const int maxn=100100;
struct Point{
    int x,y,id;
    bool operator < (const Point p) const {
        if(x!=p.x)return x<p.x;
        return y<p.y;
    }
}p[maxn];
struct BIT{
    int min_val,pos;
    void init(){
        min_val=INF;
        pos=-1;
    }
}bit[maxn<<2];
struct Edge{
    int u,v,d;
    bool operator < (const Edge p) const {
        return d<p.d;
    }
}edge[maxn<<2];
int tot,n,F[maxn];
int find(int x)
{
    return F[x]=(F[x]==x?x:find(F[x]));
}
void addedge(int u,int v,int d)
{
    edge[tot].u=u;edge[tot].v=v;edge[tot].d=d;tot++;
}
void update(int i,int val,int pos)
{
    while(i>0)
    {
        if(val<bit[i].min_val)
        {
            bit[i].min_val=val;
            bit[i].pos=pos;
        }
        i-=i&(-i);
    }
}
int query(int i,int m)
{
    int min_val=INF,pos=-1;
    while(i<=m)
    {
        if(bit[i].min_val<min_val)
        {
            min_val=bit[i].min_val;
            pos=bit[i].pos;
        }
        i+=i&(-i);
    }
    return pos;
}
int dist(Point a,Point b){
    return abs(a.y-b.y)+abs(a.x-b.x);
}
int MHT(int n,Point *p,int k){
    int a[maxn],b[maxn];
    tot=0;
    for(int dir=0;dir<4;dir++)
    {
        if(dir==1||dir==3)
        {
            for(int i=0;i<n;i++)
                swap(p[i].x,p[i].y);
        }
        if(dir==2)
        {
            for(int i=0;i<n;i++)
                p[i].x=-p[i].x;
        }
        sort(p,p+n);
        for(int i=0;i<n;i++)
            a[i]=b[i]=p[i].y-p[i].x;
        sort(b,b+n);
        int m=unique(b,b+n)-b;
        for(int i=1;i<=m;i++)bit[i].init();
        for(int i=n-1;i>=0;i--)
        {
            int pos=lower_bound(b,b+m,a[i])-b+1;
            int ans=query(pos,m);
            if(ans!=-1)addedge(p[i].id,p[ans].id,dist(p[i],p[ans]));
            update(pos,p[i].x+p[i].y,i);
        }
    }
    sort(edge,edge+tot);
    for(int i=0;i<n;i++)F[i]=i;
    for(int i=0;i<tot;i++)
    {
        int u=edge[i].u,v=edge[i].v;
        int fa=find(u),fb=find(v);
        if(fa!=fb)
        {
            k--;
            F[fa]=fb;
            if(k==0)return edge[i].d;
        }
    }
}
int main()
{
     int n,k;
     scanf("%d%d",&n,&k);
     for(int i=0;i<n;i++)
        scanf("%d %d",&p[i].x,&p[i].y),p[i].id=i;
     printf("%d\n",MHT(n,p,n-k));
     return 0;
}
