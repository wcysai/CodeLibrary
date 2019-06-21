#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int fact[MAXN],invf[MAXN],dp[MAXN],ans[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
class HomeAwayLeague {
	public:
	int matches(int x) {
		fact[0]=invf[0]=1;
        for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
        invf[1000000]=pow_mod(fact[1000000],MOD-2);
        for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
        dp[1]=0; dp[2]=1;
        for(int i=3;i<=1000000;i++) dp[i]=1LL*(dp[i-1]+dp[i-2])*(i-1)%MOD;
        int res=1LL*dp[x/2]*comb(x,x/2)%MOD*fact[x/2]%MOD;
        return res;
	}
};
// BEGIN CUT HERE
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
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
			int x                     = 5;
			int expected__            = 60;

			std::clock_t start__      = std::clock();
			int received__            = HomeAwayLeague().matches(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 8;
			int expected__            = 15120;

			std::clock_t start__      = std::clock();
			int received__            = HomeAwayLeague().matches(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 2: {
			int x                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HomeAwayLeague().matches(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 3: {
			int x                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HomeAwayLeague().matches(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int x                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HomeAwayLeague().matches(x);
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
