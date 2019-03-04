#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
double EPS= 1e-10;
const double PI=acos(-1.0);
double add(double a,double b)
{
    if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}
struct P
{
    double x,y;
    int id;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator +(P p)
    {
        return P(add(x,p.x),add(y,p.y));
    }
    P operator -(P p)
    {
        return P(add(x,-p.x),add(y,-p.y));
    }
    P operator *(double d)
    {
        return P(x*d,y*d);
    }
    double dot(P p)
    {
        return add(x*p.x,y*p.y);
    }
    double det(P p)
    {
        return add(x*p.y,-y*p.x);
    }
};
bool cmp_x(const P& p,const P& q)
{
    if (p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
vector<P> convex_hull(P* ps,int n)
{
    sort(ps,ps+n,cmp_x);
    int k=0;
    vector<P> qs(n*2);
    for(int i=0;i<n;i++)
    {
        while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--)
    {
        while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
double dist(P p,P q)
{
    return sqrt((p-q).dot(p-q));
}
int N;
P ps[MAXN];
double ans[MAXN];
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%lf %lf",&ps[i].x,&ps[i].y);
        ps[i].id=i;
    }
    vector<P> qs=convex_hull(ps,N);
    for(int i=0;i<(int)qs.size();i++)
    {
        int last=i-1;if(last<0) last+=(int)qs.size();
        int nxt=i+1;if(nxt>=(int)qs.size()) nxt-=(int)qs.size();
        double ang1=atan2((qs[i]-qs[last]).x,(qs[i]-qs[last]).y);
        double ang2=atan2((qs[i]-qs[nxt]).x,(qs[i]-qs[nxt]).y);
        double ang=ang2-ang1;
        while(ang<0) ang+=2*PI;
        while(ang>2*PI) ang-=2*PI;
        if(ang>PI) ang=2*PI-ang;
        ans[qs[i].id]=(PI-ang)/(2*PI);
    }
    for(int i=0;i<N;i++) printf("%.15f\n",ans[i]);
    return 0;
}
