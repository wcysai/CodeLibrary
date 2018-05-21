#include<bits/stdc++.h>
#define MAXN 10
using namespace std;
double EPS= 1e-10;
double add(double a,double b)
{
    if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}
struct P
{
    double x,y;
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
}a[MAXN];
int n;
int perm[MAXN];
P p[MAXN],q[MAXN];
bool on_seg(P p1,P p2, P q)
{
    return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}
P intersection(P p1,P p2,P q1,P q2)
{
    return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}
bool intersect(int i,int j)
{
    if((p[i]-q[i]).det(p[j]-q[j])==0) return false;
    P r=intersection(p[i],q[i],p[j],q[j]);
    return on_seg(p[i],q[i],r)&&on_seg(p[j],q[j],r);
}
double find_res()
{
    for(int i=0;i<n-1;i++)
    {
        p[i].x=a[perm[i]].x,p[i].y=a[perm[i]].y;
        q[i].x=a[perm[i+1]].x;q[i].y=a[perm[i+1]].y;
    }
    p[n-1].x=a[perm[n-1]].x;p[n-1].y=a[perm[n-1]].y;q[n-1].x=a[perm[0]].x,q[n-1].y=a[perm[0]].y;
    bool f=true;
    for(int i=2;i<n;i++)
    {
        for(int j=i-2;j>=0;j--)
        {
            if(i==n-1&&j==0) continue;
            if(intersect(j,i)) {f=false; break;}
        }
        if(!f) break;
    }
    if(!f) return -1.0;
    double res=0;
    for(int i=0;i<n;i++)
        res=res+sqrt((p[i].x-q[i].x)*(p[i].x-q[i].x)+(p[i].y-q[i].y)*(p[i].y-q[i].y));
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
    for(int i=0;i<n;i++)
        perm[i]=i;
    double ans=0;
    ans=max(ans,find_res());
    while(next_permutation(perm,perm+n))
    {
        ans=max(ans,find_res());
    }
    printf("%.2f\n",ans);
    return 0;
}
