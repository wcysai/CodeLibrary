#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class IdenticalBags {
	public:
	long long makeBags(vector<long long> candy, long long bagSize) {
		ll l=0,r=INF+1;
        while(r-l>1)
        {
            ll mid=(l+r)/2,cnt=0;
            bool f=false;
            for(int i=0;i<(int)candy.size();i++)
            {
                cnt+=candy[i]/mid;
                if(cnt>=bagSize) {f=true; break;}
            }
            if(f) l=mid; else r=mid;
        }
        return l;
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
			long long candy[]         = {10, 11, 12};
			long long bagSize         = 3;
			long long expected__      = 10;

			std::clock_t start__      = std::clock();
			long long received__      = IdenticalBags().makeBags(vector<long long>(candy, candy + (sizeof candy / sizeof candy[0])), bagSize);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long candy[]         = {10, 11, 12, 1, 2, 3};
			long long bagSize         = 3;
			long long expected__      = 10;

			std::clock_t start__      = std::clock();
			long long received__      = IdenticalBags().makeBags(vector<long long>(candy, candy + (sizeof candy / sizeof candy[0])), bagSize);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long candy[]         = {100};
			long long bagSize         = 7;
			long long expected__      = 14;

			std::clock_t start__      = std::clock();
			long long received__      = IdenticalBags().makeBags(vector<long long>(candy, candy + (sizeof candy / sizeof candy[0])), bagSize);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long candy[]         = {10000000000LL, 20000000000LL, 30000000000LL};
			long long bagSize         = 6;
			long long expected__      = 10000000000LL;

			std::clock_t start__      = std::clock();
			long long received__      = IdenticalBags().makeBags(vector<long long>(candy, candy + (sizeof candy / sizeof candy[0])), bagSize);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long candy[]         = ;
			long long bagSize         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = IdenticalBags().makeBags(vector<long long>(candy, candy + (sizeof candy / sizeof candy[0])), bagSize);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long candy[]         = ;
			long long bagSize         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = IdenticalBags().makeBags(vector<long long>(candy, candy + (sizeof candy / sizeof candy[0])), bagSize);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long candy[]         = ;
			long long bagSize         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = IdenticalBags().makeBags(vector<long long>(candy, candy + (sizeof candy / sizeof candy[0])), bagSize);
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
