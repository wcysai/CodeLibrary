/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 16:26:36
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll; 
const double PI=acos(-1.0);
const double eps=1e-10;
int t,n,k;
int sgn(double ta,double tb)
{
    if(fabs(ta-tb)<eps)return 0;
    if(ta<tb)   return -1;
    return 1;
}
class Point
{
public:
    double x, y;
    Point(){}
    Point( double tx, double ty){ x = tx, y = ty;}

    bool operator < (const Point &_se) const
    {
        return x<_se.x || (x==_se.x && y<_se.y);
    }
    friend Point operator + (const Point &_st,const Point &_se)
    {
        return Point(_st.x + _se.x, _st.y + _se.y);
    }
    friend Point operator - (const Point &_st,const Point &_se)
    {
        return Point(_st.x - _se.x, _st.y - _se.y);
    }
    bool operator == (const Point &_off)const
    {
        return  sgn(x, _off.x) == 0 && sgn(y, _off.y) == 0;
    }
}a[MAXN];
double dot(const Point &po,const Point &ps,const Point &pe)
{
    return (ps.x - po.x) * (pe.x - po.x) + (ps.y - po.y) * (pe.y - po.y);
}
double xmult(const Point &po,const Point &ps,const Point &pe)
{
    return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
}
double getdis2(const Point &st,const Point &se)
{
    return (st.x - se.x) * (st.x - se.x) + (st.y - se.y) * (st.y - se.y);
}
double getdis(const Point &st,const Point &se)
{
    return sqrt((st.x - se.x) * (st.x - se.x) + (st.y - se.y) * (st.y - se.y));
}
class triangle
{
public:
    Point a, b, c;
    triangle(){}
    triangle(Point a, Point b, Point c): a(a), b(b), c(c){}
    double area()
    {
        return fabs( xmult(a, b, c)) / 2.0;
    }
    Point circumcenter()
    {
        double pa = a.x * a.x + a.y * a.y;
        double pb = b.x * b.x + b.y * b.y;
        double pc = c.x * c.x + c.y * c.y;
        double ta = pa * ( b.y - c.y) - pb * ( a.y - c.y) + pc * ( a.y - b.y);
        double tb = -pa * ( b.x - c.x) + pb * ( a.x - c.x) - pc * ( a.x - b.x);
        double tc = a.x * ( b.y - c.y) - b.x * ( a.y - c.y) + c.x * ( a.y - b.y);
        return Point( ta / 2.0 / tc, tb / 2.0 / tc);
    }
};
class Line
{
public:

    Point s, e;
    double a, b, c;
    double angle;

    Line(){}
    Line( Point ts, Point te):s(ts),e(te){}
    Line(double _a,double _b,double _c):a(_a),b(_b),c(_c){}

    bool has(const Point &_Off, bool isSegment = false) const
    {
        bool ff = sgn( xmult( s, e, _Off), 0) == 0;
        if( !isSegment) return ff;
        return ff
            && sgn(_Off.x - min(s.x, e.x), 0) >= 0 && sgn(_Off.x - max(s.x, e.x), 0) <= 0
            && sgn(_Off.y - min(s.y, e.y), 0) >= 0 && sgn(_Off.y - max(s.y, e.y), 0) <= 0;
    }
};
int main()
{
    scanf("%d",&t);
    srand(time(NULL));
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        if(n==1)
        {
            printf("%.6f %.6f %.6f\n",a[0].x,a[0].y,0.0);
            continue;
        }
        if(n<=4)
        {
            double x1=(a[0].x+a[1].x)/2;
            double y1=(a[0].y+a[1].y)/2;
            Point p=Point(x1,y1);
            printf("%.6f %.6f %.6f\n",x1,y1,getdis(p,a[0]));
            continue;
        }
        while(true)
        {
            int p1=rand()%(n+1),p2=rand()%(n+1),p3=rand()%(n+1);
            Point p=triangle(a[p1],a[p2],a[p3]).circumcenter();
            double r=getdis(p,a[p1]);
            int cnt=0;
            for(int i=0;i<n;i++)
                if(sgn(r,getdis(p,a[i]))==0) cnt++;
            if(cnt>=(n+1)/2)
            {
                printf("%.6lf %.6lf %.6lf\n",p.x,p.y,r);
                break;
            }
        }
    }
    return 0;
}

