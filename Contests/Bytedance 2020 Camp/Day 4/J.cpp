#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck0
#define y0 fuck1
#define x1 fuck2
#define y1 fuck3
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
const ld eps=1e-10,PI=acos(-1);
int sign(ld x){return x<-eps?-1:x>eps;}
struct Point {ld x,y; 
    Point turn90(){return (Point){-y,x};}
    int quad() const { return sign(y)==1||(sign(y)==0&&sign(x)>=0);} 
    Point operator-(const Point p)const{return (Point){x-p.x,y-p.y};}
    Point operator+(const Point p)const{return (Point){x+p.x,y+p.y};}
    Point operator*(ld c)const{return (Point){x*c,y*c};}
    Point operator/(ld c)const{return (Point){x/c,y/c};}
};
ld det(const Point u,const Point v){return u.x*v.y-u.y*v.x;}
ld dot(const Point u,const Point v){return u.x*v.x+u.y*v.y;}
struct Line {
    Point a,b;
  bool include(const Point &p) const { return sign(det(b - a, p - a)) > 0; }
  /*
  Line push() const{ // 将半平面向外推 eps
    const double eps = 1e-6;
    Point delta = (b - a).turn90().norm() * eps;
    return Line(a - delta, b - delta);
  }
  */
};
Point intersect(const Line &l1, const Line &l2) {
  double s1 = det(l2.b - l2.a, l1.a - l2.a),
       s2 = -det(l2.b - l2.a, l1.b - l2.a);
  return (l1.a * s2 + l1.b * s1) / (s1 + s2);
}
bool parallel(const Line &l1, const Line &l2){
    return sign(det(l1.b-l1.a,l2.b-l2.a))==0;
}
bool sameDir(const Line &l0, const Line &l1) { return parallel(l0, l1) && sign(dot(l0.b - l0.a, l1.b - l1.a)) == 1; }
bool operator < (const Point &a, const Point &b) {
  if (a.quad() != b.quad()) return a.quad() < b.quad();
  else return sign(det(a, b)) > 0; 
}
bool operator < (const Line &l0, const Line &l1) {
  if (sameDir(l0, l1))return l1.include(l0.a);
  else return (l0.b - l0.a) < (l1.b - l1.a);
}
bool check(const Line &u, const Line &v, const Line &w) { return w.include(intersect(u, v)); }
vector<Point> intersection(vector<Line> &l) {
  sort(l.begin(), l.end());
  deque<Line> q;
  for (int i = 0; i < (int)l.size(); ++i) {
    if (i && sameDir(l[i], l[i - 1]))continue;
    while (q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
    while (q.size() > 1 && !check(q[1], q[0], l[i])) q.pop_front();
    q.push_back(l[i]);
  }
  while (q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
  while (q.size() > 2 && !check(q[1], q[0], q[q.size() - 1])) q.pop_front();
  vector<Point> ret;
  for (int i = 0; i < (int)q.size(); ++i) ret.push_back(intersect(q[i], q[(i + 1) % q.size()]));
  return ret;
}
Point midpoint(vector<Line> &l){
    vector<Point>vec=intersection(l);
    Point ret=(Point){0.L,0.L};
    for(Point p:vec)ret=ret+p;//,printf("%Lf %Lf\n",p.x,p.y);
    ret=ret/vec.size();
    return ret;
}
ld W,H,E;
vector<Line>vec;
const int A=40,B=5;
int main(){
    //srand(time(0));
    scanf("%Lf%Lf%Lf",&W,&H,&E);
    //int X=rand()%(2*W+1)-W,Y=rand()%(2*H+1)-H;

    vec.pb((Line){(Point){-1.L*W,-1.L*H},(Point){1.L*W,-1.L*H}});
    vec.pb((Line){(Point){1.L*W,-1.L*H},(Point){1.L*W,1.L*H}});
    vec.pb((Line){(Point){1.L*W,1.L*H},(Point){-1.L*W,1.L*H}});
    vec.pb((Line){(Point){-1.L*W,1.L*H},(Point){-1.L*W,-1.L*H}});
    rep(i,A){
        Point p=midpoint(vec);
        ld avg=0;
        rep(j,B){
            printf("? %.9Lf %.9Lf\n",p.x,p.y);
            fflush(stdout);
            ld the;
            scanf("%Lf",&the);
            //the=atan2(Y-p.y,X-p.x)/PI*180;
            //the+=rand()%(2*E+1)-E;
            //printf("%.15Lf\n",the);
            avg+=the;
        }
        avg/=B;
        //while(avg<-180)avg+=360;
        //while(avg>180)avg-=360;
        Point u=(Point){cos(avg/180*PI),sin(avg/180*PI)};
        Point v=(Point){-u.y,u.x};
        vec.pb((Line){p+v,p-v});
    }
    Point p=midpoint(vec);
    printf("! %.9Lf %.9Lf\n",p.x,p.y);
    fflush(stdout);
    //printf("%d %d\n",X,Y);
    return 0;
}