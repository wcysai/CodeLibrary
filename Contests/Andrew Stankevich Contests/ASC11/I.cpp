#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double db;
const db eps=1e-8;
int n;
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
};
db getdis(Point p,Point q)
{
    return hypot(p.x-q.x,p.y-q.y);
}
Point p[MAXN];
int fa[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) fa[x]=y;
    else
    {
        fa[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
vector<pair<db,pair<int,int> > > ve;
int type[MAXN];
bool vis[MAXN];
int main()
{
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    init(2*n);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ve.push_back(make_pair(getdis(p[i],p[j]),make_pair(i,j)));
    sort(ve.begin(),ve.end());
    db ans=0.0;
    for(int i=0;i<(int)ve.size();i++)
    {
        ans=ve[i].F;
        int u=ve[i].S.F,v=ve[i].S.S;
        if(same(u,v)||same(u+n,v+n)) break;
        unite(u,v+n); unite(u+n,v);
    }
    printf("%.15f\n",ans/2.0);
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=true;
        type[i]=1;
        for(int j=1;j<=2*n;j++)
        {
            if(i==j) continue;
            if(same(i,j))
            {
                if(j<=n) {type[j]=1; vis[j]=true;}
                else {type[j-n]=2; vis[j-n]=true;}
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",type[i]);
    return 0;
}

