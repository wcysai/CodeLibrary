#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,q,a[MAXN];
constexpr int lc(int o) { return o << 1; }
constexpr int rc(int o) { return o << 1 | 1; }
struct bigint_t {
	int n, BASE;
	vector<int> allzero, allfull, a, tag;
	bool in_range(int x) {
		return 0 <= x && x < BASE;
	}
	void assign(int o, int v) {
		a[o] = v;
		tag[o] = v;
		allzero[o] = (v == 0);
		allfull[o] = (v == BASE - 1);
	}
	void add(int o, int v) {
		a[o] += v;
		allzero[o] = (a[o] == 0);
		allfull[o] = (a[o] == BASE - 1);
	}
	void push_up(int o) {
		allzero[o] = allzero[lc(o)] && allzero[rc(o)];
		allfull[o] = allfull[lc(o)] && allfull[rc(o)];
	}
	void push_down(int o) {
		if (tag[o] != -1) {
			assign(lc(o), tag[o]);
			assign(rc(o), tag[o]);
			tag[o] = -1;
		}
	}
	void build(int o, int l, int r) {
		if (l == r) {
			assign(o, 0);
		}
		else {
			const int mid = l + r >> 1;
			build(lc(o), l, mid);
			build(rc(o), mid + 1, r);
			push_up(o);
		}
	}
	bigint_t(int n, int BASE) : n(n), BASE(BASE) {
		allzero = vector<int>(4 * (n + 2), 0);
		allfull = vector<int>(4 * (n + 2), 0);
		tag = vector<int>(4 * (n + 2), -1);
		a = vector<int>(4 * (n + 2), 0);
		build(1, 1, n);
	}
	void fill(int o, int l, int r, int ql, int qr, int v) {
		if (ql <= l && r <= qr) {
			assign(o, v);
		}
		else {
			const int mid = l + r >> 1;
			push_down(o);
			if (ql <= mid) fill(lc(o), l, mid, ql, qr, v);
			if (qr > mid) fill(rc(o), mid + 1, r, ql, qr, v);
			push_up(o);
		}
	}
	void addbit(int o, int l, int r, int p, int v) {
		if (l == r) {
			add(o, v);
		}
		else {
			const int mid = l + r >> 1;
			push_down(o);
			if (p <= mid) addbit(lc(o), l, mid, p, v);
			else addbit(rc(o), mid + 1, r, p, v);
			push_up(o);
		}
	}
	int find_first(int o, int l, int r, int p, const auto &v) {
		if (v[o]) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		const int mid = l + r >> 1;
		push_down(o);
		if (p <= mid) {
			int t = find_first(lc(o), l, mid, p, v);
			if (t == -1)
				return find_first(rc(o), mid + 1, r, p, v);
			return t;
		}
		else {
			return find_first(rc(o), mid + 1, r, p, v);
		}
	}
	int highest_bit(int o, int l, int r) {
		if (allzero[o]) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		push_down(o);
		const int mid = l + r >> 1;
		int t = highest_bit(rc(o), mid + 1, r);
		if (t != -1) {
			return t;
		}
		return highest_bit(lc(o), l, mid);
	}
	int least_bit() {
		return find_first(1, 1, n, 0, allzero);
	}
	int highest_bit() {
		return highest_bit(1, 1, n);
	}
	int query(int o, int l, int r, int p) {
		if (l == r) {
			return a[o];
		}
		else {
			const int mid = l + r >> 1;
			push_down(o);
			if (p <= mid) return query(lc(o), l, mid, p);
			else return query(rc(o), mid + 1, r, p);
		}
	}
	void plus(int p, int v) {
		int q = find_first(1, 1, n, p, allfull);
		if (p <= q - 1) fill(1, 1, n, p, q - 1, 0);
		addbit(1, 1, n, q, v);
	}
	void minus(int p, int v) {
		int q = find_first(1, 1, n, p, allzero);
		if (p <= q - 1) fill(1, 1, n, p, q - 1, BASE - 1);
		addbit(1, 1, n, q, -v);
	}
	void print() {
		vector<int> ret(n);
		for (int i = 0; i < n; ++i) {
			ret[i] = query(1, 1, n, i+1);
		}
		for (int i = 0; i < n; ++i) {
			cerr << ret[i];
			if (i + 1 == n) cerr << "\n";
			else cerr << ", ";
		}
	}
};

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&q);
        bigint_t b(n+30,m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b.plus(a[i],1);
        }
        for(int i=0;i<q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            b.minus(a[x],1);
            a[x]=y;
            b.plus(a[x],1);
            int hb=b.highest_bit(),lb=b.least_bit();
            printf("%d\n",(hb==lb)?hb:hb+1);
        }
    }
    return 0;
}









