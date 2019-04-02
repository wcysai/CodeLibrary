#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 85
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double PI=acos(-1.0);
const double eps=1e-8;
int sgn(double ta,double tb)
{
    if(fabs(ta-tb)<eps) return 0;
    if(ta<tb) return -1;
    return 1;
}
struct Point
{
    double x,y;
    int id=-1;
    Point(){}
    Point(double tx,double ty){x=tx,y=ty;}

    bool operator <(const Point &_se) const
    {
        if(sgn(x,_se.x)!=0) return x<_se.x;
        if(sgn(y,_se.y)!=0) return y<_se.y;
        return false;
    }
    friend Point operator +(const Point &_st,const Point &_se)
    {
        return Point(_st.x+_se.x,_st.y+_se.y);
    }
    friend Point operator -(const Point &_st,const Point &_se)
    {
        return Point(_st.x-_se.x,_st.y-_se.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    bool operator == (const Point &_off)const
    {
        return sgn(x,_off.x)==0&&sgn(y,_off.y)==0;
    }
};
double xmult(const Point &po,const Point &ps,const Point &pe)
{
    return (ps.x-po.x)*(pe.y-po.y)-(pe.x-po.x)*(ps.y-po.y);
}
struct Line
{
    Point s,e;
    double a,b,c;
    double angle;
    int num;
    bool used=false;

    Line(){}
    Line(Point ts,Point te):s(ts),e(te){}
    Line(double _a,double _b,double _c):a(_a),b(_b),c(_c){}

    const bool operator <(const Line &ta) const
    {
        if(sgn(angle,ta.angle)!=0) return angle<ta.angle;
        return ((s-ta.s)^(ta.e-ta.s)) < 0;
    }

    bool pton()
    {
        a=e.y-s.y;
        b=s.x-e.x;
        c=e.x*s.y-e.y*s.x;
        return true;
    }
    double get_angle(bool isVector=true)
    {
        angle=atan2(e.y-s.y,e.x-s.x);
        if(!isVector&&angle<0) angle+=PI;
        return angle;
    }

    friend double operator /(const Line &_st,const Line &_se)
    {
        return (_st.e.x-_st.s.x)*(_se.e.y-_se.s.y)-(_st.e.y-_st.s.y)*(_se.e.x-_se.s.x);
    }

    bool has(const Point &_Off,bool isSegment=false) const
    {
        bool ff=sgn(xmult(s,e,_Off),0)==0;
        return ff;
    }
 
};

static bool parallel(const Line &_st,const Line &_se)
{
    return sgn(_st/_se,0)==0;
}

static int crossLPT(const Line &_st,const Line &_se, Point &ret)
{
    if(parallel(_st,_se)) return -1;
    ret=_st.s;
    double t=(Line(_st.s,_se.s)/_se)/(_st/_se);
    ret.x+=(_st.e.x-_st.s.x)*t;
    ret.y+=(_st.e.y-_st.s.y)*t;
    return 1;
}

double getdis(const Point &st,const Point &se)
{
    return sqrt((st.x - se.x) * (st.x - se.x) + (st.y - se.y) * (st.y - se.y));
}

int n;
vector<Line> lines;
set<Point> points;
vector<Point> pp;
vector<Line> outlines[MAXN*MAXN];
vector<double> ans;
vector<Point> tmp;
int main()
{
    freopen("areas.in","r",stdin);
    freopen("areas.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        Point s,e;
        scanf("%Lf%Lf%Lf%Lf",&s.x,&s.y,&e.x,&e.y);
        Line l(s,e);
        lines.push_back(l);
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            Point intersect;
            if(crossLPT(lines[i],lines[j],intersect)!=-1) 
            {
                bool f=true;
                for(auto p:points) if(p==intersect) f=false;
                if(f) points.insert(intersect);
            }
        }
    for(auto p:points) pp.push_back(p);
    for(auto l:lines)
    {
        tmp.clear();
        for(int i=0;i<(int)pp.size();i++)
        {
            if(l.has(pp[i]))
            {
                Point pt=pp[i];
                pt.id=i;
                tmp.push_back(pt);
            }
        }
        if(tmp.size()<2) continue;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<(int)tmp.size()-1;i++)
        {
            Line li(tmp[i],tmp[i+1]);
            li.get_angle(); li.num=tmp[i+1].id;
            outlines[tmp[i].id].push_back(li);
            //printf("%f %f %f %f %f\n",tmp[i].x,tmp[i].y,tmp[i+1].x,tmp[i+1].y,li.angle);
            Line gi(tmp[i+1],tmp[i]);
            gi.get_angle(); gi.num=tmp[i].id;
            outlines[tmp[i+1].id].push_back(gi);
        }
    } 
    for(int i=0;i<(int)pp.size();i++) sort(outlines[i].begin(),outlines[i].end());
    for(int i=0;i<(int)pp.size();i++)
    {
        for(auto &l:outlines[i])
        {
            if(l.used) continue;
            bool f=true;
            l.used=true;
            double area=0;
            Point from=l.s;
            Point to=l.e;
            Line curline=l;
            while(!(to==pp[i]))
            {
                //printf("from: %.4f %.4f to: %.4f %.4f\n",from.x,from.y,to.x,to.y);
                int num=curline.num;
                area+=from.x*to.y-to.x*from.y;
                Line reverseline=Line(to,from);
                reverseline.get_angle(); 
                int sz=(int)outlines[num].size();
                int lb=-1,rb=sz-1;
                while(rb-lb>1)
                {
                    int mid=(lb+rb)/2;
                    if(sgn(outlines[num][mid].angle,reverseline.angle)>0) rb=mid; else lb=mid;
                }
                int id=rb;
                if(sgn(outlines[num][sz-1].angle,reverseline.angle)==0) id=0;
                //if(sgn(outlines[num][id].angle,reverseline.angle)==0) {f=false; break;}
                double dangle=outlines[num][id].angle-reverseline.angle;
                while(sgn(dangle,0)<0) dangle+=2*PI;
                while(sgn(dangle,2*PI)>0) dangle-=2*PI;
                if(sgn(dangle,PI)>0) {f=false; break;}
                //printf("%d %d %d\n",num,(int)outlines[num].size(),id);
                if(outlines[num][id].used) {f=false; break;}
                outlines[num][id].used=true;
                curline=outlines[num][id];
                from=to; to=curline.e; 
            }
            if(f)
            {
                //puts("done");
                area+=from.x*to.y-to.x*from.y;
                if(fabs(area)>2*eps) ans.push_back(fabs(area/2.0));
            }
        }
    }
    printf("%d\n",(int)ans.size());
    sort(ans.begin(),ans.end());
    for(auto v:ans) printf("%.10Lf\n",v);
    return 0;
}
