#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double PI = acos(-1.0);
const double eps = 1e-10;
int n,r;
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
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    bool operator == (const Point &_off)const
    {
        return  sgn(x, _off.x) == 0 && sgn(y, _off.y) == 0;
    }
};
Point a[MAXN];
Point get_point(double angle)
{
    return Point(r*cos(angle),r*sin(angle));
}
double get_ans(double angle)
{
    Point p=get_point(angle);
    double maxi=-INF,mini=INF;
    for(int i=0;i<n;i++)
    {
        double ang=atan2(a[i].y-p.y,a[i].x-p.x)-atan2(-p.y,-p.x);
        while(sgn(ang,PI)>0) ang-=2*PI;
        while(sgn(ang,-PI)<0) ang+=2*PI;
        maxi=max(maxi,ang);
        mini=min(mini,ang);
    }
    double res=maxi-mini;
    return res;
}
const int k=200;
int main()
{
    freopen("secret.in","r",stdin);
    freopen("secret.out","w",stdout);
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
    double ans=0.0;
    Point pans=Point(0.0,0.0);
    for(int i=0;i<k;i++)
    {
        double l=2*PI/k*i,r=2*PI/k*(i+1);
        for(int iter=0;iter<50;iter++)
        {
            double lmid=l+(r-l)/3.0,rmid=l+(r-l)*2.0/3.0;
            if(get_ans(lmid)<get_ans(rmid)) l=lmid; else r=rmid;
        }
        if(get_ans(l)>ans)
        {
            ans=get_ans(l);
            pans=get_point(l);
        }
    }
    printf("%.8f %.8f\n",pans.x,pans.y);
    return 0;
}
