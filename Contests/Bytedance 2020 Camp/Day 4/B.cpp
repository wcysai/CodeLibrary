#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(long long i=1;i<=n;++i)
#define bit(i) __builtin_popcountll(i)
#define LL long long
#define inf 998244353
#define F first
#define S second
#define N 500
#define maxn 500
using namespace std;

struct Poi
{
    long double x,y;
    int id;
    friend bool operator <(Poi a,Poi b)
    {
        return mp(a.x,a.y)<mp(b.x,b.y);
    }
};
long double cross(Poi x,Poi y,Poi z)
{
    return (y.x-x.x)*(z.y-x.y)-(y.y-x.y)*(z.x-x.x);
}
vector<Poi> convexHull(vector<Poi> ps) { 
  int n = ps.size(); if (n <= 1) return ps;
  sort(ps.begin(), ps.end());
  vector<Poi> qs;
  for (int i = 0; i < n; qs.push_back(ps[i++])) 
    while (qs.size() > 1 && cross(qs[qs.size()-2],qs.back(),ps[i]) <= 0) qs.pop_back();
  for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])) 
    while ((int)qs.size() > t && cross(qs[(int)qs.size()-2],qs.back(),ps[i]) <= 0) qs.pop_back();
  qs.pop_back(); return qs;
}
 
long double area(Poi x,Poi y,Poi z)
{
    return abs(cross(x,y,z))/(long double)(2.);
}
long double w,h;
int n;
struct node
{
    long double x,y,vx,vy;
    long double stop;
    void read()
    {
        scanf("%Lf%Lf%Lf%Lf",&x,&y,&vx,&vy);
    }
    void calcstop()
    {
        long double l=0,r=1e18;
        for(int ti=0;ti<200;ti++)
        {
            long double mid=(l+r)/2;
            long double tx=x+vx*mid;
            long double ty=y+vy*mid;
            if (tx<0 || ty<0 || tx>w || ty>h)r=mid;
            else l=mid;
        }
        stop=l;
    }
}a[100];
long double calc(long double ti)
{
    vector<Poi> q; q.clear();
    for(int i=1;i<=n;i++)
        if (ti>=a[i].stop)
            q.pb((Poi){a[i].x+a[i].stop*a[i].vx,a[i].y+a[i].stop*a[i].vy,i});
        else
            q.pb((Poi){a[i].x+ti*a[i].vx,a[i].y+ti*a[i].vy,i});
    auto a=convexHull(q);
    if (a.size()<=2)return 0;
    long double ret=0;
    for(int i=1;i<a.size()-1;i++)
        ret+=area(a[0],a[i],a[i+1]);
    return ret;
}
vector<long double> event;
int main()
{
    cin>>n>>w>>h;
    for(int i=1;i<=n;i++){ a[i].read(); a[i].calcstop(); }
    event.clear();
    for(int i=1;i<=n;i++)event.pb(a[i].stop);
    event.pb(0);
    sort(event.begin(),event.end());
    long double ans=2147483647ll*10000000.,ansp=0;

    for(int i=0;i<event.size()-1;i++)
    {
        long double l=event[i]; 
        long double r=event[i+1];
        for(int i=0;i<200;i++)
        {
            long double lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
            if(calc(rb)<calc(lb)) l=lb; else r=rb;
        }
        long double ret=calc(l);
        if (ret<ans)ans=ret,ansp=l;
    }
    printf("%.11Lf\n%.11Lf\n",ansp,ans);
}