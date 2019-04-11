#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dsaida
#define y1 dksdoad
#define x2 daksoda
#define y2 sdoadda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
const db eps=1e-8;
const db PI=acos(-1.0);
const db step=1e-4;
int sgn(db ta, db tb)
{
    if(fabs(ta-tb)<eps) return 0;
    if(ta<tb) return -1;
    return 1;
}
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    bool operator <(const Point &_se) const
    {
        return x<_se.x||(x==_se.x&&y<_se.y);
    }
    friend Point operator +(const Point &_st,const Point &_se)
    {
        return Point(_st.x+_se.x,_st.y+_se.y);
    }
    friend Point operator -(const Point &_st,const Point &_se)
    {
        return Point(_st.x-_se.x,_st.y-_se.y);
    }
    Point operator *(const db v) const
    {
        return Point(x*v,y*v);
    }
    Point operator /(const db v)const
    {
        return Point(x/v,y/v);
    }
};
struct Rectangle
{
    Point p1,p2,p3,p4;
    Rectangle(){}
    Rectangle(Point _p1,Point _p2,Point _p3,Point _p4):p1(_p1),p2(_p2),p3(_p3),p4(_p4){}
};
db xmult(const Point &po,const Point &ps,const Point &pe)
{
    return (ps.x-po.x)*(pe.x-po.x)+(ps.y-po.y)*(pe.y-po.y);
}
bool inside(const Point &p,const Rectangle &r)
{
    if(xmult(r.p1,p,r.p2)<-eps) return false;
    if(xmult(r.p2,p,r.p3)<-eps) return false;
    if(xmult(r.p3,p,r.p4)<-eps) return false;
    if(xmult(r.p4,p,r.p1)<-eps) return false;
    return true;
}
bool inside(const Rectangle &r1,const Rectangle &r2)
{
    return inside(r1.p1,r2)&&inside(r1.p2,r2)&&inside(r1.p3,r2)&&inside(r1.p4,r2);
}
void regularize(db &ang)
{
    while(sgn(ang,2*PI)>0) ang-=2*PI;
    while(sgn(ang,0)<0) ang+=2*PI;
}
db get_angle(Point p,Point q)
{
    return atan2(q.y-p.y,q.x-p.x);
}
void rotate(Point &p, db ang)
{
    db xx=p.x*cos(ang)-p.y*sin(ang);
    db yy=p.x*sin(ang)+p.y*cos(ang);
    p.x=xx; p.y=yy;
}
Point p,q[4];
db x1,y1,s1,s2,s3;
int main()
{
    freopen("maps.in","r",stdin);
    freopen("maps.out","w",stdout);
    scanf("%Lf%Lf%Lf",&s1,&p.x,&p.y); 
    scanf("%Lf",&s2);
    scanf("%Lf",&s3);
    for(int i=0;i<4;i++) scanf("%Lf%Lf",&q[i].x,&q[i].y);
    Rectangle r1(Point(0,0),Point(p.x,0),p,Point(0,p.y)),r2(q[0],q[1],q[2],q[3]);
    Point center1=(Point(0.0,0.0)+p)/2,center2=(q[0]+q[2])/2;
    Point shift=center2-center1;
    Point v=center1-center1/s1*s3;
    db ang=get_angle(center1,q[0]-shift)-get_angle(center1,v);
    regularize(ang);
    //ax+by+c=0
    //dx+ey+f=0
    db r=s3/s1;
    db a=cos(ang)*r-1,b=-sin(ang)*r,c=shift.x;
    db d=sin(ang)*r,e=cos(ang)*r-1,f=shift.y;
    Point fixed;
    fixed.x=(c*e-b*f)/(b*d-a*e); fixed.y=(c*d-a*f)/(a*e-b*d); 
    Rectangle r3;
    for(db aa=0.0;aa<2*PI;aa+=step)
    {
        Point pos=fixed*s2/s1;
        rotate(pos,aa);
        Point sh=fixed-pos;
        Point pp=fixed*s2/s1; rotate(pp,aa); pp=pp+sh; 
        r3.p1=(r1.p1-center1)*s2/s1; rotate(r3.p1,aa); r3.p1=r3.p1+sh; r3.p1=r3.p1+center1;
        r3.p2=(r1.p2-center1)*s2/s1; rotate(r3.p2,aa); r3.p2=r3.p2+sh; r3.p2=r3.p2+center1;
        r3.p3=(r1.p3-center1)*s2/s1; rotate(r3.p3,aa); r3.p3=r3.p3+sh; r3.p3=r3.p3+center1;
        r3.p4=(r1.p4-center1)*s2/s1; rotate(r3.p4,aa); r3.p4=r3.p4+sh; r3.p4=r3.p4+center1;
        if(inside(r3,r1)&&inside(r2,r3))
        {
            printf("%.15Lf %.15Lf %.15Lf %.15Lf %.15Lf %.15Lf %.15Lf %.15Lf\n",r3.p1.x,r3.p1.y,r3.p2.x,r3.p2.y,r3.p3.x,r3.p3.y,r3.p4.x,r3.p4.y);
            return 0;
        }
    }
    puts("impossible");
    return 0;
}
