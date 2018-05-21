#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-5
#define x first
#define y second
using namespace std;
typedef long long ll;
struct point
{
	double x,y;
};  
struct line{point a,b;};
 point a,b,c,p;
 
 bool eq(point a,point b)
 {
 	return max(a.x-b.x,b.x-a.x)<eps&&max(a.y-b.y,b.y-a.y)<eps;
 }
point intersection(line u,line v){  
    point ret=u.a;  
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))  
            /((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));  
    ret.x+=(u.b.x-u.a.x)*t;  
    ret.y+=(u.b.y-u.a.y)*t;  
    return ret;  
}  
  
  
//外心  
point circumcenter(point a,point b,point c){  
    line u,v;  
    u.a.x=(a.x+b.x)/2;  
    u.a.y=(a.y+b.y)/2;  
    u.b.x=u.a.x-a.y+b.y;  
    u.b.y=u.a.y+a.x-b.x;  
    v.a.x=(a.x+c.x)/2;  
    v.a.y=(a.y+c.y)/2;  
    v.b.x=v.a.x-a.y+c.y;  
    v.b.y=v.a.y+a.x-c.x;  
    return intersection(u,v);  
}  
  
  
//内心  
point incenter(point a,point b,point c){  
    line u,v;  
    double m,n;  
    u.a=a;  
    m=atan2(b.y-a.y,b.x-a.x);  
    n=atan2(c.y-a.y,c.x-a.x);  
    u.b.x=u.a.x+cos((m+n)/2);  
    u.b.y=u.a.y+sin((m+n)/2);  
    v.a=b;  
    m=atan2(a.y-b.y,a.x-b.x);  
    n=atan2(c.y-b.y,c.x-b.x);  
    v.b.x=v.a.x+cos((m+n)/2);  
    v.b.y=v.a.y+sin((m+n)/2);  
    return intersection(u,v);  
}  
  
  
//垂心  
point perpencenter(point a,point b,point c){  
    line u,v;  
    u.a=c;  
    u.b.x=u.a.x-a.y+b.y;  
    u.b.y=u.a.y+a.x-b.x;  
    v.a=b;  
    v.b.x=v.a.x-a.y+c.y;  
    v.b.y=v.a.y+a.x-c.x;  
    return intersection(u,v);  
}  
  
  
//重心  
//到三角形三顶点距离的平方和最小的点  
//三角形内到三边距离之积最大的点  
point barycenter(point a,point b,point c){  
    line u,v;  
    u.a.x=(a.x+b.x)/2;  
    u.a.y=(a.y+b.y)/2;  
    u.b=c;  
    v.a.x=(a.x+c.x)/2;  
    v.a.y=(a.y+c.y)/2;  
    v.b=b;  
    return intersection(u,v);  
}  
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&p.x,&p.y);
	if(eq(p,circumcenter(a,b,c))||eq(p,incenter(a,b,c))||eq(p,perpencenter(a,b,c))||eq(p,barycenter(a,b,c))) puts("Yes"); else puts("No");
	return 0;

}