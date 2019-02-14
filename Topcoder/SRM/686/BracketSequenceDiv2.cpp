#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dp[MAXN][MAXN][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
class BracketSequenceDiv2 {
	public:
	int count(string s) 
    {
        int n=s.size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            int x=0;
            if(s[i-1]=='(') x=0; else x=1;
            for(int j=0;j<=i;j++)
            {
                if(x==0)
                {
                    add(dp[i][j][1],dp[i-1][j][1]);
                    if(j>0) add(dp[i][j][0],dp[i-1][j-1][0]);
                    if(j>0) add(dp[i][j][0],dp[i-1][j-1][1]);
                    if(j==1) add(dp[i][j][0],1);
                }
                else
                {
                    add(dp[i][j][0],dp[i-1][j][0]);
                    add(dp[i][j][1],dp[i-1][j+1][0]);
                    add(dp[i][j][1],dp[i-1][j+1][1]);
                }
            }
        }
        int ans=0;
        add(ans,dp[n][0][0]); add(ans,dp[n][0][1]);
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
			string s                  = "(())(";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "())";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = ")(((";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "()()()()()()()()(())))(()()()()))())";
			int expected__            = 364675;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()";
			int expected__            = 122826009;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BracketSequenceDiv2().count(s);
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
