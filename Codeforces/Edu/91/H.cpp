#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
int T;
double L,x,y,vx,vy,k;
const double PI=acos(-1.0);
ll getlvl(P p)
{
    p.S+=L*sqrt(3.0)/6.0;
    return (ll)(floor(p.S/(L*sqrt(3.0)/2.0)));
}
ll calc(P p,P q)
{
    ll x=getlvl(p),y=getlvl(q);
    return max(x-y,y-x);
}
void rotate(P &p,double ang)
{
    p=P(p.F*cos(ang)-p.S*sin(ang),p.F*sin(ang)+p.S*cos(ang));
}
ll get_num(double t)
{
    P p=P(x,y),q=P(x+vx*t,y+vy*t);
    ll res=calc(p,q);
    rotate(p,PI*2.0/3.0); rotate(q,PI*2.0/3.0);
    res+=calc(p,q);
    rotate(p,PI*2.0/3.0); rotate(q,PI*2.0/3.0);
    res+=calc(p,q);
    return res;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&L,&x,&y,&vx,&vy,&k);
        y-=L*sqrt(3.0)/6.0;
        double l=0.0,r=1e12;
        for(int i=0;i<200;i++)
        {
            double mid=(l+r)/2;
            if(get_num(mid)<k) l=mid; else r=mid;
        }
        printf("%.10f\n",l);
    }
    return 0;
}