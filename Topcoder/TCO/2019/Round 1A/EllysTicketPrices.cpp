#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int base = 1000000000;
const int base_digits = 9; 
struct bigint {
    vector<int> a;
    int sign;
    /*<arpa>*/
    int size(){
	if(a.empty())return 0;
	int ans=(a.size()-1)*base_digits;
	int ca=a.back();
	while(ca)
	    ans++,ca/=10;
	return ans;
    }
    bigint operator ^(const bigint &v){
	bigint ans=1,a=*this,b=v;
	while(!b.isZero()){
	    if(b%2)
		ans*=a;
	    a*=a,b/=2;
	}
	return ans;
    }
    string to_string(){
	stringstream ss;
	ss << *this;
	string s;
	ss >> s;
	return s;
    }
    int sumof(){
	string s = to_string();
	int ans = 0;
	for(auto c : s)  ans += c - '0';
	return ans;
    }
    /*</arpa>*/
    bigint() :
	sign(1) {
    }
 
    bigint(long long v) {
	*this = v;
    }
 
    bigint(const string &s) {
	read(s);
    }
 
    void operator=(const bigint &v) {
	sign = v.sign;
	a = v.a;
    }
 
    void operator=(long long v) {
	sign = 1;
	a.clear();
	if (v < 0)
	    sign = -1, v = -v;
	for (; v > 0; v = v / base)
	    a.push_back(v % base);
    }
 
    bigint operator+(const bigint &v) const {
	if (sign == v.sign) {
	    bigint res = v;
 
	    for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
		if (i == (int) res.a.size())
		    res.a.push_back(0);
		res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
		carry = res.a[i] >= base;
		if (carry)
		    res.a[i] -= base;
	    }
	    return res;
	}
	return *this - (-v);
    }
 
    bigint operator-(const bigint &v) const {
	if (sign == v.sign) {
	    if (abs() >= v.abs()) {
		bigint res = *this;
		for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
		    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
		    carry = res.a[i] < 0;
		    if (carry)
			res.a[i] += base;
		}
		res.trim();
		return res;
	    }
	    return -(v - *this);
	}
	return *this + (-v);
    }
 
    void operator*=(int v) {
	if (v < 0)
	    sign = -sign, v = -v;
	for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
	    if (i == (int) a.size())
		a.push_back(0);
	    long long cur = a[i] * (long long) v + carry;
	    carry = (int) (cur / base);
	    a[i] = (int) (cur % base);
	    //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
	}
	trim();
    }
 
    bigint operator*(int v) const {
	bigint res = *this;
	res *= v;
	return res;
    }
 
    void operator*=(long long v) {
	if (v < 0)
	    sign = -sign, v = -v;
	for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
	    if (i == (int) a.size())
		a.push_back(0);
	    long long cur = a[i] * (long long) v + carry;
	    carry = (int) (cur / base);
	    a[i] = (int) (cur % base);
	    //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
	}
	trim();
    }
 
    bigint operator*(long long v) const {
	bigint res = *this;
	res *= v;
	return res;
    }
 
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
	int norm = base / (b1.a.back() + 1);
	bigint a = a1.abs() * norm;
	bigint b = b1.abs() * norm;
	bigint q, r;
	q.a.resize(a.a.size());
 
	for (int i = a.a.size() - 1; i >= 0; i--) {
	    r *= base;
	    r += a.a[i];
	    int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
	    int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
	    int d = ((long long) base * s1 + s2) / b.a.back();
	    r -= b * d;
	    while (r < 0)
		r += b, --d;
	    q.a[i] = d;
	}
 
	q.sign = a1.sign * b1.sign;
	r.sign = a1.sign;
	q.trim();
	r.trim();
	return make_pair(q, r / norm);
    }
 
    bigint operator/(const bigint &v) const {
	return divmod(*this, v).first;
    }
 
    bigint operator%(const bigint &v) const {
	return divmod(*this, v).second;
    }
 
    void operator/=(int v) {
	if (v < 0)
	    sign = -sign, v = -v;
	for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
	    long long cur = a[i] + rem * (long long) base;
	    a[i] = (int) (cur / v);
	    rem = (int) (cur % v);
	}
	trim();
    }
 
    bigint operator/(int v) const {
	bigint res = *this;
	res /= v;
	return res;
    }
 
    int operator%(int v) const {
	if (v < 0)
	    v = -v;
	int m = 0;
	for (int i = a.size() - 1; i >= 0; --i)
	    m = (a[i] + m * (long long) base) % v;
	return m * sign;
    }
 
    void operator+=(const bigint &v) {
	*this = *this + v;
    }
    void operator-=(const bigint &v) {
	*this = *this - v;
    }
    void operator*=(const bigint &v) {
	*this = *this * v;
    }
    void operator/=(const bigint &v) {
	*this = *this / v;
    }
 
    bool operator<(const bigint &v) const {
	if (sign != v.sign)
	    return sign < v.sign;
	if (a.size() != v.a.size())
	    return a.size() * sign < v.a.size() * v.sign;
	for (int i = a.size() - 1; i >= 0; i--)
	    if (a[i] != v.a[i])
		return a[i] * sign < v.a[i] * sign;
	return false;
    }
 
    bool operator>(const bigint &v) const {
	return v < *this;
    }
    bool operator<=(const bigint &v) const {
	return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
	return !(*this < v);
    }
    bool operator==(const bigint &v) const {
	return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
	return *this < v || v < *this;
    }
 
    void trim() {
	while (!a.empty() && !a.back())
	    a.pop_back();
	if (a.empty())
	    sign = 1;
    }
 
    bool isZero() const {
	return a.empty() || (a.size() == 1 && !a[0]);
    }
 
    bigint operator-() const {
	bigint res = *this;
	res.sign = -sign;
	return res;
    }
 
    bigint abs() const {
	bigint res = *this;
	res.sign *= res.sign;
	return res;
    }
 
    long long longValue() const {
	long long res = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	    res = res * base + a[i];
	return res * sign;
    }
 
    friend bigint gcd(const bigint &a, const bigint &b) {
	return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
	return a / gcd(a, b) * b;
    }
 
    void read(const string &s) {
	sign = 1;
	a.clear();
	int pos = 0;
	while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
	    if (s[pos] == '-')
		sign = -sign;
	    ++pos;
	}
	for (int i = s.size() - 1; i >= pos; i -= base_digits) {
	    int x = 0;
	    for (int j = max(pos, i - base_digits + 1); j <= i; j++)
		x = x * 10 + s[j] - '0';
	    a.push_back(x);
	}
	trim();
    }
 
    friend istream& operator>>(istream &stream, bigint &v) {
	string s;
	stream >> s;
	v.read(s);
	return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const bigint &v) {
	if (v.sign == -1)
	    stream << '-';
	stream << (v.a.empty() ? 0 : v.a.back());
	for (int i = (int) v.a.size() - 2; i >= 0; --i)
	    stream << setw(base_digits) << setfill('0') << v.a[i];
	return stream;
    }
 
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
	vector<long long> p(max(old_digits, new_digits) + 1);
	p[0] = 1;
	for (int i = 1; i < (int) p.size(); i++)
	    p[i] = p[i - 1] * 10;
	vector<int> res;
	long long cur = 0;
	int cur_digits = 0;
	for (int i = 0; i < (int) a.size(); i++) {
	    cur += a[i] * p[cur_digits];
	    cur_digits += old_digits;
	    while (cur_digits >= new_digits) {
		res.push_back(int(cur % p[new_digits]));
		cur /= p[new_digits];
		cur_digits -= new_digits;
	    }
	}
	res.push_back((int) cur);
	while (!res.empty() && !res.back())
	    res.pop_back();
	return res;
    }
 
    typedef vector<long long> vll;
 
    static vll karatsubaMultiply(const vll &a, const vll &b) {
	int n = a.size();
	vll res(n + n);
	if (n <= 32) {
	    for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		    res[i + j] += a[i] * b[j];
	    return res;
	}
 
	int k = n >> 1;
	vll a1(a.begin(), a.begin() + k);
	vll a2(a.begin() + k, a.end());
	vll b1(b.begin(), b.begin() + k);
	vll b2(b.begin() + k, b.end());
 
	vll a1b1 = karatsubaMultiply(a1, b1);
	vll a2b2 = karatsubaMultiply(a2, b2);
 
	for (int i = 0; i < k; i++)
	    a2[i] += a1[i];
	for (int i = 0; i < k; i++)
	    b2[i] += b1[i];
 
	vll r = karatsubaMultiply(a2, b2);
	for (int i = 0; i < (int) a1b1.size(); i++)
	    r[i] -= a1b1[i];
	for (int i = 0; i < (int) a2b2.size(); i++)
	    r[i] -= a2b2[i];
 
	for (int i = 0; i < (int) r.size(); i++)
	    res[i + k] += r[i];
	for (int i = 0; i < (int) a1b1.size(); i++)
	    res[i] += a1b1[i];
	for (int i = 0; i < (int) a2b2.size(); i++)
	    res[i + n] += a2b2[i];
	return res;
    }
 
    bigint operator*(const bigint &v) const {
	vector<int> a6 = convert_base(this->a, base_digits, 6);
	vector<int> b6 = convert_base(v.a, base_digits, 6);
	vll a(a6.begin(), a6.end());
	vll b(b6.begin(), b6.end());
	while (a.size() < b.size())
	    a.push_back(0);
	while (b.size() < a.size())
	    b.push_back(0);
	while (a.size() & (a.size() - 1))
	    a.push_back(0), b.push_back(0);
	vll c = karatsubaMultiply(a, b);
	bigint res;
	res.sign = sign * v.sign;
	for (int i = 0, carry = 0; i < (int) c.size(); i++) {
	    long long cur = c[i] + carry;
	    res.a.push_back((int) (cur % 1000000));
	    carry = (int) (cur / 1000000);
	}
	res.a = convert_base(res.a, 6, base_digits);
	res.trim();
	return res;
    }
};
class EllysTicketPrices {
	public:
    int N;
    bool check(int x,int &N,vector<int> &C,int &target)
    {
        bigint tg=target; tg=tg*100;
        bigint res=x;
        bigint num=1;
        bigint sum=x;
        for(int i=0;i<N-1;i++)
        {
            res=res*(100+C[i]);
            num=num*100;
            bigint tmp=res/(num);
            int cat=(res/(num/10))%10;
            if(cat>=5) res=(tmp+1)*num; else res=tmp*num;
            sum=sum*100+res;
        }
        bigint ans=sum/N;
        bigint tmp=ans/(num);
        int cat=(ans/(num/10))%10;
        if(cat>=5) ans=(tmp+1)*num; else ans=tmp*num;
        return ans<=tg*num;
    }
	double getPrice(int N, vector <int> C, int target) 
    {
	    int l=1,r=100000000;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid,N,C,target)) l=mid; else r=mid;
        }
        return (double)l/100.0;
	}
};
// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 5;
			int C[]                   = {-10, 15, 5, -20};
			int target                = 180;
			double expected__         = 184.01;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 11;
			int C[]                   = {5, 16, 17, -3, -10, 20, 20, 14, 2, 0};
			int target                = 1337;
			double expected__         = 874.77;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int C[]                   = {0};
			int target                = 42;
			double expected__         = 42.0;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 20;
			int C[]                   = {30, -26, 87, 47, -39, 25, -67, 62, -38, 68, -84, 5, 28, -20, 50, -61, 10, 63, -71};
			int target                = 392;
			double expected__         = 476.28;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 50;
			int C[]                   = {-60, 61, 17, 86, 56, 27, 9, 41, -27, -36, 57, -16, 1, 50, -55, -36, 14, 13, -93, 14, 18, 25, 62, -18, 40, 79, 56, 19, 10, -55, -43, 45, -43, -84, 61, -64, 41, -55, 38, 18, 36, -43, 79, 33, 87, 19, -47, 38, -56};
			int target                = 8887;
			double expected__         = 9451.93;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int C[]                   = ;
			int target                = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int C[]                   = ;
			int target                = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int C[]                   = ;
			int target                = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = EllysTicketPrices().getPrice(N, vector <int>(C, C + (sizeof C / sizeof C[0])), target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
