/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 21:37:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double PI=3.1415926535;
const double eps=1e-10;
int sgn( double ta, double tb)
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

};

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

class Line
{
public:

    Point s,e;
    double a, b, c;
    double angle;

    Line(){}
    Line( Point ts, Point te):s(ts),e(te){}
    Line(double _a,double _b,double _c):a(_a),b(_b),c(_c){}
    bool operator < (const Line &ta)const
    {
        return angle<ta.angle;
    }
    friend double operator / ( const Line &_st, const  Line &_se)
    {
        return (_st.e.x - _st.s.x) * (_se.e.y - _se.s.y) - (_st.e.y - _st.s.y) * (_se.e.x - _se.s.x);
    }
    friend double operator *( const Line &_st, const  Line &_se)
    {
        return (_st.e.x - _st.s.x) * (_se.e.x - _se.s.x) - (_st.e.y - _st.s.y) * (_se.e.y - _se.s.y);
    }

    bool pton()
    {
        a = e.y - s.y;
        b = s.x - e.x;
        c = e.x * s.y - e.y * s.x;
        return true;
    }
    double dis(const Point &_Off, bool isSegment = false)
    {
        pton();
        double td = (a * _Off.x + b * _Off.y + c) / sqrt(a * a + b * b);
        if(isSegment)
        {
            double xp = (b * b * _Off.x - a * b * _Off.y - a * c) / ( a * a + b * b);
            double yp = (-a * b * _Off.x + a * a * _Off.y - b * c) / (a * a + b * b);
            double xb = max(s.x, e.x);
            double yb = max(s.y, e.y);
            double xs = s.x + e.x - xb;
            double ys = s.y + e.y - yb;
           if(xp > xb + eps || xp < xs - eps || yp > yb + eps || yp < ys - eps)
                td = min( getdis(_Off,s), getdis(_Off,e));
        }
        return fabs(td);
    }
};
Point gsort;
bool gcmp( const Point &ta, const Point &tb)
{
    double tmp = xmult( gsort, ta, tb);
    if( fabs( tmp) < eps)
        return getdis( gsort, ta) < getdis( gsort, tb);
    else if( tmp > 0)
        return 1;
    return 0;
}

class Polygon
{
public:
    const static int maxpn = 5e4+7;
    Point pt[maxpn];
    int n;


    void graham( Point _p[], int _n)
    {
        int cur=0;
        for(int i = 1; i < _n; i++)
            if( sgn( _p[cur].y, _p[i].y) > 0 || ( sgn( _p[cur].y, _p[i].y) == 0 && sgn( _p[cur].x, _p[i].x) > 0) )
                cur = i;
        swap( _p[cur], _p[0]);
        n = 0, gsort = pt[n++] = _p[0];
        if( _n <= 1)   return;
        sort( _p + 1, _p+_n ,gcmp);
        pt[n++] = _p[1];
        for(int i = 2; i < _n; i++)
        {
            while(n>1 && sgn( xmult( pt[n-2], pt[n-1], _p[i]), 0) <= 0)// 当凸包退化成直线时需特别注意n
                n--;
            pt[n++] = _p[i];
        }
    }
}Poly;
int n;
Point p[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    Poly.graham(p,n);
    n=Poly.n;
    double ans=0;
    for(int i=0;i<n;i++)
        ans+=getdis(Poly.pt[i],Poly.pt[(i+1)%n]);
    printf("%.10f\n",ans*PI);
    return 0;
}

