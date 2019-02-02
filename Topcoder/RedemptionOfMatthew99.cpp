#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class RedemptionOfMatthew99 {
	public:
	double bestTraversal(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2) {
		
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
			int X1[]                  = {0, 1};
			int Y1[]                  = {1, 1};
			int X2[]                  = {0, 1};
			int Y2[]                  = {-1, -1};
			double expected__         = 6.23606797749979;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X1[]                  = {0, 1, 2};
			int Y1[]                  = {2, 1, 2};
			int X2[]                  = {0, 1, 2};
			int Y2[]                  = {-2, -1, -2};
			double expected__         = 16.32455532033676;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X1[]                  = {-2, 2};
			int Y1[]                  = {1, 5};
			int X2[]                  = {-2, 2};
			int Y2[]                  = {-1, -4};
			double expected__         = 15.614226788360828;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X1[]                  = {-2, 1, 2};
			int Y1[]                  = {1, 2, 6};
			int X2[]                  = {-3, -2, -1};
			int Y2[]                  = {-1, -1, -2};
			double expected__         = -1.0;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int X1[]                  = {331, 667, 2926, 3285};
			int Y1[]                  = {536, 375, 375, 596};
			int X2[]                  = {760, 1291, 2251, 2939};
			int Y2[]                  = {-615, -428, -428, -636};
			double expected__         = 8698.860039486546;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int X1[]                  = ;
			int Y1[]                  = ;
			int X2[]                  = ;
			int Y2[]                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X1[]                  = ;
			int Y1[]                  = ;
			int X2[]                  = ;
			int Y2[]                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int X1[]                  = ;
			int Y1[]                  = ;
			int X2[]                  = ;
			int Y2[]                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RedemptionOfMatthew99().bestTraversal(vector <int>(X1, X1 + (sizeof X1 / sizeof X1[0])), vector <int>(Y1, Y1 + (sizeof Y1 / sizeof Y1[0])), vector <int>(X2, X2 + (sizeof X2 / sizeof X2[0])), vector <int>(Y2, Y2 + (sizeof Y2 / sizeof Y2[0])));
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
