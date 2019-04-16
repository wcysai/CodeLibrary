#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
const db PI=acos(-1.0);
const db eps=1e-12;
int sgn(db ta,db tb)
{
    if(fabs(ta-tb)<eps) return 0;
    if(ta<tb) return -1;
    return 1;
}
struct Point
{
    db x,y;
    Point(){}
    Point(db tx,db ty) {x=tx,y=ty;}
    friend Point operator + (const Point &_st,const Point &_se)
    {
        return Point(_st.x + _se.x, _st.y + _se.y);
    }
    friend Point operator - (const Point &_st,const Point &_se)
    {
        return Point(_st.x - _se.x, _st.y - _se.y);
    }
};
double getdis(const Point &st,const Point &se)
{
    return sqrt((st.x - se.x) * (st.x - se.x) + (st.y - se.y) * (st.y - se.y));
}
struct Circle
{
    Point c;
    db r;
    Circle(){}
    Circle(Point p,db _r):c(p),r(_r){}
    pair<Point,Point> tangent(Point &p)
    {
        db d=getdis(c,p);
        db angp=acos(r/d),ango=atan2(p.y-c.y,p.x-c.x);
        Point pl=Point(c.x+r*cos(ango+angp),c.y+r*sin(ango+angp));
        Point pr=Point(c.x+r*cos(ango-angp),c.y+r*sin(ango-angp));
        return make_pair(pl,pr);
    }
};
int r,c;
db x,y;
vector<Circle> red,color;
string str;
Point p;
int main()
{
    freopen("snooker.in","r",stdin);
    freopen("snooker.out","w",stdout);
    scanf("%d%d",&r,&c);
    cin>>str;
    scanf("%lf%lf",&p.x,&p.y);
    for(int i=0;i<r;i++)
    {
        scanf("%lf%lf",&x,&y);
        Point pp=Point(x,y);
        red.push_back(Circle(pp,2.0));
    }
    for(int i=0;i<c;i++)
    {
        scanf("%lf%lf",&x,&y);
        Point pp=Point(x,y);
        color.push_back(Circle(pp,2.0));
    }
    if(str[0]=='C') swap(red,color);
    for(auto c:red)
    {
        auto res=c.tangent(p);
        db l=atan2(res.F.y-p.y,res.F.x-p.x);
        db r=atan2(res.S.y-p.y,res.S.x-p.x);
        db dif=r-l;
        vector<pair<db,int> > v; v.clear();
        while(sgn(dif,0)<0) dif+=2*PI;
        while(sgn(dif,2*PI)>0) dif-=2*PI;
        while(sgn(l,0)<0) l+=2*PI;
        while(sgn(l,2*PI)>0) l-=2*PI;
        v.push_back(make_pair(l,-1)); v.push_back(make_pair(l+dif,1));
        for(auto cc:color)
        {
            if(sgn(getdis(cc.c,p),getdis(c.c,p))>0) continue;
            auto ret=cc.tangent(p);
            db lb=atan2(ret.F.y-p.y,ret.F.x-p.x);
            db rb=atan2(ret.S.y-p.y,ret.S.x-p.x);
            db dd=rb-lb;
            while(sgn(dd,0)<0) dd+=2*PI;
            while(sgn(dd,2*PI)>0) dd-=2*PI;
            while(sgn(lb,0)<0) lb+=2*PI;
            while(sgn(lb,2*PI)>0) lb-=2*PI;
            for(int k=-1;k<=1;k++)
            {
                v.push_back(make_pair(lb+k*2*PI,1)); 
                v.push_back(make_pair(lb+dd+k*2*PI,-1));
            }
        }
        sort(v.begin(),v.end());
        int cur=0;
        for(auto p:v) 
        {
            cur+=p.S;
            if(cur==-1)
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
