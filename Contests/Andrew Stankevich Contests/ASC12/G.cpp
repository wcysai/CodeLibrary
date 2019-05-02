#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,c;
const db eps=1e-8;
struct Point
{
    db x,y;
    Point(){}
    Point(db tx,db ty) {x=tx; y=ty;}
};
struct Line
{
    Point s,e;
    db a,b,c;
    Line(){}
    Line(Point ts,Point te):s(ts),e(te){}
    bool pton()
    {
        a=e.y-s.y;
        b=s.x-e.x;
        c=e.x*s.y-e.y*s.x;
        return true;
    }
    db dis(const Point &_Off)
    {
        pton();
        db td=(a*_Off.x+b*_Off.y+c)/sqrt(a*a+b*b);
        return fabs(td);
    }
}l1,l2;
vector<pair<db,int> > v;
int choice[MAXN];
int off;
int main()
{
    freopen("pipe.in","r",stdin);
    freopen("pipe.out","w",stdout);
    scanf("%d%d",&n,&c);
    scanf("%Lf%Lf%Lf%Lf",&l1.s.x,&l1.s.y,&l1.e.x,&l1.e.y);
    scanf("%Lf%Lf%Lf%Lf",&l2.s.x,&l2.s.y,&l2.e.x,&l2.e.y);
    Line l;
    db res=0;
    for(int i=1;i<=n;i++)
    {
        db demand;
        Point p;
        scanf("%Lf%Lf%Lf",&p.x,&p.y,&demand);
        db dis1=l1.dis(p),dis2=l2.dis(p);
        res+=dis1;
        v.push_back(make_pair((dis2-dis1)*demand,i));
    }
    sort(v.begin(),v.end());
    db ans=INF;
    int id=0;
    db sum=0;
    for(int i=0;i<=n;i++)
    {
        if(max(i-(n-i),(n-i)-i)<=c&&sum+eps<ans)
        {
            ans=sum;
            id=i;
        }
        sum+=v[i].F;
    }
    for(int i=1;i<=n;i++) choice[i]=1;
    for(int i=0;i<id;i++) choice[v[i].S]=2;
    for(int i=1;i<=n;i++) printf("%d ",choice[i]);
    return 0;

}

