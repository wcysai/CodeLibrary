#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 daoksd
#define x2 dkoadads
#define y1 dsakodas
#define y2 ckodsda
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<db,db> P;
const db eps=1e-8;
db a,b,c,d,allx,ally;
P solve1(db y1,db y2)
{
    db bx=(y1+y2)/2*b+(y1/2+(y2-y1)/3)*a;
    if(y1>y2) swap(y1,y2);
    db by=(y1+y2)/2*d+(y2*y2/2+(y2+y1)*y1/2-(y2*y2+y1*y1+y1*y2)/3)*c;
    return make_pair(abs(bx-allx),abs(by-ally));
}
P solve2(db x1,db x2)
{
    db by=(x1+x2)/2*d+(x1/2+(x2-x1)/3)*c;
    if(x1>x2) swap(x1,x2);
    db bx=(x1+x2)/2*b+(x2*x2/2+(x2+x1)*x1/2-(x2*x2+x1*x1+x2*x1)/3)*a;
    return make_pair(abs(bx-allx),abs(by-ally));
}
P solve3(db x1,db y1)
{
    db bx=x1*y1/2*b+((x1*x1-3*x1+3)/3-(2-x1)*(1-x1)/2)*a*y1;
    db by=x1*y1/2*d+((y1*y1-3*y1+3)/3-(2-y1)*(1-y1)/2)*c*x1;
    return make_pair(abs(bx-allx),abs(by-ally));
}
P ts1(db x1)
{
    db l=0.0,r=1.0;
    for(int i=0;i<200;i++)
    {
        db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
        if(solve1(x1,lb).S>solve1(x1,rb).S) l=lb; else r=rb;
    }
    return make_pair(x1,l);
}
P ts2(db y1)
{
    db l=0.0,r=1.0;
    for(int i=0;i<200;i++)
    {
        db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
        if(solve2(y1,lb).S>solve2(y1,rb).S) l=lb; else r=rb;
    }
    return make_pair(y1,l);
}
P ts3(db x1)
{
    db l=0.0,r=1.0;
    for(int i=0;i<200;i++)
    {
        db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
        if(solve3(x1,lb).F>solve3(x1,rb).F) l=lb; else r=rb;
    }
    return make_pair(x1,l);
}
int main()
{
    freopen("bacteria.in","r",stdin);
    freopen("bacteria.out","w",stdout);
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    allx=b+0.5*a,ally=d+0.5*c; allx/=2.0; ally/=2.0;
    db l=0.0,r=1.0;
    for(int i=0;i<200;i++)
    {
        db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
        if(solve1(lb,ts1(lb).S).F>solve1(rb,ts1(rb).S).F) l=lb; else r=rb;
    }
    auto res=solve1(l,ts1(l).S);
    if(res.F<eps&&res.S<eps)
    {
        db y1=l,y2=ts1(l).S;
        printf("%.10f %.10f %.10f\n",y1-y2,1.0,-y1);
        return 0;
    }
    l=0.0,r=1.0;
    for(int i=0;i<200;i++)
    {
        db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
        if(solve2(lb,ts2(lb).S).F>solve2(rb,ts2(rb).S).F) l=lb; else r=rb;
    }
    res=solve2(l,ts2(l).S);
    if(res.F<eps&&res.S<eps)
    {
        db x1=l,x2=ts2(l).S;
        printf("%.10f %.10f %.10f\n",-1.0,x2-x1,x1);
        return 0;
    }
    l=0.0,r=1.0;
    for(int i=0;i<200;i++)
    {
        db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
        if(solve3(lb,ts3(lb).S).S>solve3(rb,ts3(rb).S).S) l=lb; else r=rb;
    } 
    res=solve3(l,ts3(l).S);
    if(res.F<eps&&res.S<eps)
    {
        db x1=l,y1=ts3(l).S;
        printf("%.10f %.10f %.10f\n",y1,x1,x1*y1-x1-y1);
        return 0;
    }
    puts("0 0 0");
    return 0;
}
