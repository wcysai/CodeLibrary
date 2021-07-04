#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;

typedef double T;
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
const T PI=acos(-1.0);
const T eps=1e-10;

int sgn( double ta, double tb)
{
    if(fabs(ta-tb)<eps)return 0;
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
    const bool operator<(Point &p)const {return tie(x,y,z)<tie(p.x,p.y,p.z);}
};
Point zero{0,0,0};
T operator|(Point v, Point w) {return v.x*w.x + v.y*w.y + v.z*w.z;}
T sq(Point v) {return v|v;}
db abs(Point v) {return sqrt(sq(v));}
Point unit(Point v) {return v/abs(v);}
db angle(Point v, Point w) 
{
    db cosTheta=(v|w)/abs(v)/abs(w);
    return acos(max((db)-1.0,min((db)1.0,cosTheta)));
}
Point operator*(Point v,Point w) {return {v.y*w.z-v.z*w.y,v.z*w.x-v.x*w.z,v.x*w.y-v.y*w.x};}
T orient(Point p, Point q, Point r, Point s) {return (q-p)*(r-p)|(s-p);}
T orientByNormal(Point p, Point q, Point r, Point n) {return (q-p)*(r-p)|n;}
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

int t;
T A,B,C,x,y,z;
double r;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&A,&B,&C,&x,&y,&z);
        Point p=Point(A,B,C),q=Point(x,y,z),O=Point(0,0,0);
        
        printf("%.10f %.10f %.10f\n",p.x,p.y,p.z);
        
        printf("%.10f %.10f %.10f\n",q.x,q.y,q.z);
        Line l=Line(O,p);
        Point d=l.proj(q);
        printf("%.10f %.10f %.10f\n",d.x,d.y,d.z);
        Point a=q,b=q;
        
    }
    return 0;
}