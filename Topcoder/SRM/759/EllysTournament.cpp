#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class EllysTournament {
	public:
	double getChance(int N, int K, vector <int> ratings) {
		
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
			int N                     = 4;
			int K                     = 2;
			int ratings[]             = {2103, 2019, 1911, 2331};
			double expected__         = 0.17753927527829697;

			std::clock_t start__      = std::clock();
			double received__         = EllysTournament().getChance(N, K, vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 12;
			int K                     = 6;
			int ratings[]             = {42, 88, 13, 11, 71, 55, 32, 13, 72, 53, 37, 50};
			double expected__         = 0.06697114679670368;

			std::clock_t start__      = std::clock();
			double received__         = EllysTournament().getChance(N, K, vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 20;
			int K                     = 13;
			int ratings[]             = {1543, 1230, 421, 1415, 1271, 1962, 2677, 2373, 2951, 114, 1379, 2015, 2211, 955, 2066, 2573, 2982, 296, 1730, 1591};
			double expected__         = 0.05017297846158086;

			std::clock_t start__      = std::clock();
			double received__         = EllysTournament().getChance(N, K, vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 100;
			int K                     = 42;
			int ratings[]             = {2750, 2877, 2224, 186, 1398, 1084, 1542, 2770, 2288, 1078, 373, 2417, 476, 2968, 564, 1565, 1740, 1377, 2633, 287, 111, 823, 578, 520, 1708, 174, 144, 1295, 694, 678, 227, 2588, 371, 2740, 211, 1798, 82, 2385, 2979, 389, 2031, 1667, 2541, 2561, 1471, 2562, 974, 577, 286, 2836, 120, 2290, 185, 554, 2549, 1410, 1814, 1508, 2559, 1806, 2215, 1606, 2637, 1394, 1583, 1491, 2908, 529, 2556, 1034, 2770, 750, 2866, 2590, 1156, 2646, 2536, 958, 2862, 2565, 1027, 2744, 1160, 276, 2080, 322, 92, 790, 2452, 1859, 602, 2935, 2392, 1076, 2991, 1158, 2721, 868, 112, 29};
			double expected__         = 0.003026484586204139;

			std::clock_t start__      = std::clock();
			double received__         = EllysTournament().getChance(N, K, vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int K                     = ;
			int ratings[]             = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = EllysTournament().getChance(N, K, vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int K                     = ;
			int ratings[]             = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = EllysTournament().getChance(N, K, vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int ratings[]             = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = EllysTournament().getChance(N, K, vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
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
