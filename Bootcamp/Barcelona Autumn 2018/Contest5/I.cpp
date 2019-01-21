/*************************************************************************
    > File Name: I.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 17:46:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
ll n,k,a[MAXN];
struct Point
{
    db x,y;
    Point(){}
    Point(db xx,db yy){x=xx;y=yy;}
}P[MAXN];
typedef Point Vector;
Vector operator + (Vector A, Vector B)
{
    return Vector(A.x+B.x, A.y+B.y);
}
Vector operator - (Vector A, Vector B)
{
    return Vector(A.x-B.x, A.y-B.y);
}
db Cross(Vector A, Vector B)
{
    return A.x*B.y - A.y*B.x;
}
db Area2(Point A, Point B, Point C)
{
    return Cross(B-A, C-A);
}
db PolygonArea(Point *p, ll n)
{
    db area = 0.0;
    for(ll i = 1; i < n-1; i++)
    area += Cross(p[i]-p[0], p[i+1]-p[0]);
    return fabs(area/2.0);
}
ll gcd(ll a,ll b)
{
    if((a%b)==0) return b;
    else return gcd(b,a%b);
}
db find()
{
    db b=0;
    for(ll i=0;i<n;i++)
    {
        ll dx=fabs(P[i].x-P[(i+1)%n].x);
        ll dy=fabs(P[i].y-P[(i+1)%n].y);
        if(dx>dy)swap(dx,dy);
        if(dx==0) b+=(db)dy;else if (dy==0) b+=(db)dx;else b+=(db)gcd(dx,dy);//注意实际的dxdy是可能等于0的
    }
    db S=fabs(PolygonArea(P,n));
    db ans=S+b/2.0+1;
    return ans;
}
int main()
{
    scanf("%lld",&n);
    db cnt1,cnt2,cnt3,cnt4;
    for(ll i=0;i<n;i++) scanf("%Lf%Lf",&P[i].x,&P[i].y);
    cnt1=find();
    for(ll i=0;i<n;i++) P[i].x*=2;
    cnt2=find();
    for(ll i=0;i<n;i++) P[i].y*=2;
    cnt4=find();
    for(ll i=0;i<n;i++) P[i].x/=2;
    cnt3=find();
    //printf("%Lf %Lf %Lf %Lf\n",cnt1,cnt2,cnt3,cnt4);
    printf("%.0Lf\n",cnt4-cnt3-cnt2+cnt1);
    return 0;
}

