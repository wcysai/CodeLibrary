#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
const db PI=acos(-1.0);
const db eps=1e-8;
int n,ans;
int sgn(db ta,db tb)
{
    if(fabs(ta-tb)<eps) return 0;
    if(ta<tb) return -1;
    return 1;
}
int fa[MAXN],r[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
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
    x=find(x);
    y=find(y);
    if(x==y) return;
    ans--;
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
struct Point
{
    db x,y;
    Point(){}
    Point(db tx,db ty) {x=tx,y=ty;}

    bool operator < (const Point &_se) const
    {
        return sgn(x,_se.x)==-1||(sgn(x,_se.x)==0&&sgn(y,_se.y)==-1);
    }

    bool operator == (const Point &_se) const
    {
        return sgn(x,_se.x)==0&&sgn(y,_se.y)==0;
    }
};

db getdis(const Point &lhs,const Point &rhs)
{
    return hypot(lhs.x-rhs.x,lhs.y-rhs.y);
}

struct Circle
{
    Point p;
    db r;

    Circle(){}
    Circle(db tx,db ty,db tr) {p.x=tx,p.y=ty; r=tr;}
};

vector<Circle> v;

bool intersection(const Circle &c1,const Circle &c2,Point &p1,Point &p2)
{
    db d=getdis(c1.p,c2.p);
    if(sgn(d,c1.r+c2.r)>0||sgn(d,fabs(c1.r-c2.r))<0) return false;
    db cosa=(c1.r*c1.r+d*d-c2.r*c2.r)/(2*d*c1.r);
    db sina=sqrt(max(0.0,1.0-cosa*cosa));
    p1=c1.p,p2=c1.p;
    p1.x+=c1.r/d*((c2.p.x-c1.p.x)*cosa+(c2.p.y-c1.p.y)*-sina);
    p1.y+=c1.r/d*((c2.p.x-c1.p.x)*sina+(c2.p.y-c1.p.y)*cosa);
    p2.x+=c1.r/d*((c2.p.x-c1.p.x)*cosa+(c2.p.y-c1.p.y)*sina);
    p2.y+=c1.r/d*((c2.p.x-c1.p.x)*-sina+(c2.p.y-c1.p.y)*cosa);
    return true;
}
set<Point> pp,p[MAXN];

int main()
{
    freopen("circles.in","r",stdin);
    freopen("circles.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        db x,y,c;
        scanf("%lf%lf%lf",&x,&y,&c);
        v.push_back((Circle){x,y,c});
    }
    init(n);
    ans=n+1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            Point a,b;
            if(intersection(v[i],v[j],a,b))
            {
                pp.insert(a); pp.insert(b);
                p[i].insert(a); p[i].insert(b);
                p[j].insert(a); p[j].insert(b);
                unite(i,j);
            }
        }
    }
    ans-=(int)pp.size();
    for(int i=0;i<n;i++) ans+=p[i].size();
    printf("%d\n",ans);
    return 0;
}
