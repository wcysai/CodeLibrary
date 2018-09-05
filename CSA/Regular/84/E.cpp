/*************************************************************************
    > File Name: 84E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-18 23:01:18
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
const ll inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
inline bool rd(T &ret) {
	char c; ll sgn;
	if (c = getchar(), c == EOF) return 0;
	while (c != '-' && (c<'0' || c>'9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
}
template <class T>
inline void pt(T x) {
	if (x <0) { putchar('-'); x = -x; }
	if (x>9) pt(x / 10);
	putchar(x % 10 + '0');
}
using namespace std;
const ll N = 3e5 + 10;
typedef long long ll;
class MST{
	struct Edge{
		ll from, to, dis;
		Edge(ll _from = 0, ll _to = 0, ll _dis = 0) :from(_from), to(_to), dis(_dis){}
		bool operator < (const Edge &x) const{return dis < x.dis;}
	}edge[N << 3];
	ll f[N], sz[N], tot;
	ll find(ll x){ return x == f[x] ? x : f[x] = find(f[x]); }
    bool same(ll x,ll y)
    {
        x=find(x);y=find(y);
        if(x==y) return true; else return false;
    }
	void Union(ll x, ll y)
    {
        x=find(x);y=find(y);
        if(x>y) swap(x,y);
		f[x] = y;
        sz[y]+=sz[x];
	}
public:
	void init(ll n){
		for (ll i = 0; i <= n; i++)f[i] = i,sz[i]=1;
		tot = 0;
	}
	void add(ll u, ll v, ll dis){
		edge[tot++] = Edge(u, v, dis);
	}
	ll work()
    {
		sort(edge, edge + tot);
		ll cost = 0;
		for (ll i = 0; i < tot; i++)
			if (!same(edge[i].from, edge[i].to))
            {
                //printf("%lld\n",edge[i].dis);
				cost += edge[i].dis/2*sz[find(edge[i].from)]*sz[find(edge[i].to)];
                //printf("%lld\n",cost);
                Union(edge[i].from,edge[i].to);
            }
        return cost;
	}
}mst;
struct Point{//二维平面的点
	ll x, y, id;
	bool operator < (const Point&a) const{
		return x == a.x ? y < a.y : x < a.x;
	}
}p[N];
class BIT{//树状数组
	ll c[N], id[N], maxn;
	ll lowbit(ll x){ return x&-x; }
public:
	void init(ll n){
		maxn = n + 10;
		fill(c, c + maxn + 1, inf);
		fill(id, id + maxn + 1, -1);
	}
	void updata(ll x, ll val, ll _id){
		while (x){
			if (val < c[x]){ c[x] = val; id[x] = _id; }
			x -= lowbit(x);
		}
	}
	ll query(ll x){
		ll val = inf, _id = -1;
		while (x <= maxn){
			if (val > c[x]){ val = c[x]; _id = id[x]; }
			x += lowbit(x);
		}
		return _id;
	}
}tree;
inline bool cmp(ll *x, ll *y){ return *x < *y; }
class Manhattan_MST{//复杂度O(max(N*1.5,Nlog(N)))
	ll A[N], B[N];
public:
	ll work(ll l, ll r){
		mst.init(r);
		for (ll dir = 1; dir <= 4; dir++){
			if (dir%2==0)for (ll i = l; i <= r; i++)swap(p[i].x, p[i].y);
			else if (dir == 3)for (ll i = l; i <= r; i++)p[i].y = -p[i].y;
			sort(p + l, p + r + 1);
			for (ll i = l; i <= r; i++) A[i] = B[i] = p[i].y - p[i].x; //离散化
			sort(B + 1, B + N + 1);
			ll sz = unique(B + 1, B + N + 1) - B - 1;
			//初始化反树状数组
			tree.init(sz);
			for (ll i = r; i >= l; i--)
			{
				ll pos = lower_bound(B + 1, B + sz + 1, A[i]) - B;
				ll id = tree.query(pos);
				if (id != -1)
					mst.add(p[i].id, p[id].id, abs(p[i].x - p[id].x) + abs(p[i].y - p[id].y));
				tree.updata(pos, p[i].x + p[i].y, i);
			}
		}for (ll i = l; i <= r; i++)p[i].y = -p[i].y;
		return mst.work();
	}
}m_mst;
 
ll n;
int main(){
	scanf("%lld",&n);
    for (ll i = 1; i <= n; i++)rd(p[i].x), rd(p[i].y), p[i].id = i;
	cout << m_mst.work(1, n) << endl;
	return 0;
}
