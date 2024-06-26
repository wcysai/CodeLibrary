#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class EllysAndXor {
	public:
	int getMax(vector <int> numbers) {
        int cnt=(int)numbers.size()-1;
        int ans=0;
		for(int mask=0;mask<(1<<cnt);mask++)
        {
            int cur=numbers[0];
            for(int i=0;i<cnt;i++)
            {
                if(mask&(1<<i)) cur=cur&(numbers[i+1]);
                else cur=cur^(numbers[i+1]);
            }
            ans=max(ans,cur);
        }
        return ans;

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
			int numbers[]             = {42, 27, 38};
			int expected__            = 44;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {666, 133, 438, 123, 893, 674, 462, 209};
			int expected__            = 976;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {42};
			int expected__            = 42;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {123, 456, 789, 987, 654, 321};
			int expected__            = 975;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numbers[]             = {42, 13, 17, 666, 811, 314, 1, 5, 2, 1000};
			int expected__            = 1007;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int numbers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numbers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int numbers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysAndXor().getMax(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
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
