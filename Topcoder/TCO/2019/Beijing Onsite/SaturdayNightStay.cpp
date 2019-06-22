#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int whatday(int d,int m,int y)
{
    int ans;
    if(m==1||m==2)
        m+=12,y--;
    if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
        ans=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
    else
        ans=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return ans;
}
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int getday(int m,int d)
{
    int s=0;
    for(int i=0;i<m;i++) s+=days[i];
    return s+d;
}

class SaturdayNightStay {
	public:
	int countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth) {
		int st=getday(firstMonth,firstDay),ed=getday(lastMonth,lastDay);
        int anohi=whatday(firstDay,firstMonth,2019);
        int ans=0;
        for(int i=st;i<=ed;i++)
        {
            bool f=false;
            int hito=(anohi+1)%7;
            for(int j=i+1;j<=ed;j++)
            {
                if(hito==6) f=true;
                if(f) ans++;
                hito=(hito+1)%7;
            }
            anohi=(anohi)+1%7;
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
			int firstDay              = 15;
			int firstMonth            = 6;
			int lastDay               = 16;
			int lastMonth             = 6;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SaturdayNightStay().countOptions(firstDay, firstMonth, lastDay, lastMonth);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int firstDay              = 16;
			int firstMonth            = 6;
			int lastDay               = 22;
			int lastMonth             = 6;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = SaturdayNightStay().countOptions(firstDay, firstMonth, lastDay, lastMonth);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int firstDay              = 1;
			int firstMonth            = 1;
			int lastDay               = 31;
			int lastMonth             = 1;
			int expected__            = 382;

			std::clock_t start__      = std::clock();
			int received__            = SaturdayNightStay().countOptions(firstDay, firstMonth, lastDay, lastMonth);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int firstDay              = 7;
			int firstMonth            = 8;
			int lastDay               = 19;
			int lastMonth             = 10;
			int expected__            = 2485;

			std::clock_t start__      = std::clock();
			int received__            = SaturdayNightStay().countOptions(firstDay, firstMonth, lastDay, lastMonth);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int firstDay              = ;
			int firstMonth            = ;
			int lastDay               = ;
			int lastMonth             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SaturdayNightStay().countOptions(firstDay, firstMonth, lastDay, lastMonth);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int firstDay              = ;
			int firstMonth            = ;
			int lastDay               = ;
			int lastMonth             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SaturdayNightStay().countOptions(firstDay, firstMonth, lastDay, lastMonth);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int firstDay              = ;
			int firstMonth            = ;
			int lastDay               = ;
			int lastMonth             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SaturdayNightStay().countOptions(firstDay, firstMonth, lastDay, lastMonth);
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
