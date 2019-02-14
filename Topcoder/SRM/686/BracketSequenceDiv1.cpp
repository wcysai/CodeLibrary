#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 45
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(ll &a,ll b) {a+=b;}
class BracketSequenceDiv1 {
	public:
    ll dp[MAXN][MAXN];
    string str;
    ll solve(ll l,ll r)
    {
        if(l>=r) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        ll &ans=dp[l][r];
        ans=solve(l+1,r);
        for(ll i=l+1;i<=r;i++) if((str[l]=='('&&str[i]==')')||(str[l]=='['&&str[i]==']')) add(ans,solve(l+1,i-1)*solve(i+1,r));
        return ans;
    }
	long long count(string s) 
    {
        str=s;
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1)-1;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			string s                  = "()[]";
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "())";
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "()()";
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "([)]";
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "())[]][]([]()]]()]]]";
			long long expected__      = 3854;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string s                  = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s                  = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BracketSequenceDiv1().count(s);
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
