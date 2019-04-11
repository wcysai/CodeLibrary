#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dalsodsa
#define y1 cdiakdao
#define x2 dakiad
#define y2 caokdsoa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
const db eps=1e-8;
const db PI=acos(-1.0);
db x1,y1,x2,y2;

int sgn(db ta,db tb)
{
    if(fabs(ta-tb)<eps) return 0;
    if(ta>tb) return 1;
    return -1;
}
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y) {x=_x; y=_y;}

    bool operator<(const Point &_se) const
    {
        return x<_se.x||(x==_se.x&&y<_se.y);
    }
    friend Point operator+(const Point &_st,const Point &_se)
    {
        return Point(_st.x+_se.x,_st.y+_se.y);
    }
    friend Point operator-(const Point &_st,const Point &_se)
    {
        return Point(_st.x-_se.x,_st.y-_se.y);
    }
    Point operator*(const db v) const
    {
        return Point(v*x,v*y);
    }
}p[4];
db xmult(const Point &po,const Point &ps,const Point &pe)
{
    return (ps.x-po.x)*(pe.y-po.y)-(pe.x-po.x)*(ps.y-po.y);
}
db dis2(const Point &p,const Point &q)
{
    return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}
db find_area(const Point &p,const Point &q,const Point &r)
{
    db ans=0.0;
    ans+=p.x*q.y-p.y*q.x;
    ans+=q.x*r.y-q.y*r.x;
    ans+=r.x*p.y-r.y*p.x;
    return fabs(ans/2.0);
}
struct Line
{
    Point s,e;
    db a,b,c;
    Line(){}
    Line(Point ts,Point te):s(ts),e(te){}
    bool pton()
    {
        a=e.y-s.y;
        b=s.x-e.x;
        c=e.x*s.y-e.y*s.x;
        return true;
    }
    pair<db,bool> dis(const Point &_off,bool isSegment=false)
    {
        pton();
        db td=(a*_off.x+b*_off.y+c)/sqrt(a*a+b*b);
        if(isSegment)
        {
            db xp=(b*b*_off.x-a*b*_off.y-a*c)/(a*a+b*b);
            db yp=(-a*b*_off.x+a*a*_off.y-b*c)/(a*a+b*b);
            db xb=max(s.x,e.x);
            db yb=max(s.y,e.y);
            db xs=s.x+e.x-xb;
            db ys=s.y+e.y-yb;
            if(xp>xb+eps||xp<xs-eps||yp>yb+eps||yp<ys-eps) 
            {
                td=min(sqrt(dis2(_off,s)),sqrt(dis2(_off,e)));
                return make_pair(fabs(td),false);
            }
        }
        return make_pair(fabs(td),true);
    }
};
struct Circle
{
    Point center;
    db r;
    bool in_circle(const Point& p)
    {
        db d=dis2(p,center);
        return sgn(r*r,d)>=0;
    }
    Point intersection(const Point &inside,const Point &outside)
    {
        db l=0.0,r=1.0;
        while(r-l>eps)
        {
            db mid=(l+r)/2;
            if(in_circle(inside+(outside-inside)*mid)) l=mid; else r=mid;
        }
        return inside+(outside-inside)*l;
    }
    pair<Point,Point> cross(Line _off)
    {
        _off.pton();
        db td=fabs(_off.a*center.x+_off.b*center.y+_off.c)/sqrt(_off.a*_off.a+_off.b*_off.b);
        db xp=(_off.b*_off.b*center.x-_off.a*_off.b*center.y-_off.a*_off.c)/(_off.a*_off.a+_off.b*_off.b);
        db yp=(-_off.a*_off.b*center.x+_off.a*_off.a*center.y-_off.b*_off.c)/(_off.a*_off.a+_off.b*_off.b);
        db ango=atan2(yp-center.y,xp-center.x);
        db angp=acos(td/r);
        return make_pair(Point(center.x+r*cos(ango+angp),center.y+r*sin(ango+angp)),Point(center.x+r*cos(ango-angp),center.y+r*sin(ango-angp)));
    }
    db area(Point p,Point q)
    {
        if(in_circle(p)&&in_circle(q)) return find_area(p,q,center);
        if(!in_circle(p)&&!in_circle(q))
        {
            Line l=Line(p,q);
            auto res=l.dis(center,true);
            if(res.F<r-eps&&res.S)
            {
                pair<Point,Point> pp=cross(l);
                if(dis2(pp.S,p)>dis2(pp.F,p)) swap(pp.F,pp.S);
                //if(xmult(pp.F,pp.S,p)>eps) swap(pp.F,pp.S);
                db ang=atan2(p.y-center.y,p.x-center.x)-atan2(pp.S.y-center.y,pp.S.x-center.x),ans=0.0;
                while(ang>PI+eps) ang-=2*PI;
                while(ang<-PI-eps) ang+=2*PI;
                ans+=fabs(ang)*r*r/2.0;
                ang=atan2(q.y-center.y,q.x-center.x)-atan2(pp.F.y-center.y,pp.F.x-center.x);
                while(ang>PI+eps) ang-=2*PI;
                while(ang<-PI-eps) ang+=2*PI;
                ans+=fabs(ang)*r*r/2.0;
                ans+=find_area(pp.F,pp.S,center);
                return ans;
            }
            db ang=atan2(p.y-center.y,p.x-center.x)-atan2(q.y-center.y,q.x-center.x);
            while(ang>PI+eps) ang-=2*PI;
            while(ang<-PI-eps) ang+=2*PI;
            return fabs(ang)*r*r/2.0;
        }
        if(in_circle(q)) swap(p,q);
        Point inter1=intersection(center,q),inter2=intersection(p,q);
        db ans=find_area(p,inter2,center);
        db ang=atan2(inter1.y-center.y,inter1.x-center.x)-atan2(inter2.y-center.y,inter2.x-center.x);
        while(ang>PI+eps) ang-=2*PI;
        while(ang<-PI-eps) ang+=2*PI;
        return ans+fabs(ang)*r*r/2.0;
    }
}c;
int main()
{
    freopen("mammoth.in","r",stdin);
    freopen("mammoth.out","w",stdout);
    scanf("%Lf%Lf%Lf",&c.center.x,&c.center.y,&c.r);
    scanf("%Lf%Lf%Lf%Lf",&x1,&y1,&x2,&y2);
    p[0]=Point(x1,y1); p[1]=Point(x1,y2); p[2]=Point(x2,y2); p[3]=Point(x2,y1);
    db ans=0.0;
    for(int i=0;i<4;i++)
    {
        if(xmult(c.center,p[i],p[(i+1)%4])>eps) ans+=c.area(p[i],p[(i+1)%4]); else ans-=c.area(p[i],p[(i+1)%4]);
    }
    printf("%.15Lf\n",fabs(ans));
    return 0;
}
