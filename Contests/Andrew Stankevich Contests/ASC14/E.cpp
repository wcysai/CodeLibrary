#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long double db;
const db PI=acos(-1.0);
const db eps=1e-12;
int sgn(db ta, db tb)
{
    if(fabs(ta-tb)<eps)return 0;
    if(ta<tb) return -1;
    return 1;
};
struct Point
{
    db x, y;
    int id;
    Point(){}
    Point( db tx, db ty){ x = tx, y = ty;}

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
    db operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    bool operator == (const Point &_off)const
    {
        return  sgn(x, _off.x) == 0 && sgn(y, _off.y) == 0;
    }
};
db getdis(const Point &st,const Point &se)
{
    return sqrt((st.x - se.x) * (st.x - se.x) + (st.y - se.y) * (st.y - se.y));
}
Point p[MAXN];
db r[MAXN];
void tangent(Point &p1,Point &p2,int r1,int r2,Point &q1,Point &q2)
{
    Point d=p2-p1;
    db dis=getdis(p1,p2);
    db t=(r1-r2)/dis;
    db ang1=asin(t)-atan2(d.x,d.y),ang2=PI-asin(t)-atan2(d.x,d.y);
    q1=Point(p1.x+r1*cos(ang1),p1.y+r1*sin(ang1));
    q2=Point(p1.x+r1*cos(ang2),p1.y+r1*sin(ang2));
    q1.id=q2.id=p1.id;
}
int n;
vector<Point> v,ch;
Point gsort;
db xmult(const Point &po,const Point &ps,const Point &pe)
{
    return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
}

void ConvexClosure()
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0; i < (int)v.size(); i++)
    {
        int n=(int)ch.size();
        while( n > 1 && sgn( xmult( ch[n-2], ch[n-1], v[i]), 0) <= 0) 
        {
            n--;
            ch.pop_back();
        }
        ch.push_back(v[i]);
    }
    int _key = (int)ch.size();
    for(int i = (int)v.size() - 2; i >= 0; i--)
    {
        int n=(int)ch.size();
        while( n > _key && sgn( xmult( ch[n-2], ch[n-1], v[i]), 0) <= 0)
        {
            n--;
            ch.pop_back();
        }
        ch.push_back(v[i]);
    }
    ch.pop_back();
}
int main()
{
    freopen("murder.in","r",stdin);
    freopen("murder.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%Lf%Lf",&p[i].x,&p[i].y);
        scanf("%Lf",&r[i]);
        p[i].id=i;
    }
    if(n==1)
    {
        printf("%.15Lf\n",2*PI*r[0]);
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            Point q1,q2;
            tangent(p[i],p[j],r[i],r[j],q1,q2);
            v.push_back(q1); v.push_back(q2);
        }
    }
    ConvexClosure();
    db ans=0.0;
    for(int i=0;i<(int)ch.size();i++)
    {
        int num=(i+1)%(int)ch.size();
        if(ch[i].id!=ch[num].id) ans+=getdis(ch[i],ch[num]);
        else
        {
            int c=ch[i].id;
            db ang=atan2(ch[num].y-p[c].y,ch[num].x-p[c].x)-atan2(ch[i].y-p[c].y,ch[i].x-p[c].x);
            while(ang<-eps) ang+=2*PI;
            while(ang>=2*PI) ang-=2*PI;
            ans+=ang*r[c];
        }
    }
    printf("%.15Lf\n",ans);
    return 0;
}
