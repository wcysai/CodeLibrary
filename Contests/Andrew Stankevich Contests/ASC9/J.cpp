#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 sadoasdl
#define y2 dakodsad
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
typedef double T;
const db PI=acos(-1.0);
const db eps=1e-10;
int sgn(db ta,db tb)
{
    if(fabs(ta-tb)<eps) return 0;
    if(ta<tb) return -1;
    return 1;
}
class Point
{
public:
    T x,y,z;
    Point(){}
    Point(T tx,T ty,T tz) {x=tx,y=ty,z=tz;}
    db dist2(Point p) {return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z);}
    db dist(Point p) {return sqrt(dist2(p));}
    Point operator+(Point p) {return {x+p.x,y+p.y,z+p.z};}
    Point operator-(Point p) {return {x-p.x,y-p.y,z-p.z};}
    Point operator*(T d) {return {x*d,y*d,z*d};}
    Point operator/(T d) {return {x/d,y/d,z/d};}
    bool operator==(Point p) {return tie(x,y,z)==tie(p.x,p.y,p.z);}
    bool operator!=(Point p) {return !operator==(p);}
    void read() {scanf("%lf%lf%lf",&x,&y,&z);}
    const bool operator<(Point &p)const {return tie(x,y,z)<tie(p.x,p.y,p.z);}
};
T operator|(Point v, Point w) {return v.x*w.x + v.y*w.y + v.z*w.z;}
Point operator*(Point v,Point w) {return {v.y*w.z-v.z*w.y,v.z*w.x-v.x*w.z,v.x*w.y-v.y*w.x};}
T sq(Point v) {return v|v;}
db abs(Point v) {return sqrt(sq(v));}
Point unit(Point v) {return v/abs(v);}
class Plane 
{
public:
    Point n; T d;
    Plane(){}
    Plane(Point n,T d) : n(n), d(d) {}
    Plane(Point n, Point p) : n(n), d(n|p) {}
    Plane(Point p, Point q, Point r) : Plane((q-p)*(r-p), p) {}
    T side(Point p) {return (n|p)-d;}
    db dist(Point p) {return abs(side(p))/abs(n);}
    Plane translate(Point t) {return {n,d+(n|t)};}
    Plane shiftup(db dist) {return {n,d+dist*abs(n)};}
    Point proj(Point p) {return p-n*side(p)/sq(n);}
    Point refl(Point p) {return p-n*2*side(p)/sq(n);}
};
class Line
{
public:
    Point d,o;
    Line(){}
    Line(Point p,Point q):d(q-p),o(p){}
    Line(Plane p1,Plane p2)
    {
        d=p1.n*p2.n;
        o=(p2.n*p1.d-p1.n*p2.d)*d/sq(d);
    }
    db dist2(Point p) {return sq(d*(p-o))/sq(d);}
    db dist(Point p) {return sqrt(dist2(p));}
    bool cmpProj(Point p,Point q) {return (d|p)<(d|q);}
    Point proj(Point p) {return o+d*(d|(p-o))/sq(d);}
    Point refl(Point p) {return proj(p)*2-p;}
    Point inter(Plane p) {return o-d*p.side(o)/(d|p.n);}
};
db R;
T point_to_cylinder(Point p1,Point &p2,Point &p3)
{
    db dist_to_line=abs((p2-p1)*(p3-p1))/p2.dist(p3);
    if(((p2-p3)|(p2-p1))<-eps)
    {
        db dist_to_face=(p2-p1)|(unit(p2-p3));
        return sqrt(dist_to_face*dist_to_face+max(dist_to_line-R,0.0)*max(dist_to_line-R,0.0));
    }
    else if(((p3-p2)|(p3-p1))<-eps)
    {
        db dist_to_face=(p3-p2)|(unit(p3-p1));
        return sqrt(dist_to_face*dist_to_face+max(dist_to_line-R,0.0)*max(dist_to_line-R,0.0));
    }
    else return sqrt(max(dist_to_line-R,0.0));
}
Point A,B,C,D,pp,qq;
db dis1,dis2;
int main()
{
    freopen("tracing.in","r",stdin);
    freopen("tracing.out","w",stdout);
    A.read(); B.read(); scanf("%lf",&R); C.read(); D.read();
    Point p=unit(D-C); 
    db l=0.0,r=20000.0;
    for(int i=0;i<200;i++)
    {
        db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
        pp=C+p*lb,qq=C+p*rb;
        dis1=point_to_cylinder(pp,A,B),dis2=point_to_cylinder(qq,A,B);
        if(!sgn(dis1,0)||dis1<dis2) r=rb; else l=lb;
    }
    if(dis1>1e-4||dis1<-1e-4) puts("NONE"); else printf("%.10lf %.10lf %.10lf\n",pp.x,pp.y,pp.z);
    return 0;
}
