/*************************************************************************

    > File Name: 258.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-03 21:12:47
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 100005
#define INF 1000000000
#define MOD 20092010
#define LOG 61
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

struct LinearRec {

	ll n;
	vector<ll> first, trans;
	vector<vector<ll> > bin;

	vector<ll> add(vector<ll> &a, vector<ll> &b) {
		vector<ll> result(n * 2 + 1, 0);
		//You can apply constant optimization here to get a ~10x speedup
		for (ll i = 0; i <= n; ++i) {
			for (ll j = 0; j <= n; ++j) {
				if ((result[i + j] += (long long)a[i] * b[j] % MOD) >= MOD) {
					result[i + j] -= MOD;
				}
			}
		}
		for (ll i = 2 * n; i > n; --i) {
			for (ll j = 0; j < n; ++j) {
				if ((result[i - 1 - j] += (long long)result[i] * trans[j] % MOD) >= MOD) {
					result[i - 1 - j] -= MOD;
				}
			}
			result[i] = 0;
		}
		result.erase(result.begin() + n + 1, result.end());
		return result;
	}

	LinearRec(vector<ll> &first, vector<ll> &trans):first(first), trans(trans) {
		n = first.size();
		vector<ll> a(n + 1, 0);
		a[1] = 1;
		bin.push_back(a);
		for (ll i = 1; i < LOG; ++i) {
			bin.push_back(add(bin[i - 1], bin[i - 1]));
		}
	}

	ll calc(ll k) {
		vector<ll> a(n + 1, 0);
		a[0] = 1;
		for (ll i = 0; i < LOG; ++i) {
			if (k >> i & 1) {
				a = add(a, bin[i]);
			}
		}
		ll ret = 0;
		for (ll i = 0; i < n; ++i) {
			if ((ret += (long long)a[i + 1] * first[i] % MOD) >= MOD) {
				ret -= MOD;
			}
		}
		return ret;
	}
};
int main()
{
    ll n=2000;
    vector<ll> a(2000,1);
    vector<ll> b(2000);
    b[1999]=b[1998]=1;
    LinearRec f(a,b);
    printf("%lld\n",f.calc(1000000000000000001LL));
    return 0;
}

