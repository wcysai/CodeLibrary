#include<bits/stdc++.h>
#define MAXN 85
#define INF 1000000000
#define MOD 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
const db PI=acos(-1.0);
const db eps=1e-8;
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
    Point(db tx,db ty){x=tx,y=ty;}
    void print()
    {
        printf("%.10f %.10f\n",x,y);
    }
    bool operator<(const Point &q) const
    {
        return x<q.x||(x==q.x&&y<q.y);
    }
    friend Point operator + (const Point &_st,const Point &_se)
    {
        return Point(_st.x+_se.x,_st.y+_se.y);
    }
    friend Point operator -(const Point &p,const Point &q)
    {
        return Point(p.x-q.x,p.y-q.y);
    }
    friend Point operator /(const Point &p,const db v)
    {
        return Point(p.x/v,p.y/v);
    }
    friend Point operator *(const Point &p,const db v)
    {
        return Point(p.x*v,p.y*v);
    }
    db operator ^ (const Point &b) const
    {
        return x*b.y-y*b.x;
    }
    bool operator == (const Point &_off) const
    {
        return sgn(x,_off.x)==0&&sgn(y,_off.y)==0;
    }
};
db xmult(const Point &po,const Point &ps,const Point &pe)
{
    return (ps.x-po.x)*(pe.y-po.y)-(pe.x-po.x)*(ps.y-po.y);
}
db getdis(const Point &st,const Point &se)
{
    return sqrt((st.x-se.x)*(st.x-se.x)+(st.y-se.y)*(st.y-se.y));
}
db tri(const Point &a,const Point &b,const Point &c)
{
    return (b-a)^(c-a);
}
struct Line
{
    Point s,e;
    db a,b,c;
    db ang;
    Line(){}
    Line(Point ts,Point te):s(ts),e(te){}
    Line(db _a,db _b,db _c):a(_a),b(_b),c(_c){}

    bool pton()
    {
        a=e.y-s.y;
        b=s.x-e.x;
        c=e.x*s.y-e.y*s.x;
        return true;
    }

    friend db operator /(const Line &_st,const Line &_se)
    {
        return (_st.e.x-_st.s.x)*(_se.e.y-_se.s.y)-(_st.e.y-_st.s.y)*(_se.e.x-_se.s.x);
    }
 
}; 
static bool parallel(const Line &_st,const Line &_se)
{
    return sgn(_st/_se,0)==0;
}
static bool crossLPt(const Line &_st,const Line &_se,Point &ret)
{
    db ta=tri(_st.s,_st.e,_se.s);
    db tb=tri(_st.s,_st.e,_se.e);
    if(!sgn(ta,0)&&!sgn(tb,0)) return 0;
    if(!sgn(ta-tb,0)) return 0;
    ret=(_se.s*tb-_se.e*ta)/(tb-ta);
    return 1;
}
static bool isCrossSS(const Line &_st,const Line &_se,bool f=false)
{
    if(parallel(_st,_se)) return false;
    if(sgn(max(_st.s.x, _st.e.x) , min(_se.s.x, _se.e.x))<=0 ||
        sgn(max(_se.s.x, _se.e.x) , min(_st.s.x, _st.e.x))<=0 ||
        sgn(max(_st.s.y, _st.e.y) , min(_se.s.y, _se.e.y))<=0 ||
        sgn(max(_se.s.y, _se.e.y) , min(_st.s.y, _st.e.y))<=0 ) return false;
if(f)printf("xmult %lf %lf\n",xmult(_st.s,_se.s,_st.e)*xmult( _st.s, _se.e, _st.e),xmult( _se.s, _st.s, _se.e)*xmult( _se.s, _st.e, _se.e));
    return
        
        xmult( _st.s, _se.s, _st.e) * xmult( _st.s, _se.e, _st.e) < -1e-4 &&
         xmult( _se.s, _st.s, _se.e) * xmult( _se.s, _st.e, _se.e) < -1e-4;
};
Point gsort;
bool gcmp(const Point &ta,const Point &tb)
{
    db tmp=xmult(gsort,ta,tb);
    if(fabs(tmp)<eps) return getdis(gsort,ta)<getdis(gsort,tb);
    else if(tmp>0) return 1;
    return 0;
}
struct Polygon
{
    const static int maxpn=80;
    Point pt[maxpn];
    int n;
    db area()
    {
        db ans = 0.0;
        for(int i=0;i<n;i++)
        {
            int nt=(i+1)%n;
            ans+=pt[i].x*pt[nt].y-pt[nt].x*pt[i].y;
        }
        return fabs(ans/2.0);
    }
    void orient()
    {
        db ans = 0.0;
        for(int i=0;i<n;i++)
        {
            int nt=(i+1)%n;
            ans+=pt[i].x*pt[nt].y-pt[nt].x*pt[i].y;
        }
        if(ans>0) reverse(pt,pt+n);
    }
    void graham(Point _p[],int _n)
    {
        int cur=0;
        for(int i=1;i<_n;i++)
            if(sgn(_p[cur].y,_p[i].y)>0||(sgn(_p[cur].y,_p[i].y)==0&&sgn(_p[cur].x,_p[i].x)>0)) cur=i;
        swap(_p[cur],_p[0]);
        n=0,gsort=pt[n++]=_p[0];
        if(_n<=1) return;
        sort(_p+1,_p+_n,gcmp);
        pt[n++]=_p[1];
        for(int i=2;i<_n;i++)
        {
            while(n>1&&sgn(xmult(pt[n-2],pt[n-1],_p[i]),0)<=0) n--;
            pt[n++]=_p[i];
        }
    }
    bool has(const Point &p)
    {
        //return false;
        if(n<3) return false;
        if(xmult(pt[0],p,pt[1])>-eps) return false;
        if(xmult(pt[0],p,pt[n-1])<eps) return false;
        int l=2,r=n-1;
        int line=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(xmult(pt[0],p,pt[mid])<-eps) line=mid,r=mid-1;
            else l=mid+1;
        }
        return xmult(pt[line-1],p,pt[line])<-eps;
    }
};
Point pt[MAXN];
Polygon pg;
int n;
db ans=INF;
Point pa,pb,pc;
db triangle_area(const Point &a,const Point &b,const Point &c)
{
    db ans=0.0;
    ans+=a.x*b.y-b.x*a.y;
    ans+=b.x*c.y-c.x*b.y;
    ans+=c.x*a.y-a.x*c.y;
    return fabs(ans/2.0);
};
bool check_valid(Point a,Point b,Point c)
{ 
    bool f=false;
    if(pg.has(a)||pg.has(b)||pg.has(c)) return false;
    //if(f) assert(0);
    if(sgn(tri(a,b,c),pg.area())<0) return false;
    //if(f) assert(0);
    for(int i=0;i<pg.n;i++)
    {
        if(f) printf("id=%d\n",i);
        int nxt=(i+1)%pg.n;
        Line l=Line(pg.pt[i],pg.pt[nxt]);
        if(isCrossSS(l,Line(a,b),f)) return false;
        if(isCrossSS(l,Line(b,c),f)) return false;
        if(isCrossSS(l,Line(c,a),f)) return false;
    }
    //if(f) assert(0);
    return true;
}
void update_ans(const Point &a,const Point &b,const Point &c,bool checkstatus=true)
{
    //if (checkstatus) {if(!check_valid(a,b,c)) return;}
    db area=tri(a,b,c);
    if(area>eps&&area<ans)
    {
        ans=area;
        pa=a; pb=b; pc=c;
    }
}
int main()
{
    freopen("wall.in","r",stdin);
    freopen("wall.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lf%lf",&pt[i].x,&pt[i].y);
    pg.graham(pt,n); 
    //three lines of polygon
    int nn=pg.n;
    //printf("%d\n",nn);
    for(int i=0;i<nn;i++)
        for(int j=i+1;j<nn;j++)
            for(int k=j+1;k<nn;k++)
            {
                Line la,lb,lc;
                la=Line(pg.pt[i],pg.pt[(i+1)%nn]);
                lb=Line(pg.pt[j],pg.pt[(j+1)%nn]);
                lc=Line(pg.pt[k],pg.pt[(k+1)%nn]);
                Point a,b,c;
                if(!crossLPt(la,lb,a)) continue;
                if(!crossLPt(lb,lc,b)) continue;
                if(!crossLPt(lc,la,c)) continue;
                /*if(!sgn(a.x,-871.4382322842)||!sgn(b.x,-871.4382322842)||!sgn(c.x,-871.4382322842))
                {
                    a.print(); b.print(); c.print();
                    printf("\n");
                }*/
                //printf("%f\n",tri(a,b,c));
                if(tri(a,b,c)>0&&tri(a,b,c)<ans)
                {
                    ans=tri(a,b,c);
                    pa=a; pb=b; pc=c;
                }
            }
    //two lines and a vertex
    for(int i=0;i<nn;i++)
        for(int j=i+1;j<nn;j++)
        {
            Line la,lb;
            Point pp,q1,q2;
            la=Line(pg.pt[i],pg.pt[(i+1)%nn]);
            lb=Line(pg.pt[j],pg.pt[(j+1)%nn]);
            if(!crossLPt(la,lb,pp)) continue;
            if(getdis(pg.pt[i],pp)>getdis(pg.pt[(i+1)%nn],pp)) q1=pg.pt[i]; else q1=pg.pt[(i+1)%nn];
            if(getdis(pg.pt[j],pp)>getdis(pg.pt[(j+1)%nn],pp)) q2=pg.pt[j]; else q2=pg.pt[(j+1)%nn];
            int g=sgn(tri(q1,q2,pp),0);
            for(int k=0;k<nn;k++)
            {
                if(!sgn(tri(pp,q1,pg.pt[k]),0)||!sgn(tri(pp,q2,pg.pt[k]),0)||sgn(tri(q1,q2,pg.pt[k])*g,0)>=0) continue;
                Point p2=pg.pt[k]+pg.pt[k]-pp;
                Point p3=p2+q2-pp;
                Point p4,p5;
                crossLPt(Line(pp,q1),Line(p2,p3),p4);
                crossLPt(Line(pp,q2),Line(p4,pg.pt[k]),p5);
                if(sgn(tri(p4,p5,pg.pt[(k+1)%nn])*g,0)>=0&&sgn(tri(p4,p5,pg.pt[(k-1+nn)%nn])*g,0)>=0)
                {
                    db d=fabs(tri(pp,p4,p5));
                    if(d<ans)
                    {
                        ans=d;
                        pa=pp; pb=p4; pc=p5;
                    }
                }
            }
        }
    printf("%.10f %.10f \n%.10f %.10f\n%.10f %.10f\n",pa.x,pa.y,pb.x,pb.y,pc.x,pc.y);
    return 0;
}
